#include <stdio.h>
#include <stdlib.h>
//返回输入字符串的字符数和单词数
int main()
{
	int charCount=0;//字符计数
	int wordCount=0;//单词计数
	int i=0;
	char c;
	//获取输入文本
	char text[400]={""};
	gets(text);
	//计算
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