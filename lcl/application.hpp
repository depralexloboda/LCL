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
		lambda_impl* clone() const;
		lambda_impl* move();
		
		string to_string();
		string to_string(bool&);
		
		void get_free_variables(set<variable>&, map<variable, int>&);
		bool is_free_to_substitude(const variable&, set<variable>&, bool);
		int count_of_betaredexes();
	};
}

#endif // APPLICATION_HPP
