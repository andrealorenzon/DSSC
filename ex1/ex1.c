// Write a function that takes an integer number n and a natural number m
// and returns n^m.

#include <stdio.h>

int power(int n, int m) 
{
	int result = 1;
	while(m>0) {
		result *= n;
		m--;
	}
}


int main(int argc, char const *argv[])
{
	int test; 
	test = power(4, 5);
	printf("%d\n", test );

	return 0;
}