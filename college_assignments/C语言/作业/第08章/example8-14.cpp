#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define N  200

void beep( );
void GetPassage(char str[ ]); 
void WordSepa(char str[ ], char word[ ][20]);
void SaveWord(char wordstr[ ], char word[ ][20]);
void SortWord(char word[ ][20]); 
void ShowWord(char word[][20]);

int main()
{
  char text[N+1], word[50][20] = {0};
  
  GetPassage(text);
  WordSepa(text, word);
  SortWord(word);
  ShowWord(word);
  return 0;
}

//����
void beep( )
{
  printf("\07");
}

//��ȡӢ�Ķ��ġ�
void GetPassage(char str[]) 
{
  int i = 0;
  char ch;
  
  while ( 1 )
  {
    ch = getch( );     //��ȡ������ַ�������ʾ
    if (ch == '\r')    //�س������˳�  
       break;
    if (ch == '\b')    //�˸��
    {
      if (i > 0)  
      {  
        printf ("%c %c", ch, ch);
        i--;
      }
      else
        beep ( );
      continue;
    }  //if
    if (!isalpha(ch) && ch != ',' && ch != '.' && ch != ' ')   //����ĸ�����š���š��ո�
    {
      beep( );
      continue;
    }
    if (i < N)   //��ĸ�����š���š��ո�
    {
      printf ("%c", ch);
      str[i++] = ch;
    }
    else
      beep ( );
  }  //while (1)
  str[i] = '\0';  //���ַ���������־
}

//���ʷֽ⡣        
void WordSepa(char str[], char word[][20])
{
  int i, j;
  char wordstr[20];

  for (i = 0; str[i] != '\0'; )
  {
    if (!isalpha(str[i]))
	{
	  i++;
	  continue;
	}
	j = 0;
	while(isalpha(str[i]))
      wordstr[j++] = str[i++];
	wordstr[j] = '\0';
    SaveWord(wordstr, word);
  }
}

//���ʱ��档        
void SaveWord(char wordstr[], char word[][20])
{
  int i;
  
  for(i = 0; word[i][0] > 0; i++)
  {
	if (stricmp(wordstr, word[i]+1) == 0)  //�ҵ��˵���
	{
		word[i][0]++;
	    return;
	}
  }
  //û���ҵ����ʣ����뵽word��
  strcpy(word[i]+1, wordstr);
  word[i][0] = 1;
}

//��ʾ���ʼ����ֵĴ���
void ShowWord(char word[][20])
{
  int i;

  printf("\nWord sorting statistics��");
  for(i = 0; word[i][0] > 0; i++)
	printf("%s(%d) ", word[i]+1, word[i][0]);
  printf("\n");  

}

//�������򣨲���ѡ�����򣩡�
void SortWord(char word[][20]) 
{
  int i, j, k;
  char temp[20];

  for(i = 0; word[i][0] > 0; i++)
  {
	k = i;
	for(j = i+1; word[j][0] > 0; j++)
		if ((word[j][0] > word[k][0]) || 
			(word[j][0] == word[k][0] && stricmp(word[j]+1,word[k]+1) < 0))
			k = j;
	if (k != i)
	{
	  strcpy(temp, word[i]);
	  strcpy(word[i], word[k]);
	  strcpy(word[k], temp);
	}
  }
}
