#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���������ַ������ַ����͵�����
int main(int argc, char *argv[])
{
	int charCount=0;//�ַ�����
	int wordCount=0;//���ʼ���
	int i=0;
	int flag=0;//�жϿո�Ͷ���ǰ���Ƿ�Ϊͬ���ķָ���
	char c;
	//��ȡ�����ı�
	char text[400]={""};
	FILE* fp = fopen(argv[2], "r");
    if(!fp) {
        perror("File opening failed");
        return 0;
    }
	
    while ((c = fgetc(fp)) != EOF) { 
	   text[i++]=c;
    }
	//����
	for(i=0;(c=text[i])!=NULL;i++)
	{
		if(flag==0 && (c==',' || c==' '))//��ĸ���״������ָ���
		{
			flag=1;
			continue;
		}
		if(flag==1 && !(c==',' || c==' '))//�ָ�����������һ����ĸ
		{
			flag=0;
			wordCount++;
		}
	}
	charCount=i;
	if(strcmp(argv[1],"-c")==0)
	{
		printf("�ַ�����%d",charCount);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		printf("��������%d",wordCount+1);
	}else
	{
		printf("�������");
	}
	
	return 0;
}