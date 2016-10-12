#include"head.h"

int max(int a, int b){
	if (a > b){
		return a;
	}
	else return b;
}

int min(int a, int b){
	if (a < b){
		return a;
	}
	else return b;
}

int greatest_common_divisor(int a, int b){//��a,b���Լ��
	if (b == 0)return a;
	else {
		int yushu = 0;

		a = max(a, b);
		b = min(a, b);

		yushu = a % b;
		while (yushu != 0){
			a = b;
			b = yushu;
			yushu = a % b;
		}
		return b;
	}
}

Fraction gener(int up, int down){//���ɷ���
	Fraction result;
	result.up = up;
	result.down = down;
	stringstream s1, s2;
	s1 << result.up; s1 >> result.high;
	s2 << result.down; s2 >> result.low;
	return result;
}

Fraction reafra(int d, int u){//������ɷ���
	Fraction result;
	result.up = ran(d, u);
	result.down = ran(d, u);
	if (result.down == 0){
		while (result.down != 0){
			ran(d, u);
		}
	}
	stringstream s1, s2;
	s1 << result.up; s1 >> result.high;
	s2 << result.down; s2 >> result.low;
	return result;
}

Fraction reduction(Fraction n1){//����Լ��
	if (n1.up == 0){
		n1.down = 1;
	}
	else{
		int divisor;//���Լ��
		divisor = greatest_common_divisor(n1.up, n1.down);
		n1.up /= divisor;
		n1.down /= divisor;
	}
	stringstream s1, s2;
	s1 << n1.up; s1 >> n1.high;
	s2 << n1.down; s2 >> n1.low;
	return n1;
}

Fraction add(Fraction n1, Fraction n2){//�����ӷ�
	Fraction re;
	re.down = n1.down * n2.down;
	re.up = n1.up * n2.down + n2.up * n1.down;
	re = reduction(re);
	return re;
}

Fraction minus1(Fraction n1, Fraction n2){//��������
	Fraction re;
	re.down = n1.down * n2.down;
	re.up = n1.up * n2.down - n2.up * n1.down;
	re = reduction(re);
	return re;
}

Fraction mul(Fraction n1, Fraction n2){//�����˷�
	Fraction re;
	re.down = n1.down * n2.down;
	re.up = n1.up * n2.up;
	re = reduction(re);
	return re;
}

Fraction div(Fraction n1, Fraction n2){//��������
	Fraction re;
	re.up = n1.up*n2.down;
	re.down = n1.down*n2.up;
	re = reduction(re);
	return re;
}

void print_frac(Fraction f){//�������
	f = reduction(f);
	if (f.down == 1){
		cout << f.up;
	}
	else{
		cout << f.up << "\\" << f.down;
	}
}

string FraToString(Fraction f){
	string result;
	if (f.down == 1){
		result = f.high;
	}
	else{
		result = f.high + "\\" + f.low;
	}
	return result;
}
