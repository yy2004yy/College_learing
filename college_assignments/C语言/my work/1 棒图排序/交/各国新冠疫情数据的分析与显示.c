/**
 * @author: 2022280380 Ye Yang
 * @description: Analysis and display of COVID-19 data in various countries
 * @version: v0.01
 * @date: 2020-04-07 15:50:50 
 **/ 
#include <stdio.h>

void printf_star(int a)
{
	int i, star[50];
	for(i = 0; i < a; i++)
	{
	star[i] = '*';
	printf("%c", star[i]);
	}
	printf("\n");
	star[a] = '\0';
}

int main ()
{
	int i, j, flag, k, g;
	int patient_max, recovery_max, recoveryRatio_max;//ÿһ������Ŷ�Ӧ���ݵ����ֵ 
	double t;//��Ϊ�м����������ݣ����ڽ��� 
	int number[51] ;//��� 
	char country[51][12] = {"����", "������", "�����", "�¹�", "����", "�й�", "����", "Ӣ��", "������", "��ʿ", "����ʱ", "����", "���ô�", "�µ���", "����", "������", "�Ϻ�", "��ɫ��", "���", "����˹", "�Ĵ�����", "Ų��", "������", "�ݿ�", "����", "ӡ��", "����", "����", "��������", "�ձ�", "�ͻ�˹̹", "��������", "��϶��", "���ɱ�", "¬ɭ��", "ɳ�ذ�����", "��³", "ӡ��������", "ī����", "̩��", "����ά��", "����", "������", "������", "������", "�������", "ϣ��", "�Ϸ�", "����͢", "���ױ���", "����"};//ע��һ������ռ�������ַ� 
	double patient[51] = {367650, 136675, 132675, 103375, 98010, 81740, 60500, 51608, 30217, 21657, 20814, 18803, 16667, 12332, 12232, 11730, 10331, 8904, 7206, 6343, 5908, 5865, 5364, 4828, 4815, 4778, 4681, 4413, 4057, 3906, 3864, 3793, 3747, 3660, 2843, 2605, 2561, 2491, 2439, 2258, 2200, 2176, 2100, 2076, 1832, 1828, 1755, 1686, 1628, 1562, 1562};//ȷ������ 
	double recovery[51] = {19810, 40437, 22837, 36081, 17250, 77167, 24236, 135, 1326, 8056, 3986, 250, 3616, 3463, 127, 140, 6694, 585, 205, 406, 2547, 32, 25, 127, 728, 382, 1378, 162, 406, 592, 429, 1241, 100, 73, 500, 551, 997, 192, 633, 824, 118, 300, 14, 167, 131, 33, 269, 95, 325, 88, 460};//�������� 
	double recoveryRatio[51];//������ 
	int star[51];//�����ݶ�Ӧ��ͼ��������� 
	
	for(i = 0; i < 51; i++)
	number[i] = i + 1;//��ÿһ�����Ұ��ź���� 
	for(i = 0; i < 51; i++)
	recoveryRatio[i] =(recovery[i] / patient[i])*100;//������ = �������� / ȷ������	
	printf("���\t   ����\t     ȷ������\t��������\t������\n");
	for(i = 0; i < 51; i++)
	printf("%2d%13s%12.0lf%12.0lf%14.2lf%%\n", number[i],country[i], patient[i], recovery[i],recoveryRatio[i]);
	
	printf("\n\n");
	
	for(i = 1; i < 51; i++)//��"ð�������㷨 "����������ݰ���ȷ�������ɶൽ�ٵ�˳������
	{
		flag = 0;
		for(j = 0; j < 51 - i; j++)
			if(patient[j] < patient[j+1])//������ݽ�С�򵽺���ȥ 
			{
				t = patient[j];
				patient[j] = patient[j+1];
				patient[j+1] = t;
			
				t = recovery[j];
				recovery[j] = recovery[j+1];
				recovery[j+1] = t;
			
				t = recoveryRatio[j];
				recoveryRatio[j] = recoveryRatio[j+1];
				recoveryRatio[j+1] = t;
			
				for(k = 0; k <= 11; k++)//�Զ�ά���������ֵ������Ҫ���á�ѭ�� ��������Ԫ�ؽ��н��� 
				{
					t = country[j][k];
					country[j][k] = country[j+1][k];
					country[j+1][k] = t;
				}
				
				t = number[j];
				number[j] = number[j+1];
				number[j+1] = t;
				
				flag = 1;
			}
			
		if(flag == 0) break;
	}
	patient_max = patient[0];
	printf("���\tȷ������\t����\t  ��������\t ������\t  ��ȷ�����������ݰ�ͼ\n");
	for(i = 0; i < 51; i++)
	{
	printf("%2d%13.0lf%13s%12.0lf%14.2lf%%    ", number[i],  patient[i], country[i], recovery[i],recoveryRatio[i]);
	star[i] = (patient[i]*40)/patient_max;	
	printf_star(star[i]);
	}
	
	printf("\n\n");

	for(i = 0; i < 50; i++)	// �� ѡ�������㷨 ����������ݰ������������ɶൽ�ٵ�˳������
	{
		g = i;//gΪ��ǰ�����������±ꣻ 
		for(j = i + 1; j < 51; j++)
			if(recovery[g] < recovery[j]) g = j;//������ݽ�С�򵽺���ȥ 
			
			if( g != i)
			{
				t = patient[g];
				patient[g] = patient[i];
				patient[i] = t;
			
				t = recovery[g];
				recovery[g] = recovery[i];
				recovery[i] = t;
			
				t = recoveryRatio[g];
				recoveryRatio[g] = recoveryRatio[i];
				recoveryRatio[i] = t;
			
				for(k = 0; k <= 11; k++)
				{
					t = country[i][k];
					country[i][k] = country[g][k];
					country[g][k] = t;
				}
				
				t = number[g];
				number[g] = number[i];
				number[i] = t;
			}
	}
	recovery_max = recovery[0];
	printf("���\t��������\t����\tȷ������\t������\t ���������������ݰ�ͼ\n");
	for(i = 0; i < 51; i++)
	{
	printf("%2d%12.0lf%14s%11.0lf%14.2lf%%   ", number[i], recovery[i], country[i], patient[i], recoveryRatio[i]);
	star[i] = (recovery[i]*40)/recovery_max;	
	printf_star(star[i]);
	}
	
	printf("\n\n");
	for(i = 0; i < 50; i++)
	{
		g = i;
		for(j = i + 1; j < 51; j++)//�� ѡ�������㷨 ����������ݰ����������ɴ�С��˳������
			if(recoveryRatio[g] < recoveryRatio[j])  g = j;//������ݽ�С�򵽺���ȥ 
			
			if( g != i)
			{
				t = patient[g];
				patient[g] = patient[i];
				patient[i] = t;
			
				t = recovery[g];
				recovery[g] = recovery[i];
				recovery[i] = t;
			
				t = recoveryRatio[g];
				recoveryRatio[g] = recoveryRatio[i];
				recoveryRatio[i] = t;
			
				for(k = 0; k <= 11; k++)
				{
					t = country[i][k];
					country[i][k] = country[g][k];//�Ժ�һ��Ԫ�ؽ��л�������ÿһ�λ�����Ԫ�����κ���һλ 
					country[g][k] = t;
				}

				t = number[g];
				number[g] = number[i];
				number[i] = t;
			}	
	}
	recoveryRatio_max = recoveryRatio[0];
	printf("���\t������\t   ����\t     ȷ������\t   ��������\t �������ʣ����ݰ�ͼ\n");
	for(i = 0; i < 51; i++)
	{
	printf("%2d%10.2lf%%%11s%13.0lf%12.0lf        ", number[i], recoveryRatio[i], country[i], patient[i], recovery[i]);
	star[i] = (recoveryRatio[i]*40)/recoveryRatio_max;	
	printf_star(star[i]);
	}
	
}

