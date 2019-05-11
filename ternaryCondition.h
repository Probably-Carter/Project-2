class TernaryCondition : public SubExpression
{
public:
	TernaryCondition(Expression* first, Expression* second, Expression* third) :
		SubExpression(first, second, third)
	{
	}
	int evaluate()
	{
		return third->evaluate() ? first->evaluate() : second->evaluate();
	}
};