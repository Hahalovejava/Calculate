// FractionCalc.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "head.h"



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "��������Ŀ������1~100����";
	int time, down, up, muldiv=0, frac=0, par=0;
	cin >> time;//time��Ŀ��
	cout <<"��������ֵ����ֵ��Χ:";
	cin >> down >> up;//[down,up]Ϊ��������Χ
	cout << "�Ƿ�����˳����������㣨y/n):";
	char yn1;
	cin >> yn1;
	yn1 == 'y' || yn1 == 'Y' ? muldiv = 1 : muldiv = 0;
	cout << "�Ƿ��������Ų������㣨y/n):";
	char yn2;
	cin >> yn2;
	yn2 == 'y' || yn2 == 'Y' ? par  = 1 : par = 0;
	cout << "�Ƿ�����������������㣨y/n):";
	char yn3;
	cin >> yn3;
	yn3 == 'y' || yn3 == 'Y' ? frac = 1 : frac = 0;
	cout << "****************************************************************************" << endl;
	generate(time, down, up, muldiv, frac, par);
	system("pause");
	return 0;
}

