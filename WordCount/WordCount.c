#include <stdio.h>
#include <stdlib.h>
//���������ַ������ַ����͵�����
int main()
{
	int charCount=0;//�ַ�����
	int wordCount=0;//���ʼ���
	int i=0;
	char c;
	//��ȡ�����ı�
	char text[400]={""};
	gets(text);
	//����
	for(i=0;(c=text[i])!=NULL;i++)
	{
		if(c==',' || c==' ')
		{
			wordCount++;
		}
	}
	printf("%d %d",charCount,wordCount);
	return 0;
}