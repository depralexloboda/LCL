#include "abstraction.hpp"

namespace lambda_calculus{
    abstraction::abstraction(const variable& _var, const lambda& _term) :var(_var), term(_term) {}
	
	abstraction::abstraction(variable&& _var, lambda&& _term) :var(std::move(_var)), term(std::move(_term)){}
	
	abstraction::abstraction(const abstraction& x) :term(x.term), var(x.var){}
	
	abstraction::abstraction(abstraction&& x) :term(std::move(x.term)), var(std::move(x.var)){}
	
	lambda_impl* abstraction::clone() const{
		return new abstraction(var, term);
	}
	
	lambda_impl* abstraction::move(){
		return new abstraction(std::move(var), std::move(term));
	}
	
	abstraction::~abstraction(){}
	
	abstraction& abstraction::operator=(const abstraction& x){
		if(&x != this){
			abstraction temp(x);
			var = std::move(temp.var);
			term = std::move(temp.term);
		}
		return *this;
	}
	
	string abstraction::to_string(){
		return "\\" + var.to_string() + "." + "(" + term.to_string() + ")";
	}
	
	string abstraction::to_string(bool& x){
		string res = "\\" + var.to_string(x) + "." + lambda_calculus::to_string(term, x);
		x = true;
		return res;
	}
	
	abstraction& abstraction::operator=(abstraction&& x){
		if(&x != this){
			abstraction temp(std::move(x));
			var = std::move(temp.var);
			term = std::move(temp.term);
		}
		return *this;
	}
	
	void abstraction::get_free_variables(set<variable>& res, map<variable, int>& linked){
		++linked[var];
		lambda_calculus::get_free_variables(term, res, linked);
		--linked[var];
	}
	
	bool abstraction::is_free_to_substitude(const variable& x, set<variable>& freed, bool is_linked){
		if(freed.find(var) != freed.end()){
			return lambda_calculus::is_free_to_substitude(term, x, freed, true);
		}
		return lambda_calculus::is_free_to_substitude(term, x, freed, is_linked); 
	}
	
	int abstraction::count_of_betaredexes(){
		return term.count_of_betaredexes();
	}
}
