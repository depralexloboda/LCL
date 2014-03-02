#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>
#include "lambda.hpp"

namespace lambda_calculus{
	using std::string;
	
	class variable: public lambda_impl
	{
		string name;
	public:
		variable(string);
		variable(const variable&);
		variable(variable&&);
		variable& operator=(const variable&);
		variable& operator=(variable&&);
		~variable();
		lambda_impl* clone() const;
		lambda_impl* move();
		
		string to_string();
		string to_string(bool&);
		
		void get_free_variables(set<variable>&, map<variable, int>&);
		bool is_free_to_substitude(const variable&, set<variable>&, bool);
		int count_of_betaredexes();
		
		bool operator<(const variable&) const;
		bool operator==(const variable&) const;
	};
}
#endif // VARIABLE_HPP
