#include "expression.h"
#include <iostream>
#include <stdexcept>

// for Binary sub-expression
Binary::Binary (Expression *value1, Expression *value2, std::string type): 
	value1{value1}, value2{value2}, type{type} {}

Binary::~Binary () {
	delete value1; 
	delete value2;
}

void Binary::prettyprint () {
	std::cout << "(";
        value1->prettyprint();
	std::cout << " " << type << " ";
       	value2->prettyprint();
	std::cout << ")";
}

void Binary::set (std::string var, float val) {
	value1->set(var, val);
	value2->set(var, val);
}

void Binary::unset (std::string var) {
	value1->unset(var);
	value2->unset(var);
}

float Binary::evaluate () {
	if (type == "+") return value1->evaluate() + value2->evaluate();
	else if (type == "-") return value1->evaluate() - value2->evaluate();
	else if (type == "*") return value1->evaluate() * value2->evaluate();
	else return value1->evaluate() / value2->evaluate();
}

// for unary sub-expression
Unary::Unary (Expression *value1, std::string type): 
	value1{value1}, type{type} {}

Unary::~Unary () {
	delete value1;
}

void Unary::prettyprint () {
	if (type == "abs") {
		std::cout << "|";
	       	value1->prettyprint();
		std::cout << "|";
	}
	else {
		std::cout << "-";
	       	value1->prettyprint();
	}
}

void Unary::set (std::string var, float val) {
	value1->set(var, val);
}

void Unary::unset (std::string var) {
	value1->unset(var);
}

float Unary::evaluate () {
	if (type == "abs") {
		float temp = value1->evaluate();
		return (temp < 0 ? -temp : temp);
	}
	else return -(value1->evaluate());
}

// for variable sub-expression
Variable::Variable (float value1, std::string name, bool st): 
	value1{value1}, name{name}, st{st} {}

Variable::~Variable () {
	return; // do nothing
}

void Variable::prettyprint () {
	if (!st) std::cout << name;
	else std::cout << value1; 
}

void Variable::set (std::string var, float val) {
	if (name == var) {
		st = true;
		value1 = val;
	}
}

void Variable::unset (std::string var) {
	if (name == var) st = false;
}

float Variable::evaluate () {
	if (st) return value1;
	else throw std::invalid_argument (name);
}

// for Value sub-expression
Value::Value (float value1): 
	value1{value1} {}

Value::~Value () {
	return; // do nothing
}

void Value::prettyprint () {
	std::cout << value1;
}

void Value::set (std::string var, float val) {
	return;
}

void Value::unset (std::string var) {
	return;
}

float Value::evaluate () {
	return value1;
}


// for intepreter
Interpreter::Interpreter ():
	expr{nullptr} {}

Interpreter::Interpreter (std::istream &in, std::ostream &out = std::cout):
	expr{nullptr}, in{in}, out{out} {}


float Interpreter::evaluate () {
	try {
		float res = expr->evaluate();
		return res;
	} catch (...) {
		throw;
	}
}

void Interpreter::set_var (std::string var, float val) {
	if (expr == nullptr) return;
	expr->set(var, val);
}

void Interpreter::unset_var (std::string var) {
	if (expr == nullptr) return;
	expr->unset(var);
}

