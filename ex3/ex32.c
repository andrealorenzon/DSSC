#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	long long int prev = 1;
	long long fibN = 1;
	long long next = 1;

	// debug OK!  printf("%d\n", n );

	if (n<=0) {printf("n deve essere intero positivo.\n"); return 1;}
	
	printf("1\n");
	while (n>1) {

		printf("%lld\n", fibN );
		next = prev + fibN;
		prev = fibN;
		fibN = next;
		n--;
	}

	return 0;
}