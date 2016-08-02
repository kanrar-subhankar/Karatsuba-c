#include<stdio.h>
#include<math.h>
int getsize(long int p)
{
	int c=0;
	while(p!=0)
	{
	p=p/10;
	c++;
	}
	return c;
}
long int multiply(long int x,long int y)
{
	int n,m;
	 int a,b,c,d,z0,z1,z2;
	int size1=getsize(x);
	int size2=getsize(y);
	n=(size1>size2) ? size1:size2;
	   if (n < 10)
            return x * y;

	n=(n/2)+(n%2);
	m=pow(10,n);
	a=x/m;
	b=x-(m*a);
	c=y/m;
	d=y-(m*c);
	z0=multiply(a,c);
	z1=multiply((a+b),(c+d));
	z2=multiply(b,d);
	return z0 + ((z1 - z0 - z2) * m) + (z2 * (pow(10, 2 * n)));


}
int main(void)
{
	long int x,y,result;
	printf("Enter two nos\n");
	scanf("%ld%ld",&x,&y);
	result=multiply(x,y);
	printf("The result of Karatsuba multiplication: %ld\n",result);
 	return 0;
}







