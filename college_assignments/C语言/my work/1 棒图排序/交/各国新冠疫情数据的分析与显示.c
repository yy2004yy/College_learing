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
	int patient_max, recovery_max, recoveryRatio_max;//每一个即存放对应数据的最大值 
	double t;//作为中间变量存放数据，便于交换 
	int number[51] ;//序号 
	char country[51][12] = {"美国", "西班牙", "意大利", "德国", "法国", "中国", "伊朗", "英国", "土耳其", "瑞士", "比利时", "荷兰", "加拿大", "奥地利", "巴西", "葡萄牙", "南韩", "以色列", "瑞典", "俄罗斯", "澳大利亚", "挪威", "爱尔兰", "捷克", "智利", "印度", "丹麦", "波兰", "罗马尼亚", "日本", "巴基斯坦", "马来西亚", "厄瓜多尔", "菲律宾", "卢森堡", "沙地阿拉伯", "秘鲁", "印度尼西亚", "墨西哥", "泰国", "塞尔维亚", "芬兰", "巴拿马", "阿联酋", "卡塔尔", "多米尼加", "希腊", "南非", "阿根廷", "哥伦比亚", "冰岛"};//注意一个汉字占用两个字符 
	double patient[51] = {367650, 136675, 132675, 103375, 98010, 81740, 60500, 51608, 30217, 21657, 20814, 18803, 16667, 12332, 12232, 11730, 10331, 8904, 7206, 6343, 5908, 5865, 5364, 4828, 4815, 4778, 4681, 4413, 4057, 3906, 3864, 3793, 3747, 3660, 2843, 2605, 2561, 2491, 2439, 2258, 2200, 2176, 2100, 2076, 1832, 1828, 1755, 1686, 1628, 1562, 1562};//确诊人数 
	double recovery[51] = {19810, 40437, 22837, 36081, 17250, 77167, 24236, 135, 1326, 8056, 3986, 250, 3616, 3463, 127, 140, 6694, 585, 205, 406, 2547, 32, 25, 127, 728, 382, 1378, 162, 406, 592, 429, 1241, 100, 73, 500, 551, 997, 192, 633, 824, 118, 300, 14, 167, 131, 33, 269, 95, 325, 88, 460};//治愈人数 
	double recoveryRatio[51];//治愈率 
	int star[51];//此数据对应棒图里的星星数 
	
	for(i = 0; i < 51; i++)
	number[i] = i + 1;//对每一个国家安排好序号 
	for(i = 0; i < 51; i++)
	recoveryRatio[i] =(recovery[i] / patient[i])*100;//治愈率 = 治愈人数 / 确诊人数	
	printf("序号\t   国家\t     确诊人数\t治愈人数\t治愈率\n");
	for(i = 0; i < 51; i++)
	printf("%2d%13s%12.0lf%12.0lf%14.2lf%%\n", number[i],country[i], patient[i], recovery[i],recoveryRatio[i]);
	
	printf("\n\n");
	
	for(i = 1; i < 51; i++)//用"冒泡排序算法 "对上面的数据按照确诊人数由多到少的顺序排序
	{
		flag = 0;
		for(j = 0; j < 51 - i; j++)
			if(patient[j] < patient[j+1])//如果数据较小则到后面去 
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
			
				for(k = 0; k <= 11; k++)//对二维数组进行数值交换需要利用“循环 ”来对列元素进行交换 
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
	printf("序号\t确诊人数\t国家\t  治愈人数\t 治愈率\t  （确诊人数）数据棒图\n");
	for(i = 0; i < 51; i++)
	{
	printf("%2d%13.0lf%13s%12.0lf%14.2lf%%    ", number[i],  patient[i], country[i], recovery[i],recoveryRatio[i]);
	star[i] = (patient[i]*40)/patient_max;	
	printf_star(star[i]);
	}
	
	printf("\n\n");

	for(i = 0; i < 50; i++)	// 用 选择排序算法 对上面的数据按照治愈人数由多到少的顺序排序
	{
		g = i;//g为当前“擂主”的下标； 
		for(j = i + 1; j < 51; j++)
			if(recovery[g] < recovery[j]) g = j;//如果数据较小则到后面去 
			
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
	printf("序号\t治愈人数\t国家\t确诊人数\t治愈率\t （治愈人数）数据棒图\n");
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
		for(j = i + 1; j < 51; j++)//用 选择排序算法 对上面的数据按照治愈率由大到小的顺序排序
			if(recoveryRatio[g] < recoveryRatio[j])  g = j;//如果数据较小则到后面去 
			
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
					country[i][k] = country[g][k];//对后一行元素进行换互换，每一次互换列元素依次后移一位 
					country[g][k] = t;
				}

				t = number[g];
				number[g] = number[i];
				number[i] = t;
			}	
	}
	recoveryRatio_max = recoveryRatio[0];
	printf("序号\t治愈率\t   国家\t     确诊人数\t   治愈人数\t （治愈率）数据棒图\n");
	for(i = 0; i < 51; i++)
	{
	printf("%2d%10.2lf%%%11s%13.0lf%12.0lf        ", number[i], recoveryRatio[i], country[i], patient[i], recovery[i]);
	star[i] = (recoveryRatio[i]*40)/recoveryRatio_max;	
	printf_star(star[i]);
	}
	
}

