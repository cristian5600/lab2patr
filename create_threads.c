#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* afiseaza_mesaj(void *);

void* (*functie[])(void*) = {afiseaza_mesaj, afiseaza_mesaj};

char *mesaje[] = {"\tCrearea firelor de ", "executie sub Debian!\n"};

int main(void){
  pthread_t FIR[2];

   int i;

  for(i=0; i<2;i++)
	if (pthread_create(&FIR[i], NULL, functie[i], (void *)mesaje[i]) != 0)
	    { perror("pthread_create");
	     return EXIT_FAILURE;
	    }

  for(i=0; i<2; i++)
	   if (pthread_join(*(FIR+i), NULL) != 0){
	       perror("pthread_join");
	       return EXIT_FAILURE;
	   }

  printf("\nMain: toate firele s-au terminat.\n");
  pthread_exit(NULL);
}

void* afiseaza_mesaj(void *ptr){
  char *mesaj = (char *)ptr;

  fflush(stdout);
  printf("%s", mesaj);
}
