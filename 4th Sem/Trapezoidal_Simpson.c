#include<stdio.h>
#include<stdlib.h>
#define f(x) (1/(1+(x*x)))	//function definition
float a,b,abe,re,pe;
int n;
float h,sum,sum2,tmp;
int i;
float simpson()	
{
	printf("\nSimpson\nN\tValue\n");
	sum=((f(a)+f(b))*h)/3;
	for(i=1;i<n;i++)
	{
		tmp=a+(i*h);
		if(i%2==0)
			sum+=h*2*f(tmp)/3;
		else
			sum+=h*4*f(tmp)/3;
		printf("%d\t%f\n",i,sum);
	}
	printf("The value of the function is : %f",sum);
}

float trapezoidal()
{
	printf("\nTrapezoidal\nN\tValue\n");
	sum2=((f(a)+f(b))*h)/2;
	for(i=1;i<n;i++)
	{
		tmp=a+i*h;
		sum2+=h*f(tmp);
		printf("%d\t%f\n",i,sum2);
	}
	printf("The value of the function is : %f",sum2);
}

float error(float s)	//calculate  absolute,relative and percentage error
{
	float ans;
	printf("\nEnter the actual answer : ");
	scanf("%f",&ans);
	abe=abs(s-ans);
	re=(s-ans)/ans;
	pe=re*100;
	printf("\nAbsolute Error: %f\nRelative Error : %f\nPercentage Error : %f\n",abe,re,pe);
}
void inp()
{
	printf("Enter the limits\n");
	printf("A: ");	//lower limit
	scanf("%f",&a);
	printf("B: ");	//upper limit
	scanf("%f",&b);
	printf("Enter the number of intervals\n"); //number of limits to calculate integration value
	scanf("%d",&n);
	h=(b-a)/n;	//calculate h
}
int main()
{
	int ch;
	for(;;)
	{
		printf("\n0.Exit\n");
		printf("1.Trapezoidal Method\n");
		printf("2.Simpson's 1/3rd Rule\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:		//calculate trapezoidal
			inp();
			trapezoidal();
			error(sum2);	//error calculation 
			break;
			
			case 2:		//calculate simpsons 1/3rd rule
			inp();
			if(n%2==0)
			{
				simpson();
				error(sum);	//error calculation
			}
			else
				printf("N must be even only\n");
			break;
			
			case 0:
			exit(0);
			
			default:
			printf("INVALID CHOICE\n");
			break;
		}
	}
}
