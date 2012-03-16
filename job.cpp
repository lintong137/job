#include <stdio.h>
#include <stdlib.h>
#define MAX 1002

int main()
{

	printf("你开门");
 	char *p=NULL;
	p=(char *)malloc(sizeof(char)*MAX);
 	if(!p)
	return 1;
	while(scanf("%s",p)!=EOF)
	{
		int num_a = 0,num_b = 0,num_c = 0;
		int flag = 0;
		int end_flag=0;
		int i=0;
		while(p[i]!='\0')
		{
			if(p[i]=='o'&&flag<=3)//对o进行判断，可知o应该出现在三个地方，即z之前，z和j中间以及j之后，利用flag对其位置判断。
			{
				switch(flag)
				{
					case 0:
					num_a++;
					break;
					case 1://o第一次在中间出现应使得flag自增，便于j到判断。
					num_b++;
					flag++;
					break;
					case 2:
					num_b++;
    					break;
					case 3:
					num_c++;
					break;
				}
				i++;
				continue;
			}
			if(p[i]=='z'&&flag==0)
			{
				flag++;
				i++;
				continue;
			}
			if(p[i]=='j'&&flag==2)
			{
				i++;
				flag++;
				continue;

			}
			printf("Wrong Answer\n");// 程序执行到这里，说明有错误
			end_flag=1;
			break;
		}
		if(!end_flag)//统计完字符后，进行判断
		{
			if(num_a==num_c&&num_b==1)//正确情况
			{
				printf("Accepted\n");	
			}
			else
			{
				while(num_c>=num_a&&num_c>0&&num_b>0&&num_b>=1)
				{
				
					num_c-=num_a;//此处循环将num_c-num_a判断之前情况是否满足即要判断azbojac 要转向判断azbjc
					num_b-=1;
					if(num_a==num_c&&num_b==1)
					{
						printf("Accepted\n");
						end_flag=1;
						break;
					}
				}
				if(!end_flag)
				{
					printf("Wrong Answer\n");
				}
			}
		}
		free(p);
		p=NULL;
		p=(char *)malloc(sizeof(char)*MAX);
		if(!p)
		return  1;
	}
	return 0;
}
