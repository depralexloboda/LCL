#include "lambda_calculus.hpp"
#include <string>

namespace {
	using namespace lambda_calculus;
	using std::string;
	enum token_type{
        LAMBDA = '\\', POINT = '.', VARIABLE, SPACE = ' ', LP = '(', RP = ')', END
	};
	class Parser{
		string s;
		int pos;
		token_type current_token;
		string var_name;
		
		token_type next_token(){
            ++pos;
			if(pos >= s.size()){
				current_token = END;
                return END;
			}
			switch(s[pos]){
			case LAMBDA: case POINT: case SPACE: case LP: case RP:
                current_token = token_type(s[pos]);
				return token_type(s[pos]);
			default:
				var_name = "";
				if(s[pos] >= 'a' && s[pos] <= 'z'){
					var_name += s[pos];
					while(++pos < s.size() && s[pos] == '\''){
						var_name += '\'';
					}
					--pos;
                    current_token = VARIABLE;
					return VARIABLE;
				} else {
					throw parser_exception(s, "Unrecognized token", pos);
				}
			}
		}
		
		lambda term(){
			token_type token = next_token();
			if(token == LAMBDA){
				if(next_token() != VARIABLE){
					throw parser_exception(s, "Expected variable", pos);
				}
				if(next_token() != POINT){
					throw parser_exception(s, "Expected point \'.\'", pos);
                }
                variable var(var_name);
                return abstraction(std::move(var), expr());
			}
			if(token == VARIABLE){
                if(next_token() == VARIABLE){
                    throw parser_exception(s, "Unexpected variable", pos);
                }
				return variable(var_name);
			}
			if(token == LP){
				lambda l = expr();
                if(current_token != RP){
					throw parser_exception(s, "Expected \')\'", pos);
				}
                next_token();
				return l;
			}
			throw parser_exception(s, "Expected \'\\\', variable or \'(\'", pos);
		}
		
		lambda expr(){
			lambda left = term();
			while(current_token == SPACE){
				left = application(std::move(left), term());
			}
			return left;
		}
	public:
		lambda parse(string _s){
			s = _s;
			pos = -1;
			lambda temp = expr();
            if(current_token != END){
                throw parser_exception(s, "Syntax error", pos);
            }
			return std::move(temp);
		}
	};
}

namespace lambda_calculus{
	lambda::lambda(string s) :lambda(Parser().parse(s)){}
	
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
        x.term = nullptr;
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
	
	string lambda::to_string(){
		return term->to_string();
	}
	
	string lambda::to_string(bool& b){
		return term->to_string(b);
	}
	
	lambda::operator string(){
		bool b;
		return to_string(b);
	}	
	
	bool lambda::is_application(){
		return (dynamic_cast<application*>(term) != 0);
	}
	
    parser_exception::parser_exception(string _str, string _cause, int _pos) :str(_str), cause(_cause), pos(_pos){}
	
	string parser_exception::message(){
        string res = cause + "\n" + str + "\n";
		for(int i = 0; i < pos; i++){
			res += " ";
		}
        res += "^\n";
        return res;
	}
}
