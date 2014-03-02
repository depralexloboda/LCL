#include "application.hpp"

namespace lambda_calculus{
	application::application(const lambda& _left, const  lambda& _right) :left(_left), right(_right){}
	
	application::application(lambda&& _left, lambda&& _right) :left(std::move(_left)), right(std::move(_right)){}
	
	application::application(const application& x) :left(x.left), right(x.right){}
	
	application::application(application&& x) :left(std::move(x.left)), right(std::move(x.right)){}
	
	application::~application(){}
	
	lambda_impl* application::clone() const{
		return new application(left, right);
	}
	
	lambda_impl* application::move(){
		return new application(std::move(left), std::move(right));
	}
	
	application& application::operator=(const application& x){
		if(this != &x){
			application temp(x);
			left = std::move(temp.left);
			right = std::move(temp.right);
		}
		return *this;
	}
	
	string application::to_string(){
		return "(" + left.to_string() + ")" + " (" + right.to_string() + ")";
	}
	
	string application::to_string(bool& x){
		string res1 = lambda_calculus::to_string(left, x);
		bool x1 = x;
		string res2 = lambda_calculus::to_string(right, x);
		if(x1){
			return "(" + res1 + ") " + res2;
		}
		x = x1 || x;
		if(right.is_application()){
			return res1 + " (" + res2 + ")";
		} else {
			return res1 + " " + res2;
		}
	}
	
	application& application::operator=(application&& x){
		if(this != &x){
			application temp(std::move(x));
			left = std::move(temp.left);
			right = std::move(temp.right);
		}
		return *this;
	}
	
	void application::get_free_variables(set<variable>& res, map<variable, int>& linked){
		lambda_calculus::get_free_variables(left, res, linked);
		lambda_calculus::get_free_variables(right, res, linked);
	}
	
	bool application::is_free_to_substitude(const variable& x, set<variable>& freed, bool is_linked){
		return lambda_calculus::is_free_to_substitude(left, x, freed, is_linked) ||
				lambda_calculus::is_free_to_substitude(right, x, freed, is_linked);
	}
	
	int application::count_of_betaredexes()
	{	
		int result = left.count_of_betaredexes() + right.count_of_betaredexes();
		if(left.is_abstraction()){
			++result;
		}
		return result;
	}
}
