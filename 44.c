#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, b, c, p;
int per(a, b, c) {
	return a+b+c;
}
float s(a, b ,c, p) {
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() 
{
	int one, two, three, polusum;
	printf("a: ");
	scanf("%d", &one);
	printf("b: ");
	scanf("%d", &two);
	printf("c: ");
	scanf("%d", &three);
	
	if (one >= two + three || two >= one + three || three >= two + one) 
	{
		printf("error");
	}
	else 
	{
		printf("%d\n", per(one, two, three));
		polusum = (one + two + three) / 2;
		printf("%fl\n", s(one, two, three, polusum));
	}
}
