#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, i, j, k;
    double maind=0, dopd=0;
	printf("Size matrx:\n");
	scanf("%d", &a);
	double x[a][a], y[a][a];
	printf("element of matrix:\n");
	for (i = 0; i<a; i++)
	{
    	for (j = 0; j<a; j++)
		{
    		scanf("%lf", &x[i][j]);
    		if (i==j)
    		{
    			maind=maind+x[i][j];
			}
			if(a==i+j+1)
			{
    			dopd=dopd+x[i][j];
			}
    	}
	}
	printf("\nYour massive\n");
	for (i=0; i<a; i++)
	
	{
	    for (j=0; j<a; j++)
    	    printf("%lf ", x[i][j]);
    	printf("\n");
	}
	printf("1diagonal: %lf, 2diagonal: %lf", maind, dopd);
	
	/*for(i = 0; i<a; i++)
	{
    	for(j = 0; j<a; j++)
    	{
   		    y[i][j]=0;
 		    for(k=0; k<a; k++)
    	    y[i][j] += x[i][k] * x[k][j];
    	}
	}*/
	
    	
	}
	
	
	double g[2][2];

	printf("element of matrix:\n");
	for (i = 0; i<2; i++)
	{
    	for (j = 0; j<2; j++)
		{
    		scanf("%lf", &g[i][j]);
    		
    	}
	}
    for(i = 0; i<2; i++)
	{
    	for(j = 0; j<2; j++)
    	{
   		    y[i][j]=0;
 		    for(k=0; k<2; k++)
    	    y[i][j] += g[i][k] * g[k][j];
    	}
	}
	
printf("\nSquare of matrx\n");
	for (i=0; i<2; i++)
	{
	    for (j=0; j<2; j++)
    	    printf("%lf ", g[i][j]);
    	printf("\n");
}
}

