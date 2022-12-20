#include "intepreter.h"

Expression *build_expression () {
	Stack s;
	std::string inp;
	while (in >> inp) {
		if (inp == "done") break;
		else if (inp == "ABS") {
			Unary *temp = new Unary {s.pop(), "abs"};
			s.push(temp);
		}
		else if (inp == "NEG") {
			Unary *temp = new Unary {s.pop(), "neg"};
			s.push(temp);
		}
		else if (inp == "+") {
			Expression *val2 = s.pop();
			Binary *temp = new Binary {s.pop(), val2, "+"};
			s.push(temp);
		
		}
		else if (inp == "-") {
			Expression *val2 = s.pop();
			Binary *temp = new Binary {s.pop(), val2, "-"};
			s.push(temp);
		}
		else if (inp == "*" ) {
			Expression *val2 = s.pop();
			Binary *temp = new Binary {s.pop(), val2, "*"};
			s.push(temp);
		}
		else if (inp == "/") {
			Expression *val2 = s.pop();
			Binary *temp = new Binary {s.pop(), val2, "/"};
			s.push(temp);
		}
        // else if (inp == "sqrt"){

        // }
        // else if (inp == "nrt"){

        // }
		else {
			int val;
			istringstream iss {inp};
			if (iss >> val) {
				Value *temp = new Value {val};
				s.push(temp);
			}
			else {
				Variable *temp = new Variable {0, inp, false};
				s.push(temp);
			}
		}
	}
	return s.peek();
}