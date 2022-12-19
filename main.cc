#include "stack.h"
#include "expression.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void build_expression (Stack &s) {
	return;
}

int main () {
	Stack s;
	string inp;
	while (cin >> inp) {
		// need to support upper and lower case
		if (inp == "done") break; // expression has ended
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
		else {
			int val;
			istringstream iss {inp};
			if (iss >> val) {
				Integer *temp = new Integer {val};
				s.push(temp);
			}
			else {
				Variable *temp = new Variable {0, inp, false};
				s.push(temp);
			}
		}
	}
	if (s.data.size() > 0) {
		s.peek()->prettyprint();
		cout << '\n';
	}
	while (cin >> inp) {
		if (inp == "print") {
			s.peek()->prettyprint();
			cout << '\n';
		}
		else if (inp == "eval") {
			int out;
			try {
				out = s.peek()->evaluate();
				cout << out << endl;
			} catch (invalid_argument &err) {
				cout << err.what() << " has no value." << endl;
			}
		}
		else if (inp == "set") {
			int value;
			string var;
			cin >> var;
			cin >> inp;
			istringstream iss {inp};
			iss >> value;
			s.peek()->set(var, value);
		}
		else if (inp == "unset"){
			string var;
			cin >> var;
			s.peek()->unset(var);
		}
		else continue;
	}
	if (s.length() > 0) delete s.peek();
	return 0;
}
