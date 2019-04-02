#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (1/(1+(x*x)))
void trapezoidal(void);
void simpson(void);
int main()
{
int c,count=0;
float s=0.0,s1=0.0;
while(1)
{
if(count==0){
printf("\t\t\tWelcome to Integrator:");
printf("\n\t\t\tPlease Select from the following methods:");}
printf("\n\n \t\t\t\tMethod 1:Trapezoidal Rule:\n\t\t\t\tMethod 2:Simpson's 1/3rd Rule:\n\t\t\t\tPress 3 to Exit Integrator");
printf("\n\t\t\t\t--------------------------------------------- ");
printf("\n\n Enter Your Choice:\t");
scanf("%d",&c);
switch(c)
{
case 1:
trapezoidal();break;
case 2:
simpson();
break;
case 3:
exit(0);
default:
printf("\n Your Choice is Invalid.");
break;
}
count++;
}
}
void trapezoidal()
{
float a,b,h,s=0.0,y[100];
int i,c,n;
printf("\n Please Enter The Number Of Intervals:");
scanf("%d",&n);
printf("\n Enter the value of a:");
scanf("%f",&a);
printf("\n Enter the value of b:");
scanf("%f",&b);
printf("\n Enter the value of h:");
h=((b-a)/n);
printf("%f",h);
printf("\n \tx \tf(x)");
for(i=0;i<=n;i++)
{
y[i]=f(a+(i*h));
printf("\n %f \t %f",(a+i*h),y[i]);
}
for(i=1;i<n;i++)
{
s=s+y[i];
}
s=((y[0]+y[n])+2*s);
s=s*(h/2);
printf("\n %f",s);
}
void simpson(){
float a,b,h,s=0.0,s1=0.0,y[100];
int i,c,n;
printf("\n Please Enter The Number Of Intervals:");
scanf("%d",&n);
printf("\n Enter the value of a:");
scanf("%f",&a);
printf("\n Enter the value of b:");
scanf("%f",&b);
printf("\n Enter the value of h:");
h=((b-a)/n);
printf("%f",h);
printf("\n \tx \tf(x)");
for(i=0;i<=n;i++)
{
y[i]=f(a+(i*h));
printf("\n %f \t %f",a+i*h,y[i]);
}
for(i=1;i<n;i++)
{
if(i%2==0)
s=s+2*y[i];
else
{
s1=s1+4*y[i];
}
}
s=((y[0]+y[n])+s+s1);
s=s*(h/2);
printf("\n %f",s);
}
