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
	
	application& application::operator=(application&& x){
		if(this != &x){
			application temp(std::move(x));
			left = std::move(temp.left);
			right = std::move(temp.right);
		}
		return *this;
	}
}
