#include "lambda.hpp"

namespace lambda_calculus{
	lambda::lambda(const lambda& x){
		term = x.term->clone();
	}
	
	lambda::lambda(lambda_impl& x){
		term = x.clone();
	}
	
	lambda::lambda(lambda_impl&& x){
		term = x.move();
	}
	
	lambda::lambda(lambda&& x){
		term = x.term;
		x.term == nullptr;
	}
	
	lambda& lambda::operator=(const lambda_impl& x){
		term = x.clone();
		return *this;
	}
	
	lambda& lambda::operator=(lambda_impl&& x){
		term = x.move();
		return *this;
	}
	
	lambda& lambda::operator=(const lambda& x){
		if(this != &x){
			lambda temp(x);
			term = temp.term;
			temp.term = nullptr;
		}
		return *this;
	}
	
	lambda& lambda::operator=(lambda&& x){
		if(this != &x){
			term = x.term;
			x.term = nullptr;
		}
		return *this;
	}
	
	lambda::~lambda(){
		delete term;
	}
}