#ifndef STACK_H
#define STACK_H

#include <vector>
#include "expression.h"

class Stack {
	public:
		std::vector<Expression *> data;
		void push (Expression *exp);
		Expression *pop ();
		Expression *peek ();
		int length ();
};

#endif
