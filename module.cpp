#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

//create an object of SymbolTable
SymbolTable symbolTable;

//prototype of the function
void parseAssignments(stringstream& in);

//define main function
int main()
{
	// declare the variables
	Expression* expression;
	char paren, comma;

	string line;

	// create an input file stream
	ifstream fin("input.txt");

	if (!fin.is_open())
		perror("error while opening file");

	//use a loop, to read the content from the file

	while (getline(fin, line))
	{
		symbolTable.init();
		if (!fin)

			break;

		stringstream in(line, ios_base::in);
		in >> paren;
		cout << line << " ";
		expression = SubExpression::parse(in);
		in >> comma;
		parseAssignments(in);

		int result = expression->evaluate();
		cout << "Value = " << result << endl;

	}

	system("pause");
	return 0;

}

//definition of the function parseAssignments()

void parseAssignments(stringstream& in)

{

	char assignop, delimiter;
	string variable;
	int value;
	symbolTable.init();
	do
	{
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);

	}
	while (delimiter == ',');
}