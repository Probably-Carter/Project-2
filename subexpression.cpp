#include <iostream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "equal.h"
#include "negation.h"
#include "and.h"
#include "or.h"
#include "ternaryCondition.h"

#include <sstream>


SubExpression::SubExpression(Expression* left, Expression* right)

{

	this->left = left;
	this->right = right;

}

SubExpression::SubExpression(Expression* first, Expression* second, Expression* third)
{
	this->first = first;
	this->second = second;
	this->third = third;
}

SubExpression::SubExpression(Expression* left)
{
	this->left = left;
}

Expression* SubExpression::parse(stringstream& in)

{

	Expression* left;
	Expression* right;
	Expression* first;
	Expression* second;
	Expression* third;
	char operation, paren;
	bool isTernary = false;
	left = Operand::parse(in);
	in >> operation;
	right = Operand::parse(in);
	if (operation == ':')
	{
		first = left;
		second = right;
		left = Operand::parse(in);
		cin >> operation;
		right = Operand::parse(in);
		if (operation == '?')
		{
			third = right;
			isTernary = true;
		}
	}
	in >> paren;

	if (isTernary == true)
	{
		return new TernaryCondition(first, second, third);
	}

	switch (operation)

	{

	case '+':
		return new Plus(left, right);

	case '-':
		return new Minus(left, right);

	case '*':
		return new Times(left, right);

	case '/':
		return new Divide(left, right);

	case '=':
		return new Equal(left, right);

	case '>':
		return new GreaterThan(left, right);

	case '<':
		return new LessThan(left, right);

	case '!':
		return new Negation(left, right);

	case '&':
		return new And(left, right);

	case '|':
		return new Or(left, right);

	}

	system("pause");

	return 0;

}