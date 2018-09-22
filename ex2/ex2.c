// Write a function that takes two natural numbers n 
// and m and returns radice m-sima di n.

//commento extra


#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

double power(double n, int m) 
{
	double result = 1;
	while(m>0) {
		result *= n;
		m--;
	}
	return result;
}


double radice(double x, int n){
	
	double stimaNext;
	double stimaPrev = 8000;
	double precision = 0.00001;
	double deltaStima = 1000000;

	while (deltaStima > precision) {
		
		stimaNext = ((n-1) * stimaPrev + x /  power(stimaPrev, n-1)) / n;
		//DEBUG printf("StimaNext assegnato a : %lf\n", stimaNext );
		deltaStima = abs(stimaNext-stimaPrev);
		//DEBUG printf("deltaStima è %lf\n", deltaStima );
		stimaPrev = stimaNext;
		//DEBUG printf("Stima provvisoria: %lf\n", stimaPrev );
	
	}
		
	return stimaNext;
	}


int main(int argc, char *argv[])
{
	
	
	if (argc != 3) {
		printf("argomenti errati. 2 richiesti.\n");
		return 1;
	}
	
	double n = atof(argv[1]);
	int m = atoi(argv[2]);
	
	printf("base = %lf\n", n );
	printf("esponente radicale = %d\n", m);
	printf("radice = %lf \n", radice(n,m) );
	printf("check rielevamento a potenza: %lf\n", power(radice(n,m),m) );


	return 0;
}