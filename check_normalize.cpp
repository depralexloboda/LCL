#include "lcl/lambda_calculus.hpp"
#include <iostream>

int main(int argc, char **argv) {
	using namespace lambda_calculus;
	string s;
	std::getline(std::cin, s);
	try{
		lambda l = s;
		if(l.count_of_betaredexes()){
			std::cout << "Выражение '" << l << "' представлено не в нормальной форме" << std::endl;
		} else {
			std::cout << "Выражение '" << l << "' представлено в нормальной форме" << std::endl;
		}
	} catch(parser_exception e){
		std::cout << e.message() << std::endl;
	}
	return 0;
}