#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;
void convert(const std::string &infix, std::string &postfix);
int precedence(char symbol);
bool isOperator(char symbol);
int evaluate(const std::string &postfix);
int main()
{
	const string infix = "1*(2+3)";
	string postfix;
	convert(infix, postfix);

	cout << "Infix expression is: " << infix << endl;
	cout << "Postfix expression is: " << postfix << endl;
	cout << "Evaluated expression is :" << evaluate(postfix) << endl;

	return 0;
}

void convert(const std::string & infix, std::string & postfix)
{
	string stack("#");
	for (auto symbol : infix) {
		if (!isOperator(symbol))
			postfix.push_back(symbol);
		else if (symbol == '(')
			stack.push_back(symbol);
		else if (symbol == ')') {
			while (stack.back() != '(') {
				postfix.push_back(stack.back());
				stack.pop_back();
			}
			stack.pop_back();	// pop out (.
		} else if (precedence(symbol) > precedence(stack.back()))
				stack.push_back(symbol);
		else {
			while (precedence(symbol) <= precedence(stack.back())) {
				postfix.push_back(stack.back());
				stack.pop_back();
			}
			stack.push_back(symbol);
		}
	}
	while (stack.back() != '#') {
		postfix.push_back(stack.back());
		stack.pop_back();
	}
}

int precedence(char symbol)
{
	if (string("+-").find(symbol) != string::npos)
		return 2;
	else if (string("*/").find(symbol) != string::npos)
		return 3;
	else if (symbol == '^')
		return 4;
	else if (string("()#").find(symbol) != string::npos)
		return 1;
	else
		return INT_MIN;
}

bool isOperator(char symbol)
{
	return (string("+-*/^()").find(symbol) != string::npos);
}

int evaluate(const std::string & postfix)
{
	stack<int> stack_int;
	for (auto ch : postfix) {
		if (isdigit(ch))
			stack_int.push(ch - '0');	// Push the operand
		else {
			// Operator, pop two operands
			int operand2 = stack_int.top();
			stack_int.pop();
			int operand1 = stack_int.top();
			stack_int.pop();

			switch (ch) {
			case '+':
				stack_int.push(operand1 + operand2);
				break;
			case '-':
				stack_int.push(operand1 - operand2);
				break;
			case '*':
				stack_int.push(operand1 * operand2);
				break;
			case '/':
				stack_int.push(operand1 / operand2);
				break;
			}
		}
	}
	return stack_int.top();
}
