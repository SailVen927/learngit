#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//返回输入字符串的字符数和单词数
int main(int argc, char *argv[])
{
	int charCount=0;//字符计数
	int wordCount=0;//单词计数
	int i=0;
	int flag=0;//判断空格和逗号前后是否为同样的分隔符
	char c;
	//获取输入文本
	char text[400]={""};
	FILE* fp = fopen(argv[2], "r");
    if(!fp) {
        perror("File opening failed");
        return 0;
    }
	
    while ((c = fgetc(fp)) != EOF) { 
	   text[i++]=c;
    }
	//计算
	for(i=0;(c=text[i])!=NULL;i++)
	{
		if(flag==0 && (c==',' || c==' '))//字母后首次遇到分隔符
		{
			flag=1;
			continue;
		}
		if(flag==1 && !(c==',' || c==' '))//分隔符后遇到第一个字母
		{
			flag=0;
			wordCount++;
		}
	}
	charCount=i;
	if(strcmp(argv[1],"-c")==0)
	{
		printf("字符数：%d",charCount);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		printf("单词数：%d",wordCount+1);
	}else
	{
		printf("输入错误");
	}
	
	return 0;
}