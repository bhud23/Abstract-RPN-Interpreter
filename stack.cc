#include "stack.h"

void Stack::push(Expression *exp) {
	data.push_back(exp);
}

Expression *Stack::pop () {
	Expression *temp = data.back();
	data.pop_back();
	return temp;
}

Expression *Stack::peek() {
	return data.back();
}

int Stack::length () {
	return data.size();
}
