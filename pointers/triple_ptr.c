#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>



void alloc2d(double*** a, int m, int n)
{

     double **temp = malloc( sizeof( double* ) * m );

     temp[0] = malloc( sizeof(double) * n * m );  
     for ( int i=1; i<m; i++ )
         temp[i] = temp[0] + n*i;                    

     *a = temp;                                     
}


int main()
{
	double** m;
	alloc2d(&m, 5, 10);

	double count = 0.0;

	for (int i = 0; i < 5; i++)
    	for (int j = 0; j < 10; j++)
        	m[i][j] = ++count;

	for (int i = 0; i <  5; i++)
    	for (int j = 0; j < 10; j++)
        	printf("%f ", m[i][j]);

}