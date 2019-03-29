#include<stdio.h>
#include<stdlib.h>
#define f(x) (1/(1+(x*x)))	//function definition
float a,b,n,abe,re,pe;
float h,sum,sum2,tmp;
int i;
float simpson()	
{
	sum=((f(a)+f(b))*h)/3;
	for(i=1;i<n;i++)
	{
		tmp=a+(i*h);
		if(i%2==0)
			sum+=h*2*f(tmp)/3;
		else
			sum+=h*4*f(tmp)/3;
	}
	printf("\nSimpson\nValue: %f\n",sum);
}

float trapezoidal()
{
	sum2=((f(a)+f(b))*h)/2;
	for(i=1;i<n;i++)
	{
		tmp=a+i*h;
		sum2+=h*f(tmp);
	}
	printf("\nTrapezoidal\nValue: %f\n",sum2);
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

int main()
{
	int ch;
	printf("Enter the limits\n");
	printf("A: ");	//lower limit
	scanf("%f",&a);
	printf("B: ");	//upper limit
	scanf("%f",&b);
	printf("Enter the number of intervals\n"); //number of limits to calculate integration value
	scanf("%f",&n);
	h=(b-a)/n;	//calculate h
	for(;;)
	{
		printf("\n0.Exit\n");
		printf("1.Trapezoidal Method\n");
		printf("2.Simpson's 1/3rd Rule\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:		//calculate trapezoidal
			trapezoidal();
			error(sum2);	//error calculation 
			break;
			
			case 2:		//calculate simpsons 1/3rd rule
			simpson();
			error(sum);	//error calculation
			break;
			
			case 0:
			exit(0);
			
			default:
			printf("INVALID CHOICE\n");
			break;
		}
	}
}
