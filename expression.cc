#include "expression.h"
#include <iostream>
#include <stdexcept>

Expression::~Expression () {
	return; // do nothing
}

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

void Binary::set (std::string var, int val) {
	value1->set(var, val);
	value2->set(var, val);
}

void Binary::unset (std::string var) {
	value1->unset(var);
	value2->unset(var);
}

int Binary::evaluate () {
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

void Unary::set (std::string var, int val) {
	value1->set(var, val);
}

void Unary::unset (std::string var) {
	value1->unset(var);
}

int Unary::evaluate () {
	if (type == "abs") {
		int temp = value1->evaluate();
		return (temp < 0 ? -temp : temp);
	}
	else return -(value1->evaluate());
}

// for variable sub-expression
Variable::Variable (int value1, std::string name, bool st): 
	value1{value1}, name{name}, st{st} {}

Variable::~Variable () {
	return; // do nothing
}

void Variable::prettyprint () {
	if (!st) std::cout << name;
	else std::cout << value1; 
}

void Variable::set (std::string var, int val) {
	if (name == var) {
		st = true;
		value1 = val;
	}
}

void Variable::unset (std::string var) {
	if (name == var) st = false;
}

int Variable::evaluate () {
	if (st) return value1;
	else throw std::invalid_argument (name);
}

// for Integer sub-expression
Integer::Integer (int value1): 
	value1{value1} {}

Integer::~Integer () {
	return; // do nothing
}

void Integer::prettyprint () {
	std::cout << value1;
}

void Integer::set (std::string var, int val) {
	return;
}

void Integer::unset (std::string var) {
	return;
}

int Integer::evaluate () {
	return value1;
}
