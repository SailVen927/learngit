#include <stdio.h>
#include <stdlib.h>
//���������ַ������ַ����͵�����
int main()
{
	int charCount=0;//�ַ�����
	int wordCount=0;//���ʼ���
	int i=0;
	int flag=0;//�жϿո�Ͷ���ǰ���Ƿ�Ϊͬ���ķָ���
	char c;
	//��ȡ�����ı�
	char text[400]={""};
	FILE* fp = fopen("context.txt", "r");
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
	printf("%d %d\n",charCount,wordCount+1);
	printf("%s",text);
	return 0;
}