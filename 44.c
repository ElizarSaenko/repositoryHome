#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#define false 0
#define true 1


double per (double a, double b, double c) {
	return (a+b+c);
}
  double s (double a, double b, double c, double p){

	return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

bool x(a, b, c){
	return (a >= b + c || b >= a + c || c >= b + a);
}

int main() 
{
	double a, b, c;
	double p;
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);
	
	p = ((a + b + c) / 2);
	if (x(a, b, c) == 0)
	{

		printf("error");
	}
	else 
	{
	
		printf("%lf\n", p);
		//printf("%d\n", x(one, two, three));
		printf("%lf\n", per(a, b, c));
		printf("%lf\n", s(a, b, c, p));
		
	}
}
