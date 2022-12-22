#ifndef STACK_H
#define STACK_H

#include <vector>

class Expression;

class Stack {
	public:
		std::vector<Expression *> data;
		void push (Expression *exp);
		Expression *pop ();
		Expression *peek ();
		int length ();
};

#endif
