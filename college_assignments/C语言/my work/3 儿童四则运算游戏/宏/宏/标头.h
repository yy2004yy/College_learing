
/**
 * @author: 2022280575 Zhao-hong Zhou
 * @description:random numbers,bar charts,selection structure,cycle control and interactive I/O
 * @version: v0.01
 * @date: 2022-12-03 10:10:10
 **/
#include<iostream>
#include<time.h>
using namespace std;
//#include<stdlib.h>
//#include<conio.h>
//����������ĺ���
int randN1N2(int N1, int N2) {
	int r = 0;
	if (N1 <= N2) {
		srand((unsigned int)time(NULL));
		r = rand() % (N2 - N1 + 1) + N1;
	}
	return r;
}
//������� ��+���� ��-���� ��*���� ��/�� ���ĸ��ַ�������һ��
char randOperator() {
	char Operator = 0;
	int r = randN1N2(1, 4);
	switch (r) {
	case 1:Operator = '+'; break;
	case 2:Operator = '-'; break;
	case 3:Operator = '*'; break;
	case 4:Operator = '/'; break;
	}
	return Operator;
}
//����0~99�������
int randLmt100() {
	return randN1N2(0, 99);
}
//�ӷ�����
int addLmt100(int num1, int num2) {
	printf("%d + %d=", num1, num2);
	int a = 0;
	scanf_s("%d", &a);
	if (a == num1 + num2) {
		printf("\n��ϲ�����ˣ��ٽ�������\n");
		return 1;
	}
	else {
		printf("���ź���û�д�ԣ���Ҫ���٣����ͣ�\n��ȷ���ǣ�%d\n", num1 + num2);
		return 0;
	}
}
//��������
int subLmt100(int num1, int num2) {
	int numMin = num1, numMax = num2;
	if (num1 > num2) {
		int t = numMin;
		numMin = numMax;
		numMax = t;
	}
	printf("%d - %d=", numMax, numMin);
	int a = 0;
	scanf_s("%d", &a);
	if (a == numMax - numMin) {
		printf("\n��ϲ�����ˣ��ٽ�������\n");
		return 1;
	}
	else {
		printf("���ź���û�д�ԣ���Ҫ���٣����ͣ�\n��ȷ���ǣ�%d\n", numMax - numMin);
		return 0;
	}
}
//�˷�����
int mulLmt100(int num1, int num2) {
	printf("%d �� %d=", num1, num2);
	int a = 0;
	scanf_s("%d", &a);
	if (a == num1 * num2) {
		printf("\n��ϲ�����ˣ��ٽ�������\n");
		return 1;
	}
	else {
		printf("���ź���û�д�ԣ���Ҫ���٣����ͣ�\n��ȷ���ǣ�%d\n", num1 * num2);
		return 0;
	}
}
//��������
int divLmt100() {
	int num1 = 0, num2 = 0;
	do {
		num1 = randLmt100();
		num2 = randLmt100();
	} while (num1 < num2 || num1 % num2 != 0);
	printf("%d / %d=", num1, num2);
	int a = 0;
	scanf_s("%d", &a);
	if (a == num1 / num2) {
		printf("\n��ϲ�����ˣ��ٽ�������\n");
		return 1;
	}
	else {
		printf("���ź���û�д�ԣ���Ҫ���٣����ͣ�\n��ȷ���ǣ�%d\n", num1 / num2);
		return 0;
	}
}

int main() {
	int probNum[4] = { 0 }, ansNum[4] = { 0 },sFlag=1;
	while (sFlag == 1){
		printf("**********��������С��Ϸ**********\n");
		char oper = randOperator();
		int n1 = 0, n2 = 0;
		n1 = randLmt100();
		n2 = randLmt100();
		switch (oper) {
		case '+':
			probNum[0]++;
			ansNum[0] += addLmt100(n1, n2);
			break;
		case '-':
			probNum[1]++;
			ansNum[1] += subLmt100(n1, n2);
			break;
		case '*':
			probNum[2]++;
			ansNum[2] += mulLmt100(n1, n2);
			break;
		case '/':
			probNum[3]++;
			ansNum[3] += divLmt100();
			break;
		}
		printf("���������\n�����������밴Y�������밴N\n");
		fflush(stdin);
		char c= getch();
		if (c == 'n' || c == 'N')
			break;
			else
			system("pause");
			system("cls");
	} 
	int r1 = randLmt100();
	int r2 = randLmt100();
	printf("r1=%d,r2=%d", r1, r2);
	/*printf("���δ��⹲����%d��������,\n�ӷ�%d�������%d����\n����%d�������%d����\n�˷�%d�������%d����\n����%d�������%d����\n", probNum[0]+probNum[1]+probNum[2]+probNum[3],probNum[0], ansNum[0],probNum[1], ansNum[1], probNum[2], ansNum[2],probNum[3], ansNum[3]);
	printf("��ȥ��Ҫ�ú�ѧϰŶ���ټ���");*/
	return 0;
}
