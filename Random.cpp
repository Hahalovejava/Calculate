#include "head.h"



int flag = 1;
int ran(int down, int up){      //�������1��n������
	if (flag){
		flag = 0;
		srand((unsigned)time(NULL));
	}
	int result = random(down, up);
	return result;
}

bool is_unique(string str, vector<string>s){ //�ж����ɵ���ʽ�Ƿ����
	int count = 0;
	for (int i = 0; i < s.size(); i++){
		if (str != s[i]){
			count++;
		}
		else break;
	}
	if (count == s.size()){
		return true;    //���ɵ���ʽ�Ƕ��ص�
	}
	else{
		return false;
	}
}

int generate(int time, int low, int high, int muldiv, int frac, int par){
	int integer1, integer2;
	vector<string>str;//str�����������ɵ���Ŀ
	int ch1, ch2, ch3, ch4;//switch����ѡ��
	char sign;//�������
	int right1 = 0,wrong=0;
	for (int i = 1; i <= time;){
		int start = 1;//start���������ʽ�Ƿ��Ǹտ�ʼ����
		string first, second;//��������ĵ�һ�����������ڶ���������
		string cal;
		int num = ran(1, 9)+1;//numΪ��������Ĳ�������
		for (int j = 1; j < num;){
			//-------------------------------------------------------
			if (muldiv == 1){//����˳�
				ch1 = ran(1, 4);//��������������
				switch (ch1){
				case 1:sign = '+'; break;
				case 2:sign = '-'; break;
				case 3:sign = '*'; break;
				case 4:sign = '/'; break;
				default:cout << "Have bug!" << endl; break;
				}
			}
			else{//������˳�
				ch1 = ran(1, 2);
				switch (ch1){
				case 1:sign = '+'; break;
				case 2:sign = '-'; break;
				default:cout << "Have bug!" << endl; break;
				}
			}
			//-------------------------------------------------------
			if (frac == 1){//��ʽ���з���
				ch2 = ran(1, 3);//����������Ŀ���������
				switch (ch2){
				case 1:{//����������
						   stringstream si, so;
						   integer1 = ran(low, high);
						   integer2 = ran(low, high);
						   si << integer1; si >> first;
						   so << integer2; so >> second;
				}break;
				case 2:{//�����ͷ���
						   stringstream si;
						   integer1 = ran(low, high);
						   si << integer1; si >> first;
						   Fraction f = reduction(reafra(low, high));
						   second = '[' + f.high + "\\" + f.low + ']';
				}break;
				case 3:{//�����ͷ���
						   Fraction f1 = reduction(reafra(low, high));
						   Fraction f2 = reduction(reafra(low, high));
						   first = "[" + f1.high + "\\" + f1.low + "]";
						   second = "[" + f2.high + "\\" + f2.low + "]";
				}break;
				default:cout << "�д���" << endl; break;
				}
			}
			else{//�������������������
				stringstream si, so;
				integer1 = ran(low, high);
				si << integer1; si >> first;
				integer2 = ran(low, high);
				so << integer2; so >> second;
			}
			//-------------------------------------------------------
			if (par == 1){//���������
				ch2 = ran(1, 4);
				switch (ch2){
				case 1:{
						   if (start == 1){//startΪ1��ʾ��ʽ��δ����ǰ����������
							   cal = first + sign + second;
							   start = 0;
						   }
						   else{
							   cal = cal + sign + first;//���Ѿ����ɵ���ʽ�������ɵ�����������
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
							   cal = '(' + first + sign + second + ')';//������ŵ����
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
			else//���������Ų�������
			{
				ch4 = ran(1, 2);//������������
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
				default:cout << "�д���" << endl; break;
				}
			}
			j++;
		}
		//-------------------------------------------------------------
		if (str.empty()){//vector str,��strΪ�գ���ӵ�һ������ʽ��vector��
			str.push_back(cal);
			cout << "(" << i << ") " << cal << "=";

			string answer;
			cin >> answer;
			char postexp[maxsize];
			trans(cal, postexp);
			Fraction re = calculate(postexp);
			string result = FraToString(re);
			if (answer == result){
				cout << "��ȷ���������" << endl;
				right1++;
			}
			else{
				cout << "���󣡼���Ŷ~" << endl << "��ȷ�Ĵ�Ϊ��" << result << endl;
				wrong++;
			}
			i++;
		}
		if (is_unique(cal, str)){//�ж����ɵ���ʽ��֮ǰ�Ѿ����ɵ�����ʽ�Ƿ��ظ�
			str.push_back(cal);//�����ɵ�����ʽ��ӵ�str��
			cout << "(" << i << ") " << cal << "=";

			string answer;
			cin >> answer;
			char postexp[maxsize];
			trans(cal, postexp);
			Fraction re = calculate(postexp);
			string result = FraToString(re);
			if (answer == result){
				cout << "��ȷ���������" << endl;
				right1++;
			}
			else{
				cout << "���󣡼���Ŷ~" << endl << "��ȷ�Ĵ�Ϊ��" << result << endl;
				wrong++;
			}
			i++;
		}
		else{}
	}
	cout << "****************************************************************************" << endl;
	cout << "��������" << right1 << "���⣬������" << wrong << "����"<<endl;
	cout << "�Ƿ����³��⣿(y/n)";
	char yn; int restart;//�ٴγ���
	cin >> yn;
	yn == 'y' || yn == 'Y' ? restart = 1 : restart = 0;
	return restart;
}