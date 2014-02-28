#include "abstraction.hpp"

namespace lambda_calculus{
	abstraction::abstraction(const variable& _var, const lambda& _term) :var(var), term(_term) {}
	
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
	
	abstraction& abstraction::operator=(abstraction&& x){
		if(&x != this){
			abstraction temp(std::move(x));
			var = std::move(temp.var);
			term = std::move(temp.term);
		}
		return *this;
	}
}