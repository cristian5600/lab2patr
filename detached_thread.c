#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void * threadFunc(void * arg);
int ret=0;

int main(void){
	// Thread id
    pthread_t threadId;
    if (pthread_create(&threadId, NULL, &threadFunc, NULL) != 0)
    {
		printf("Thread creation failed : ");
		perror("pthread_create");
		return EXIT_FAILURE;
    }
    else
        printf("Thread Created with ID : %lui \n",threadId);
    // Do some stuff
   
    if (pthread_detach(threadId)!=0)
    {
	       perror("pthread_detach");
	       return EXIT_FAILURE;
    }
    // Sleep for 2 seconds because if main function exits, then other threads will
    // be also be killed. Sleep for 2 seconds, so that detached exits by then
    sleep(2);
	printf(" value returned by thread : %d\n",ret);
    printf("Main function ends \n");
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
    return 0;
}