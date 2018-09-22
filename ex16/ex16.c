#include <stdio.h>

/* standart I/O library
*/

#include <assert.h> 

/*
assert() valuta la condizione interna, e crea abort() se non è vera.
serve a verificare che ci siano ancora delle condizioni, tipo
l'allocazione di memoria
*/
#include <stdlib.h>
//contiene malloc()

#include <string.h>
//funzioni per stringhe

struct Person  //definizione della struttura dati Person
{
	char *name;
	int age;
	int height;
	int weight;
};


//costruttore di un'entità Person
// malloc alloca memoria dinamicamente, in base al sizeof
// di Person. assert() verifica. NULL sta per "unset or invalid
// pointer".



struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height=height;
	who->weight=weight;

	return who;
}

void Person_destroy(struct Person *who) {
	assert (who != NULL);
	free(who->name);
	free(who);
}

void Person_print (struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age );
	printf("\tHeight: %d\n",who->height );
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char const *argv[])
{
	//make two people structures
	struct Person *joe = Person_create
	 ( "Joe Alex", 32, 64, 140);

	 struct Person *frank = Person_create
	 ( "Frank Blank", 20,72,180);


	 //print them out and where they are in memory
	 printf("Joe is at memory location %p: \n", joe);
	 Person_print(joe);

	 printf("Frank is at memory location: %p\n", frank);
	 Person_print(frank);

	 //make everyone age 20 years and print them again

	 joe->age += 20;
	 joe->height -= 2;
	 joe->weight +=40;
	 Person_print(joe);

	 frank->age += 20;
	 frank->weight +=20;
	 Person_print(frank);

	 //destroy both
	 Person_destroy(joe);
	 Person_destroy(frank);

	return 0;
}