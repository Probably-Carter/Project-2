class SubExpression : public Expression
{
public:
	SubExpression(Expression* left, Expression* right);
	SubExpression(Expression* left);
	SubExpression(Expression* first, Expression* second, Expression* third);
	static Expression* parse(stringstream& in);

protected:
	Expression* left;
	Expression* right;
	Expression* first;
	Expression* second;
	Expression* third;
};