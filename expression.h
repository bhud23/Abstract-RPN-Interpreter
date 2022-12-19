#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

class Expression {
	public:
		virtual ~Expression ();
		virtual void prettyprint () = 0;
		virtual void set (std::string var, int val) = 0;
		virtual void unset (std::string var) = 0;
		virtual int evaluate () = 0;
};

class Binary : public Expression {
	public:
		Expression *value1;
		Expression *value2;
		std::string type;
		Binary(Expression *value1, Expression *value2, std::string type);
		~Binary ();
		void prettyprint ();
		void set (std::string var, int val);
		void unset (std::string var);
		int evaluate ();
};

class Unary : public Expression {
	public:
		Expression *value1;
		std::string type;
		Unary (Expression *value1, std::string type);
		~Unary ();
		void prettyprint ();
		void set (std::string var, int val);
		void unset (std::string var);
		int evaluate ();
};

class Variable : public Expression {
	public:
		int value1;
		const std::string name;
		bool st; 
		Variable (int value1, std::string name, bool st);
		~Variable ();
		void prettyprint ();
		void set (std::string var, int val);
		void unset (std::string var);
		int evaluate ();
};

class Integer: public Expression {
	public:
		int value1;
		Integer (int value1);
		~Integer ();
		void prettyprint ();
		void set (std::string var, int val);
		void unset (std::string var);
		int evaluate ();
};
#endif
