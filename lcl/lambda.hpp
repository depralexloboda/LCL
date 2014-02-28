#ifndef LAMBDA_HPP
#define LAMBDA_HPP
#include <string>

namespace lambda_calculus{
	using std::string;
	
	class parser_exception{
		
	};
	
	class lambda_impl{
	public:
		virtual ~lambda_impl(){}
		virtual lambda_impl* clone() const = 0;
		virtual lambda_impl* move() = 0;
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
	};
}

#endif // LAMBDA_HPP
