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
		
		string to_string();
		string to_string(bool&);
		
		void get_free_variables(set<variable>&, map<variable, int>&);
		bool is_free_to_substitude(const variable&, set<variable>&, bool);
		int count_of_betaredexes();
	};
}
#endif // ABSTRACTION_HPP
