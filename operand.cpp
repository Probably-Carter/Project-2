#include <cctype>
#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

#include <sstream>

//definition of the function parse()

Expression* Operand::parse(stringstream& in)

{

	char paren;
	double value;
	in >> ws;
	if (isdigit(in.peek()))

	{

		in >> value;
		Expression* literal = new Literal(value);
		return literal;

	}

	if (in.peek() == '(')

	{

		in >> paren;
		return SubExpression::parse(in);

	}

	else
		return new Variable(parseName(in));
	return 0;

}