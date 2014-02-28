#ifndef ABSTRACTION_HPP
#define ABSTRACTION_HPP

#include "lambda.hpp"
#include "variable.hpp"

namespace lambda_calculus{
	class abstraction: public lambda_impl
	{
		variable var;
		lambda term;
	public:
		abstraction(const variable& _var, const lambda& _term);
		abstraction(variable&& _var, lambda&& term);
		abstraction(const abstraction&);
		abstraction(abstraction&&);
		abstraction& operator=(const abstraction&);
		abstraction& operator=(abstraction&&);
		lambda_impl* clone() const;
		lambda_impl* move();
		~abstraction();
	};
}
#endif // ABSTRACTION_HPP
