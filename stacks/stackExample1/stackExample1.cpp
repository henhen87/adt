#include "stdafx.h"
#include <stack>
#include <iostream>
#include<vector>

using namespace std;

bool isOpen(char symbol);
bool isClosed(char symbol);
bool matches(char symbol, stack<char>& openSymbols);

int main()
{
	//using namespace std; /* Scoping within function */
	vector<char> symbols = {'(',')', '(', ')', '[', '{', '}', ']', '[', '['};
	bool balanced = true;
	stack<char> openSymbols;
	
	for (auto sym : symbols)
	{
		if (isOpen(sym))
		{
			openSymbols.push(sym);
		}
		else if (isClosed(sym))
		{
			if (openSymbols.empty())
			{
				balanced = false;
			}
			else
			{
				balanced = matches(sym, openSymbols);
			}
		}
	}

	if (openSymbols.size() > 0)
	{
		balanced = false;
	}

	cout << "X02150, do the symbols match? \n";
	cout << balanced << endl;

    return 0;
}

bool isOpen(char symbol)
{
	return ((symbol == '(' || symbol == '{' || symbol == '['));
}

bool isClosed(char symbol)
{
	return ((symbol == ')' || symbol == '}' || symbol == ']'));
}

bool matches(char symbol, stack<char>& openSymbols)
{
	char topSymbol = openSymbols.top();
	openSymbols.pop();
	cout << "SIZE OF STACK COPY: " << openSymbols.size() << endl;
	cout << "Top Symbol: " << topSymbol << endl;
	return (((topSymbol == '(' && symbol == ')') || (topSymbol == '{' && symbol == '}') || (topSymbol == '[' && symbol == ']')));
}
