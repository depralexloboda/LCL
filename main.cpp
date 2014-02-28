#include <iostream>
#include "lcl/lambda_calculus.hpp"

int main(int argc, char **argv) {
	using namespace lambda_calculus;
    lambda a("\\x.x (x y (\\a.a b)) z");
    return 0;
}
