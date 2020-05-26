#include<stdio.h>
void program()
{
	printf("新的计算:\n");
	printf("支持的运算符:+,-,*,/\n");

	int num[20];
	int i=0,j=0,k=0,temp,x=0,y=0,re=0,m;
	int p=1;//出现错误后p讲被赋值0，将不输出结果
	char c,a[100];

	//赋值输入
	while((c=getchar())!='\n')
	{
		a[k]=c;
		k=k+1;
	}
	a[k]='\0';

	printf("开始计算:\n");
	//判断读取拼接
	//不能首个字符
	if(a[i]==42||a[i]==47)
	{
		printf("Error01\n");
		p=0;
	}

	//解决首个负数
	if(a[i]==45)
	{
		i++;
		if(48<=a[i]&&a[i]<=57)
		{
			temp=a[i]-48;
			i++;
			while(48<=a[i]&&a[i]<=57)
			{
				temp=temp*10+a[i]-48;
				i=i+1;
			}
			num[j]=0-temp;
			j=j+1;;
		}
		else
		{
			printf("Error02\n");
			p=0;
		}
	}
	else if(a[i]==43)
	{
		i++;
		if(48<=a[i]&&a[i]<=57)
		{
			temp=a[i]-48;
			i++;
			while(48<=a[i]&&a[i]<=57)
			{
				temp=temp*10+a[i]-48;
				i=i+1;
			}
			num[j]=temp;
			j=j+1;
		}
		else
		{
			printf("Error02\n");
			p=0;
		}
	}
	//读取
	while(i<k)
	{
		if(48<=a[i]&&a[i]<=57)
		{
			temp=a[i]-48;
			i++;
			while(48<=a[i]&&a[i]<=57)
			{
				temp=temp*10+a[i]-48;
				i=i+1;
			}
			num[j]=temp;
			j=j+1;
		}
		else if(a[i]==43||a[i]==42||a[i]==45||a[i]==47)
		{
			num[j]=a[i];
			j=j+1;
			i=i+1;
		}
		else
		{
			printf("Error03\n");
			p=0;
			break;
		}
	}
	if(j==1)
	{
		printf("Error04\n");
		p=0;
	}
	if(num[0]<0&&j%2==0)
	{
		printf("Error05\n");
		p=0;
	}
	//if(a[0]==+&&j%2!=0)
		//printf("Error05\n");
	//此时j为固定参数，不可修改

	/*
	for(i=0;i<j;i++)
	{
		printf("%d\n",num[i]);
	}
	*/
	if(p==0)
	{
		printf("********************\n");
		printf("有错误，请检查错误报告\n");
		printf("####################\n");
		return;
	}

	//开始计算
	//找出所有的乘法除法
	for(i=1;i<j;i=i+2)
	{
		x=x+1;
		if(num[i]==42||num[i]==47)
		{
			y=y+1;
		}
	}
	if(y==0)//若无乘除直接加减
	{
		re=num[0];
		for(i=1;i<=j;i=i+1)
		{
			if(num[i]==43)
			{
				temp=re;
				re=re+num[i+1];
				printf("%d+%d=%d\n",temp,num[i+1],re);
				printf(" %d\n",temp);
				printf("+%d\n",num[i+1]);
				printf("--------\n");
				printf(" %d\n",re);
			}
			if(num[i]==45)
			{
				temp=re;
				re=re-num[i+1];
				printf("%d-%d=%d\n",temp,num[i+1],re);
				printf(" %d\n",temp);
				printf("-%d\n",num[i+1]);
				printf("--------\n");
				printf(" %d\n",re);
			}
		}
	}
	else//包含乘除
	{
		
		//优先处理乘除
		for(i=1;i<j;i=i+1)
		{
			
			if(num[i]==42)
			{
				temp=num[i-1]*num[i+1];
				printf("%d*%d=%d\n",num[i-1],num[i+1],temp);
				printf(" %d\n",num[i-1]);
				printf("x%d\n",num[i+1]);
				printf("--------\n");
				printf(" %d\n",temp);
				num[i-1]=temp;
				for(m=i;m<j-1;m++)
				{
					num[m]=num[m+2];
				}
				j=j-2;
				i=i-1; 
			}
			if(num[i]==47)
			{
				if(num[i+1]==0)
				{
					p=0;
					printf("Error06");
					break;
				}
				temp=(num[i-1]+num[i+1]/2)/num[i+1];
				printf("%d/%d=%d\n",num[i-1],num[i+1],temp);
				//除法竖式
				if(num[i+1]<10)
				{
					printf(" %d\n",temp);
					printf(" --------\n");
				}
				else if(num[i+1]>=10&&num[i+1]<100)
				{
					printf("  %d\n",temp);
					printf("  --------\n");
				}
				else
				{
					printf("   %d\n",temp);
					printf("   --------\n");
				}
				printf("%d|%d\n",num[i+1],num[i-1]);

				num[i-1]=temp;
				for(m=i;m<j-1;m++)
				{
					num[m]=num[m+2];
				}
				j=j-2;
				i=i-1;
			}
			
		}
		/*
		for(i=0;i<j;i++)
		{
			printf("%d\n",num[i]);
		}
		*/
		//乘除后加减
		re=num[0];
		for(i=1;i<=j;i=i+2)
		{
			if(num[i]==43)
			{
				temp=re;
				re=re+num[i+1];
				printf("%d+%d=%d\n",temp,num[i+1],re);
				printf(" %d\n",temp);
				printf("+%d\n",num[i+1]);
				printf("--------\n");
				printf(" %d\n",re);
			}
			if(num[i]==45)
			{
				temp=re;
				re=re-num[i+1];
				printf("%d-%d=%d\n",temp,num[i+1],re);
				printf(" %d\n",temp);
				printf("-%d\n",num[i+1]);
				printf("--------\n");
				printf(" %d\n",re);
			}
		}
	}
	printf("********************\n");
	printf("最终结果:\n");
	if(p)
		printf("%s=%d\n",a,re);
	else
		printf("有错误，请检查错误报告\n");
	printf("####################\n");
}

//主函数
int main()
{
	printf("简易计算器\n");
	printf("####################\n");
	while(1)
	{
		program();
	}
	return 0;
}
