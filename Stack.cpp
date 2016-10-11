#include "head.h"


struct{
	char data[maxsize];//��������
	int top;//ջ��ָ��
}op;//���������ջ

void trans(string exp, char postexp[]){//exp[]Ϊ��׺���ʽ,postexp[]Ϊ��׺���ʽ
	char ch;
	int i = 0, j = 0;//i��Ϊexp���±꣬j��Ϊpostexp���±�
	op.top = -1;
	ch = exp[i];
	i++;
	while (ch != '\0'){//exp���ʽ��βĬ�ϱ�־'\0'
		switch (ch){
		case '(':{//�ж�Ϊ������
					 op.top++;
					 op.data[op.top] = ch;
		}break;
		case ')':{//�ж�Ϊ�����ţ���'('֮ǰ����������γ�ջ�ŵ�postexp��
					 while (op.data[op.top] != '('){
						 postexp[j] = op.data[op.top];
						 j++;
						 op.top--;
					 }
					 op.top--;//������������
		}break;
		case '+'://��+����-��,���ȼ���ͣ�ֱ����(��Ϊֹ
		case '-':{
					 while (op.top != -1 && op.data[op.top] != '('){
						 postexp[j] = op.data[op.top];
						 j++;
						 op.top--;
					 }
					 op.top++;
					 op.data[op.top] = ch;
		}break;
		case '*':
		case '/':{
					 while (op.top != -1 && op.data[op.top] != '[' && (op.data[op.top] == '*' || op.data[op.top] == '/')){
						 postexp[j] = op.data[op.top];
						 j++;
						 op.top--;
					 }
					 op.top++;
					 op.data[op.top] = ch;
		}break;
		case ' ':break;//���˵��ո�
		case '[':{//����������һ������ŵ�postexp��
					 while (ch != ']'){
						 postexp[j] = ch;
						 j++;
						 ch = exp[i];
						 i++;
					 }
					 postexp[j] = ch; j++;//����]���ŵ�postexp��
		}break;
		default:{
					while (ch >= '0'&&ch <= '9'){//�ж�Ϊ����
						postexp[j] = ch;
						j++;
						ch = exp[i];
						i++;
					}
					i--;
					postexp[j] = '#';//��#��ʾһ����ֵ�Ľ���
					j++;
		}
		}
		ch = exp[i];
		i++;
	}
	while (op.top != -1){//��ʱexpɨ����ɣ�ջ����ʱ����ջ���ŵ�postexp��
		postexp[j] = op.data[op.top];
		j++;
		op.top--;
	}
	postexp[j] = '\0';//��postexp���ʽ��ӽ�����ʶ
}

struct{
	Fraction data[maxsize];//�����ֵ
	int top;//ջ��ָ��
}st;

Fraction calculate(char postexp[]){//�����׺���ʽ��ֵ
	double d;
	char ch;
	int i = 0;//postexp���±�
	st.top = -1;
	ch = postexp[i];
	i++;
	while (ch != '\0'){//postexp�ַ���δ����
		switch (ch){
		case '+':{
					 st.data[st.top - 1] = add(st.data[st.top - 1], st.data[st.top]);
					 st.top--;
		}break;
		case '-':{
					 st.data[st.top - 1] = minus1(st.data[st.top - 1], st.data[st.top]);
					 st.top--;
		}break;
		case'*':
		{
				   st.data[st.top - 1] = mul(st.data[st.top - 1], st.data[st.top]);
				   st.top--;
		}break;
		case'/':
		{
				   st.data[st.top - 1] = div(st.data[st.top - 1], st.data[st.top]);
				   st.top--;
		}break;
		case '[':{
					 double high = 0, low = 0;
					 ch = postexp[i]; i++;//ɾ����['
					 while (ch != '\\'){
						 high = 10 * high + ch - '0';
						 ch = postexp[i];
						 i++;
					 }
					 ch = postexp[i]; i++;//ɾ����\'
					 while (ch != ']'){
						 low = 10 * low + ch - '0';
						 ch = postexp[i];
						 i++;
					 }
					 st.top++;
					 Fraction re = gener(high, low);
					 st.data[st.top] = re;
		}break;
		default:{
					d = 0;
					while (ch >= '0'&&ch <= '9'){//�������ַ�ת��Ϊ��Ӧ����ֵ��ŵ�d��
						d = 10 * d + ch - '0';
						ch = postexp[i];
						i++;
					}
					st.top++;
					Fraction re = gener(d, 1);
					st.data[st.top] = re;
		}
		}
		ch = postexp[i];
		i++;
	}
	return st.data[st.top];
}
