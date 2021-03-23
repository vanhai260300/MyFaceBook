#include <stdio.h>
#include <math.h>
float Sum1 ( int n )
{
	
	if (n==1)
		return 1.0;
	else		
		return (1.0/n)+(Sum1(n-1));
	
}
float Sum2 ( int n )
{
	
	if (n==1)
		return 1.0;
	else
		if (n%2==0)		
			return -(1.0/n)+(Sum2(n-1));
		else
			return (1.0/n)+(Sum2(n-1));
}
float Sum3 ( int n )
{
	
	if (n==1)
		return -1.0;
	else
		if (n%2==0)		
			return (1.0/n)+(Sum3(n-1));
		else
			return -(1.0/n)+(Sum3(n-1));
}
int gt (int n)
{
	if (n==1 )
		return 1;
	else
		return n*gt(n-1);	
}
float Sum4 ( int n )
{
	
	if (n==1)
		return 1.0;
	else
		return (1./gt(n))+Sum4(n-1);
}
float Sum5 ( int n )
{
	
	if (n==1)
		return 1.0;
	else
		if (n%2==0)		
			return -(1./gt(n))+Sum5(n-1);
		else
			return (1./gt(n))+Sum5(n-1);
}	
float Sum6 ( int n )
{
	
	if (n==1)
		return -1.0;
	else
		if (n%2==0)		
			return (1./gt(n))+Sum6(n-1);
		else
			return -(1./gt(n))+Sum6(n-1);
}	
float Sum7 ( int n )
{
	
	if (n==1)
		return 1.0;
	else
		return sqrt(2+Sum7(n-1));
}
float Sum8 ( int n )
{
	
	if (n==1)
		return 1.0;
	else
		return sqrt(n+Sum8(n-1));
}
		
main ()
{
	int n;
	printf ("Enter the number: ");
	scanf ("%d",&n);
	printf ("Bai 1: \nS= %.4f \n", Sum1 (n));
	printf ("Bai 2: \nS= %.4f \n", Sum2 (n));
	printf ("Bai 3: \nS= %.4f \n", Sum3 (n));
	printf ("Bai 4: \nS= %.4f \n", Sum4 (n));
	printf ("Bai 5: \nS= %.4f \n", Sum5 (n));
	printf ("Bai 6: \nS= %.4f \n", Sum6 (n));
	printf ("Bai 7: \nS= %.4f \n", Sum7 (n));
	printf ("Bai 8: \nS= %.4f \n", Sum8 (n));
}

