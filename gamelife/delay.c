#include<stdio.h>
#include<stdlib.h>


int delay (int);
int main(void)
{
	
	for(int i=1;i<=10;i++)
	{
	printf("%d segundos\n",i);
	delay(1);
	}
	return 0;
}



int delay(int time)
{

	do
	{
		for(int i=15000;i>0;i--)
		{
			for(int i=20000;i>0;i--)
			{

			}
		}	
	time--;
	}while(time>0);
	return 0;
}