#include "stdafx.h"
#include <stdlib.h>
#include <stack>
#include "iostream"
using namespace std;
#include <string>

int level(char m){   //符号优先级
	switch (m){
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
	case ')':
		return 0;
	case '#':
		return -1;
	default:
		break;
	}
}

int Calc(string s, string ss){
	int i = 0;
	double c = 0;
	bool m = 1;
	string I = "";

	stack<char>y;
	stack<int>x;

	while (s[i] != '$'){
		//put number into stack
		if (s[i] > 47 && s[i] < 58){         //the char 0~9 of ASCII is 47~58
			I += s[i];
			int j;
			for (j = i + 1; s[j]>47 && s[j] < 58; j++){
				I += s[j];
			}
			x.push(atoi(I.c_str()));
			I = "";
			i = j;
		}
		if (s[i] >= 35 && s[i] <= 47){

			if (y.size() == 0 || s[i] == '(' || level(s[i])>level(y.top())){
				y.push(s[i]);
			}

			else{
				if (s[i] == ')'){//遇到')'的情况，直接将y中的符号一个一个拿出来运算，直到遇到'('为止
					for (; y.top() != '('; y.pop()){
						char d = y.top();
						double a = x.top();
						x.pop();
						double b = x.top();
						x.pop();
						switch (d){
						case '+':{
									 c = a + b;
									 break;
						}
						case '-':{
									 c = b - a;
									 break;
						}
						case '*':{
									 c = a*b;
									 break;
						}
						case '/':{
									 c = b / a;
									 break;
						}
						default:
							break;
						}
						x.push(c);
					}//end for
					y.pop();  //弹出'('
				}
				else{                      //遇到+，-，*，/的处理
					for (; y.size() != 0 && level(s[i]) <= level(y.top()); y.pop()){
						{

							char d = y.top();
							int a = x.top();
							x.pop();
							int b = x.top();
							x.pop();
							switch (d){
							case '+':{
										 c = a + b;
										 break;
							}
							case '-':{
										 c = b - a;
										 break;
							}
							case '*':{
										 c = a*b;
										 break;
							}
							case '/':{
										 c = b / a;
										 break;
							}
							default:
								break;
							}//end of switch
							x.push(c);
						}//end of if 
					}//end of for
					y.push(s[i]);
				}
			}//end of else
			i++;
		}
		else{
			cout << "Expression" << s[i] << "is a wrong matter!"<<endl;
			m = 0;
			break;
		}
	}//end of while
	if (m){
		return x.top();
	}
}