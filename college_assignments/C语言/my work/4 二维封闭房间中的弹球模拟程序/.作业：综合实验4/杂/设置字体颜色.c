#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int main(void) {int i;
HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��������ڵľ��(Handle to a WiNdoW)
SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_RED); //���������������ɫ
printf("Hello o o o ");
Sleep(2000); //�ӳ� 2000 ����
SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_GREEN);//���������������ɫ
printf("World!\n");
for(i=0; i<80; i++) printf("%d", i % 10); putchar('\n'); //��ʾһ�´��ں��� X ����
for(i=2; i<24; i++) printf("%d\n", i); //��ʾһ�´������� Y ����
/* ����̨���ڻ�����ֱ��ʹ��������������ɫ����Ӧֵ��
0=��ɫ��1=��ɫ��2=��ɫ��3=����ɫ��4=��ɫ��5=��ɫ��6=��ɫ��7=��ɫ��8=��ɫ��9=����ɫ
10=����ɫ 0xa��11=����ɫ 0xb��12=����ɫ 0xc��13=����ɫ 0xd��14=����ɫ 0xe��15=����ɫ 0xf */
SetConsoleTextAttribute(consolehwnd, 14); //��������ڵ�����ɫ
//������ʾ�ڴ��ڵ�����ָ�����괦��ʾ�ַ����ַ���
COORD coord; //ע�� coord �� X��Y ��������Ƕ���Ķ�ά�ַ����� cWin[][]���С����Ƿ���
//������ڵ������Ͻ�����Ϊ(0, 0)
coord.X = rand() % 80; //coord.X �Ǵ����ҵĺ������꣬coord.X = (ball+i)->wY
coord.Y = rand() % 24; //coord.Y �Ǵ��ϵ��µ��������꣬coord.Y = (ball+i)->wX
printf("coord.X=%2d coord.Y=%2d\n", coord.X, coord.Y);
SetConsoleCursorPosition(consolehwnd, coord);
putchar('o');//ռ��һ���ַ����
SetConsoleTextAttribute(consolehwnd, 13); //��������ڵ�����ɫ
puts("��"); //�����ķǱ�׼ ASCII �������ռ�������ַ����
SetConsoleTextAttribute(consolehwnd, 7); //�л���Ĭ�ϵĺڵװ�ɫ����
}
