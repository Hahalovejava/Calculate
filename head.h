#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#define random(low,high) (rand()%(high-low+1)+1)//high-low+1是随机数的范围，+1保证没有0从1开始
#define maxsize 1000
using namespace std;

struct Fraction{
	int up, down;
	string high, low;
};

int max(int a, int b);
int min(int a, int b);
int greatest_common_divisor(int a, int b);//求最大公约数
Fraction gener(int up, int down);//生成分数
Fraction reafra(int d, int u);//随机生成分数
Fraction reduction(Fraction n1);//分数约分
Fraction add(Fraction n1, Fraction n2);//分数加法
Fraction minus1(Fraction n1, Fraction n2);//分数减法
Fraction mul(Fraction n1, Fraction n2);//分数乘法
Fraction div(Fraction n1, Fraction n2);//分数除法
void print_frac(Fraction f);//输出分数
string FraToString(Fraction f);//将分数转换为string形式
void trans(string exp, char postexp[]);//将中缀表达式转换为后缀表达式
Fraction calculate(char postexp[]);//计算后缀表达式的值
void generate(int time, int low, int high, int muldiv, int frac, int par);//运算
int ran(int down, int up);//随机函数

