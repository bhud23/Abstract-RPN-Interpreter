#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include "expression.h"
#include "stack.h"

class Interpreter {
    istream &in;
    ostream &out;
    ostream &err;
    public:
        Interpreter (istream &in = std::cin, ostream &out = std::cout, ostream &err = std::cerr);
        ~Interpreter ();
        Expression *build_expression ();
};

#endif