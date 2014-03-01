#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>
#include "lambda.hpp"

namespace lambda_calculus{
	class application: public lambda_impl{
		lambda left, right;
	public:
		application(const lambda&, const lambda&);
		application(lambda&&, lambda&&);
		application(const application&);
		application(application&&);
		application& operator=(const application&);
		application& operator=(application&&);
		~application();
		string to_string();
		string to_string(bool&);
		lambda_impl* clone() const;
		lambda_impl* move();
	};
}

#endif // APPLICATION_HPP
