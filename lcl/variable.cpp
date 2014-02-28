#include "variable.hpp"

namespace lambda_calculus{
	variable::variable(string s) :name(s){}
	
	variable::variable(const variable& x) :name(x.name){}
	
	variable::variable(variable&& x) :name(std::move(x.name)){}
	
	variable& variable::operator=(const variable& x){
		if(&x != this){
			variable temp(x);
			name = std::move(temp.name);
		}
		return *this;
	}
	
	variable& variable::operator=(variable&& x){
		if(&x != this){
			variable temp(std::move(x));
			name = std::move(temp.name);
		}
		return *this;
	}
	
	variable::~variable(){}
	
	lambda_impl* variable::clone() const{
		return new variable(name);
	}
	
	lambda_impl* variable::move(){
		return new variable(std::move(name));
	}
	
}