#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class Node
{
public:
	char data;
	Node* next;
};

class Stack
{
private:
	Node* head;
public:
	Stack(void)
	{
		head = NULL;
	}
	~Stack()
	{

	}
	void push(char t)
	{
		Node* newNode = new Node;
		newNode->data = t;
		newNode->next = head;
		head = newNode;
	}
	char pop()
	{
		if (isEmpty())
		{
			cout << "Stack Already Empty!\n";
		}
		else
		{
			char tp = head->data;
			Node*p = head;
			head = head->next;
			delete p;
			return tp;
		}
	}
	char top()
	{
		if (!isEmpty())
		{
			char tp = head->data;
			return tp;
		}
		else
		{
			cout << "Stack Already Empty!\n";
		}
	}
	bool isEmpty()
	{
		return (head == NULL);
	}

};
int main()
{
	string s;
	Stack oper;
	cout << "Enter the operation : ";
	getline(cin, s);
	for (int i = 0; s[i] != '\0'; i++)//verifying input
	{
		if(isdigit(s[i])&&s[i+1]=='('||(!isdigit(s.front())&&s.front()!='(')||(!isdigit(s.back())&&s.back()!=')'))
		{ 
			cout << "Syntax Error ";
			_getch();
			return 0;
		}
		else if (isdigit(s[i]) || isdigit(s[i + 1]) || s[i + 1] == '(' || s[i] == ')'|| s[i + 1] == '\0')
		{
				continue;
		}
		else
		{
			cout << "Syntax Error ";
			_getch();
			return 0;
		}
	}
	cout << "\nPostfix of your operation is :";
	int i = 0;
	while(1)
	{
		
			if (isdigit(s[i]))//check if the char is digit
			{
				cout << s[i] ;
				i++;
			}
			if (s[i] == '\0')//to check the end of string
			{
				while (!oper.isEmpty())//empities the stack
				{
					if (oper.top() == '(')//incase of wrong input
					{
						system("CLS");
						cout << "Syntax Error";
						break;
					}
					else
					{
						cout << oper.pop();
					}
				}
				break;
			}
			if (s[i] == ')')//pops the operators in brackets
			{
				while (!oper.isEmpty() && oper.top() != '(')
				{
					cout << oper.pop();
				}
				if (oper.top() != '(')//incase of wrong input
				{
					system("CLS");
					cout << "Syntax Error";
					break;
				}
				else
				{
					oper.pop();
				}
			}
			else if(oper.isEmpty()||s[i]=='('|| s[i] == '^' || ((oper.top() == '+' || oper.top() == '-') && (s[i] == '*' || s[i] == '/' || s[i] == '%')) || oper.top() == '(')
			{
				oper.push(s[i]);
			}
			else
			{
				cout << oper.pop();
				oper.push(s[i]);
			}
		i++;
	}
	_getch();
	return 0;
}