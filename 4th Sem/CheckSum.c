#include<stdio.h>

int sender(int bits)
{
	char rawdata1[bits+1],sum_table[bits][50],c='0';
	int i,j,len=0,k=0,flag=1;
	printf("\nenter the first message(%d bits) : ",bits);
	scanf("%s",rawdata1);
	for(i=0;i<bits;i++)
	sum_table[k][i]=rawdata1[i];
	k++;
	printf("\nwant to enter more(1.yes | 0.no) : ");
	scanf("%d",&flag);
	while(flag)
	{
	printf("\nenter the next message(%d bits) : ",bits);
	scanf("%s",rawdata1);
	for(i=0;i<bits;i++)
	sum_table[k][i]=rawdata1[i];
	k++;
	if(k%2==0 && k>1)
{
	for(i=bits-1;i>=0;i--)
	{
		if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='0' && c=='0')
		{
			sum_table[k][i]='0';
			c='0';
		}
		else if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='0' && c=='1')
		{
			sum_table[k][i]='1';
			c='0';
		}
		else if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='1' && c=='0')
		{
			sum_table[k][i]='1';
			c='0';
		}
		else if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='1' && c=='1')
		{
			sum_table[k][i]='0';
			c='1';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='0' && c=='0')
		{
			sum_table[k][i]='1';
			c='0';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='0' && c=='1')
		{
			sum_table[k][i]='0';
			c='1';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='1' && c=='0')
		{
			sum_table[k][i]='0';
			c='1';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='1' && c=='1')
		{
			sum_table[k][i]='1';
			c='1';
		}
	}
	if(c=='1')
	{
		for(i=bits-1;i>=0;i--)
		{
			if(sum_table[k][i]=='0' && c=='0')
			{
				sum_table[k][i]='0';
				c='0';
			}
			if(sum_table[k][i]=='0' && c=='1')
			{
				sum_table[k][i]='1';
				c='0';
			}
			if(sum_table[k][i]=='1' && c=='0')
			{
				sum_table[k][i]='1';
				c='0';
			}
			if(sum_table[k][i]=='1' && c=='1')
			{
				sum_table[k][i]='0';
				c='1';
			}	
		}
	}
}
	k++;
	printf("\nwant to enter more(1.yes | 0.no) : ");
	scanf("%d",&flag);
}

for(i=0;i<bits;i++)
{
if(sum_table[k-1][i]=='0')
sum_table[k][i]='1';
else if(sum_table[k-1][i]=='1')
sum_table[k][i]='0';
}
printf("\nthe data to be sent : \n");
printf("\ndata word : ");
for(i=0;i<bits;i++)
printf("%c",sum_table[0][i]);
j=1;
while(1)
{
	if(j!=k)
printf("\ndata word : ");
else 
printf("\ncheck sum : ");
for(i=0;i<bits;i++)
printf("%c",sum_table[j][i]);
if(j<k)
{
j=j+2;
continue;
}
else
break;
}
return 0;
}

int receiver(int bits)
{
	char rawdata1[bits+1],sum_table[bits][50],c='0';
	int i,j,len=0,k=0,flag=1,cs=0;
	printf("\nenter the first message(%d bits) : ",bits);
	scanf("%s",rawdata1);
	for(i=0;i<bits;i++)
	sum_table[k][i]=rawdata1[i];
	k++;
	printf("\nwant to enter more(1.yes | 0.no) : ");
	scanf("%d",&flag);
	while(flag)
	{
	printf("\nenter the next message/check sum(%d bits) : ",bits);
	scanf("%s",rawdata1);
	for(i=0;i<bits;i++)
	sum_table[k][i]=rawdata1[i];
	k++;
	if(k%2==0 && k>1)
{
	for(i=bits-1;i>=0;i--)
	{
		if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='0' && c=='0')
		{
			sum_table[k][i]='0';
			c='0';
		}
		else if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='0' && c=='1')
		{
			sum_table[k][i]='1';
			c='0';
		}
		else if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='1' && c=='0')
		{
			sum_table[k][i]='1';
			c='0';
		}
		else if(sum_table[k-2][i]=='0' && sum_table[k-1][i]=='1' && c=='1')
		{
			sum_table[k][i]='0';
			c='1';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='0' && c=='0')
		{
			sum_table[k][i]='1';
			c='0';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='0' && c=='1')
		{
			sum_table[k][i]='0';
			c='1';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='1' && c=='0')
		{
			sum_table[k][i]='0';
			c='1';
		}
		else if(sum_table[k-2][i]=='1' && sum_table[k-1][i]=='1' && c=='1')
		{
			sum_table[k][i]='1';
			c='1';
		}
	}
	if(c=='1')
	{
		for(i=bits-1;i>=0;i--)
		{
			if(sum_table[k][i]=='0' && c=='0')
			{
				sum_table[k][i]='0';
				c='0';
			}
			if(sum_table[k][i]=='0' && c=='1')
			{
				sum_table[k][i]='1';
				c='0';
			}
			if(sum_table[k][i]=='1' && c=='0')
			{
				sum_table[k][i]='1';
				c='0';
			}
			if(sum_table[k][i]=='1' && c=='1')
			{
				sum_table[k][i]='0';
				c='1';
			}	
		}
	}
}
	k++;
	printf("\nwant to enter more(1.yes | 0.no) : ");
	scanf("%d",&flag);
}

for(i=0;i<bits;i++)
{
if(sum_table[k-1][i]=='0')
sum_table[k][i]='1';
else if(sum_table[k-1][i]=='1')
sum_table[k][i]='0';
}
for(i=0;i<bits;i++)
{
	if(sum_table[k][i]=='1')
	cs=1;
}
if(cs==1)
printf("the data has error");
else
printf("the data has no error");
return 0;
}

int main()
{
	
	int n,i,bits;
	printf("\nenter 1 for sender side, 2 for reciever side : ");
	scanf("%d",&n);
	printf("\nenter the number of bits of the checksum : ");
	scanf("%d",&bits);
	switch(n)
	{
		case 1:
	sender(bits);
	break;
	case 2:
	receiver(bits);
	break;
	default:
	printf("\nwrong choice...try again");
}
}

