#include <stdio.h>
#include <stdlib.h>


double valassol(double x);

#define precision 0.000001


double valassol(double x){
	if (x<0) return -x;
	else return x;
}

double pot(double n, int m){
	double output = 1;
	while (m>0) {
		output *= n;
		m--;
	}
	return output;
}


double main(int argc, char const *argv[])
{
	if  (argc != 2) return 1;

	double n = atof(argv[1]);   // legge l'argomento, e lo splitta in base e segno
	int negativa = 0;
	if (n < 0) negativa = 1;
	n= abs(n);


	printf("n = %f\nnegativa? = %d\n", n, negativa );  //debug  OK

	double error = 100000000000000000;
	double a = 0;
	double b = n;
	double m;

	while (valassol(error) > precision) 
	{
		  m = (a+b)/2;// calcola il punto medio, che è la stima più recente della radice di n
		  printf("a=%f || b=%f || m=%f\n", a, b, m );
		  error = n - pot(m,2);// calcola l'errore (n - punto medio ^ 2)
		  printf("error = %f\n", error);
		  if (error >= 0) a = m;// se l'errore è positivo, bisogna cercare tra il punto medio e b
		  else b = m;// altrimenti, tra a e il punto medio
		  //printf("errore = %f\n", error);

	}
	printf("La radice è %f", m );
	if (negativa) printf("i");
	printf("\n");

	return 0;
}