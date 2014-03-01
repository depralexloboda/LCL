#ifndef LAMBDA_HPP
#define LAMBDA_HPP
#include <string>

namespace lambda_calculus{
	using std::string;
	using std::ostream;
	
	class parser_exception{
		int pos;
		string str;
		string cause;
	public:
		parser_exception(string str, string cause, int pos);
		string message();
	};
	
	class lambda_impl{
	public:
		virtual ~lambda_impl(){}
		virtual lambda_impl* clone() const = 0;
		virtual lambda_impl* move() = 0;
		virtual string to_string() = 0;
		virtual string to_string(bool&) = 0;
	};
	
	class lambda{
		lambda_impl* term;
	public:
		lambda(string);
		lambda(lambda_impl&);
		lambda(lambda_impl&&);
		lambda& operator=(const lambda_impl&);
		lambda& operator=(lambda_impl&&);
		lambda(const lambda&);
		lambda(lambda&&);
		lambda& operator=(const lambda&);
		lambda& operator=(lambda&&);
		virtual ~lambda();
		string to_string();
		string to_string(bool&);
		operator string();
		bool is_application();
	};
}

#endif // LAMBDA_HPP
