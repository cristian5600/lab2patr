#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void * threadFunc(void * arg);

int ret=0;

int main(void){
	// Thread id
    pthread_t threadId;
    // Create a thread that will function threadFunc()and check if thread is created sucessfuly
    if (pthread_create(&threadId, NULL, &threadFunc, NULL) != 0)
    {
		printf("Thread creation failed : ");
		perror("pthread_create");
		return EXIT_FAILURE;
    }
    else
        printf("Thread Created with ID : %lui \n",threadId);
    // Do some stuff
   
    printf("Waiting for thread to exit\n");
    // Wait for thread to exit
    if (pthread_join(threadId, NULL) !=0)
    {
 	       perror("pthread_join");
	       return EXIT_FAILURE;
    }
    if (ret)
       printf(" value returned by thread : %d\n",ret);
    return 0;
}

void * threadFunc(void * arg)
{
    printf("Thread Function :: Start\n");
    // Sleep for 2 seconds
    sleep(2);
	ret=6;
    printf("Thread Function :: End\n");
    // Return value from thread
}