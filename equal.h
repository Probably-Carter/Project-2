class Equal : public SubExpression
{
public:
	Equal(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() == right->evaluate();
	}
};