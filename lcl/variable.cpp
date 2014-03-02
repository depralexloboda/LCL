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
	
	string variable::to_string(){
		return name;
	}
	
	string variable::to_string(bool& x){
		return name;
	}
	
	lambda_impl* variable::clone() const{
		return new variable(name);
	}
	
	lambda_impl* variable::move(){
        return new variable(std::move(name));
	}
	
	void variable::get_free_variables(set<variable>& res, map<variable,int>& linked){
		if(!linked[*this]){
			res.insert(*this);
		}
	}
	
	bool variable::operator<(const variable& other) const{
		return name < other.name;
	}
	
	bool variable::operator==(const variable& other) const{
		return name == other.name;
	}
	
	bool variable::is_free_to_substitude(const variable& x, set<variable>&, bool is_linked){
		return x.name == name ? is_linked : false;
	}
	
	int variable::count_of_betaredexes(){
		return 0;
	}
}
