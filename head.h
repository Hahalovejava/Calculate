#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#define random(low,high) (rand()%(high-low+1)+1)//high-low+1��������ķ�Χ��+1��֤û��0��1��ʼ
#define maxsize 1000
using namespace std;

struct Fraction{
	int up, down;
	string high, low;
};

int max(int a, int b);
int min(int a, int b);
int greatest_common_divisor(int a, int b);//�����Լ��
Fraction gener(int up, int down);//���ɷ���
Fraction reafra(int d, int u);//������ɷ���
Fraction reduction(Fraction n1);//����Լ��
Fraction add(Fraction n1, Fraction n2);//�����ӷ�
Fraction minus1(Fraction n1, Fraction n2);//��������
Fraction mul(Fraction n1, Fraction n2);//�����˷�
Fraction div(Fraction n1, Fraction n2);//��������
void print_frac(Fraction f);//�������
string FraToString(Fraction f);//������ת��Ϊstring��ʽ
void trans(string exp, char postexp[]);//����׺���ʽת��Ϊ��׺���ʽ
Fraction calculate(char postexp[]);//�����׺���ʽ��ֵ
void generate(int time, int low, int high, int muldiv, int frac, int par);//����
int ran(int down, int up);//�������

