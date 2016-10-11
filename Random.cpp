#include "head.h"



int flag = 1;
int ran(int down, int up){      //随机生成1至n的整数
	if (flag){
		flag = 0;
		srand((unsigned)time(NULL));
	}
	int result = random(down, up);
	return result;
}

bool is_unique(string str, vector<string>s){ //判断生成的算式是否独特
	int count = 0;
	for (int i = 0; i < s.size(); i++){
		if (str != s[i]){
			count++;
		}
		else break;
	}
	if (count == s.size()){
		return true;    //生成的算式是独特的
	}
	else{
		return false;
	}
}

int generate(int time, int low, int high, int muldiv, int frac, int par){
	int integer1, integer2;
	vector<string>str;//str用来保存生成的题目
	int ch1, ch2, ch3, ch4;//switch语句的选项
	char sign;//运算符号
	int right1 = 0,wrong=0;
	for (int i = 1; i <= time;){
		int start = 1;//start用来标记算式是否是刚开始生成
		string first, second;//四则运算的第一个运算数，第二个运算数
		string cal;
		int num = ran(1, 9)+1;//num为参与运算的参数个数
		for (int j = 1; j < num;){
			//-------------------------------------------------------
			if (muldiv == 1){//允许乘除
				ch1 = ran(1, 4);//随机生成运算符号
				switch (ch1){
				case 1:sign = '+'; break;
				case 2:sign = '-'; break;
				case 3:sign = '*'; break;
				case 4:sign = '/'; break;
				default:cout << "Have bug!" << endl; break;
				}
			}
			else{//不允许乘除
				ch1 = ran(1, 2);
				switch (ch1){
				case 1:sign = '+'; break;
				case 2:sign = '-'; break;
				default:cout << "Have bug!" << endl; break;
				}
			}
			//-------------------------------------------------------
			if (frac == 1){//算式中有分数
				ch2 = ran(1, 3);//四则运算题目的三种情况
				switch (ch2){
				case 1:{//整数和整数
						   stringstream si, so;
						   integer1 = ran(low, high);
						   integer2 = ran(low, high);
						   si << integer1; si >> first;
						   so << integer2; so >> second;
				}break;
				case 2:{//整数和分数
						   stringstream si;
						   integer1 = ran(low, high);
						   si << integer1; si >> first;
						   Fraction f = reduction(reafra(low, high));
						   second = '[' + f.high + "\\" + f.low + ']';
				}break;
				case 3:{//分数和分数
						   Fraction f1 = reduction(reafra(low, high));
						   Fraction f2 = reduction(reafra(low, high));
						   first = "[" + f1.high + "\\" + f1.low + "]";
						   second = "[" + f2.high + "\\" + f2.low + "]";
				}break;
				default:cout << "有错误！" << endl; break;
				}
			}
			else{//不允许真分数参与运算
				stringstream si, so;
				integer1 = ran(low, high);
				si << integer1; si >> first;
				integer2 = ran(low, high);
				so << integer2; so >> second;
			}
			//-------------------------------------------------------
			if (par == 1){//允许带括号
				ch2 = ran(1, 4);
				switch (ch2){
				case 1:{
						   if (start == 1){//start为1表示算式还未生成前两个运算数
							   cal = first + sign + second;
							   start = 0;
						   }
						   else{
							   cal = cal + sign + first;//将已经生成的算式和新生成的运算数相连
						   }
				}break;
				case 2:{
						   if (start == 1){
							   cal = second + sign + first;
							   start = 0;
						   }
						   else{
							   cal = second + sign + cal;
						   }
				}break;
				case 3:{
						   if (start == 1){
							   cal = '(' + first + sign + second + ')';//添加括号的情况
							   start = 0;
						   }
						   else{
							   cal = '(' + cal + sign + first + ')';
						   }
				}break;
				case 4:{
						   if (start == 1){
							   cal = '(' + second + sign + first + ')';
							   start = 0;
						   }
						   else{
							   cal = '(' + second + sign + cal + ')';
						   }
				}break;
				default:cout << "Have bug!" << endl; break;
				}
			}
			else//不允许括号参与运算
			{
				ch4 = ran(1, 2);//输出的两种情况
				switch (ch4)
				{
				case 1:
				{
						  if (start == 1)
						  {
							  cal = first + sign + second;
							  start = 0;
						  }
						  else
						  {
							  cal = cal + sign + first;
						  }
				}break;
				case 2:
				{
						  if (start == 1)
						  {
							  cal = second + sign + first;
							  start = 0;
						  }
						  else
						  {
							  cal = second + sign + cal;
						  }
				}break;
				default:cout << "有错误！" << endl; break;
				}
			}
			j++;
		}
		//-------------------------------------------------------------
		if (str.empty()){//vector str,若str为空，添加第一个运算式到vector中
			str.push_back(cal);
			cout << "(" << i << ") " << cal << "=";

			string answer;
			cin >> answer;
			char postexp[maxsize];
			trans(cal, postexp);
			Fraction re = calculate(postexp);
			string result = FraToString(re);
			if (answer == result){
				cout << "正确！你真棒！" << endl;
				right1++;
			}
			else{
				cout << "错误！加油哦~" << endl << "正确的答案为：" << result << endl;
				wrong++;
			}
			i++;
		}
		if (is_unique(cal, str)){//判断生成的算式和之前已经生成的运算式是否重复
			str.push_back(cal);//将生成的运算式添加到str中
			cout << "(" << i << ") " << cal << "=";

			string answer;
			cin >> answer;
			char postexp[maxsize];
			trans(cal, postexp);
			Fraction re = calculate(postexp);
			string result = FraToString(re);
			if (answer == result){
				cout << "正确！你真棒！" << endl;
				right1++;
			}
			else{
				cout << "错误！加油哦~" << endl << "正确的答案为：" << result << endl;
				wrong++;
			}
			i++;
		}
		else{}
	}
	cout << "****************************************************************************" << endl;
	cout << "你做对了" << right1 << "道题，做错了" << wrong << "道题"<<endl;
	cout << "是否重新出题？(y/n)";
	char yn; int restart;//再次出题
	cin >> yn;
	yn == 'y' || yn == 'Y' ? restart = 1 : restart = 0;
	return restart;
}