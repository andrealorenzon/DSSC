/*

funziona approssimativamente
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double x)  // funzione in analisi
{
	return ( 2.00 * x * x * x - 4.00 * x + 1.00);
}

double search(double a, double b, double precision) {   // funzione di ricerca

	double m = (a+b)/2;  //calcola punto medio
	
	printf("%f\t%f\t%f\t%f\t%f\t%f\n",a,b,m,f(a),f(b),f(m) );  //debug, scrive a, b, punto medio e rispettivi valori y
	if (abs(f(m)) < precision) {
		return m;
	}    // caso base, se f(m) è inferiore alla precisione in valore assoluto,
											// esce dal ciclo e restituisce m
	else 									// oppure, se non è abbastanza preciso
	{
		if(f(a)*f(m) < 0) {					//se a e m hanno segni opposti, vuol dire che lo zero è tra essi, quindi

			search(a,m,precision);			//cerca tra a e m, 
		}
		else {								//altrimenti
				
			search(m, b, precision);		//cerca tra m e b.
		}
	}
}


int main(int argc, char const *argv[])
{
	if (argc != 4) return 1;   					//verifica che ci siano 3 argomenti, se no quitta

	double a = atof(argv[1]);					//assegnazione di a, b e precisione
	double b = atof(argv[2]);
	double precision = atof(argv[3]);

	printf("searching from %f to %f with precision %f\n\n", a, b, precision); //debug, verifica gli input

	printf("a\t\tb\t\tm\t\tf(a)\t\tf(b)\t\t(f(m)\n");			// indice nomi colonne

	double root = search(a,b,precision);						// cerca la radice
	printf("lo zero è : %f\n" , root);							// stampa la radice

	return 0;
}