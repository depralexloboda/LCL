#include "lcl/lambda_calculus.hpp"
#include <iostream>

int main(int argc, char **argv) {
	using namespace lambda_calculus;
	using std::string;
	string s;
    std::getline(std::cin, s);
	try{
		lambda expr(s);
		std::cout << expr.to_string() << "\n";
	} catch(parser_exception e){
		std::cout << e.message();
	}
	return 0;
}
