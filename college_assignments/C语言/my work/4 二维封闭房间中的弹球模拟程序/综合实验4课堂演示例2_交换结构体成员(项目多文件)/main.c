#include "EXP4_structMultifile.h"  //��Ŀ������.c�ļ��ж����������ͷ�ļ�

/*
  main()���ļ���ֻ����������塢���û��Ľ���(�������������)��
  �Լ����ֹ����Զ��庯���ĵ���
*/
int main() {
  struct Person leader[N]={ {"Li", 3},
                            {"Zhang",10},
                            {"Sun",0}};
  if (leader[0].points < leader[1].points)
    swap(&leader[0].points, &leader[1].points);
  printf("Li:%d, Zhang: %d\n", leader[0].points, leader[1].points);
  return 0;
}
