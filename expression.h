#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

template <typename T> class Expression {
	public:
		virtual ~Expression ();
		virtual void prettyprint () = 0;
		virtual void set (std::string var, T val) = 0;
		virtual void unset (std::string var) = 0;
		virtual T evaluate () = 0;
};

template <typename T> class Binary : public Expression {
	public:
		Expression *value1;
		Expression *value2;
		std::string type;
		Binary(Expression *value1, Expression *value2, std::string type);
		~Binary ();
		void prettyprint ();
		void set (std::string var, T val);
		void unset (std::string var);
		T evaluate ();
};

template <typename T> Unary : public Expression {
	public:
		Expression *value1;
		std::string type;
		Unary (Expression *value1, std::string type);
		~Unary ();
		void prettyprint ();
		void set (std::string var, int val);
		void unset (std::string var);
		T evaluate ();
};

template <typename T> class Variable : public Expression {
	public:
		T value1;
		const std::string name;
		bool st; 
		Variable (T value1, std::string name, bool st);
		~Variable ();
		void prettyprint ();
		void set (std::string var, T val);
		void unset (std::string var);
		T evaluate ();
};

template <typename T> class Value: public Expression {
	public:
		T value1;
		Value (T value1);
		~Value ();
		void prettyprint ();
		void set (std::string var, T val);
		void unset (std::string var);
		T evaluate ();
};
#endif
