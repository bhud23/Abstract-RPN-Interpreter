#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include "stack.h"

class segmentation_fault;

class Expression {
	public:
		virtual ~Expression () = default;
		virtual void prettyprint () = 0;
		virtual void set (std::string var, float val) = 0;
		virtual void unset (std::string var) = 0;
		virtual float evaluate () = 0;
};

class Binary : public Expression {
	public:
		Expression *value1;
		Expression *value2;
		std::string type;
		Binary (Expression *value1, Expression *value2, std::string type);
		~Binary ();
		void prettyprint ();
		void set (std::string var, float val);
		void unset (std::string var);
		float evaluate ();
};

class Unary : public Expression {
	public:
		Expression *value1;
		std::string type;
		Unary (Expression *value1, std::string type);
		~Unary ();
		void prettyprint ();
		void set (std::string var, float val);
		void unset (std::string var);
		float evaluate ();
};

class Variable : public Expression {
	public:
		float value1;
		const std::string name;
		bool st; 
		Variable (float value1, std::string name, bool st);
		~Variable ();
		void prettyprint ();
		void set (std::string var, float val);
		void unset (std::string var);
		float evaluate ();
};

class Value: public Expression {
	public:
		float value1;
		Value (float value1);
		~Value ();
		void prettyprint ();
		void set (std::string var, float val);
		void unset (std::string var);
		float evaluate ();
};

class Interpreter {
	private:
		std::istream &in = std::cin;
		std::ostream &out = std::cout;
		Expression *expr;
	public:
		Interpreter ();
		Interpreter (std::istream &in, std::ostream &out);
		float evaluate ();
		void read_expression ();
		void display ();
		void set_var (std::string var, float val);
		void unset_var (std::string var);
};

#endif
