#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>
#include "lambda.hpp"

namespace lambda_calculus{
	using std::string;
	class variable: public lambda_impl
	{
		std::string name;
	public:
		variable(string);
		variable(const variable&);
		variable(variable&&);
		variable& operator=(const variable&);
		variable& operator=(variable&&);
		~variable();
		lambda_impl* clone() const;
		lambda_impl* move();
	};
}
#endif // VARIABLE_HPP
