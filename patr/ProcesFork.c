#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
  int child_pid;

  printf("Acesta este procesul parinte cu pid-ul %d\n", getpid());
  fflush(stdout);

  child_pid  = fork();
  if( child_pid)
	     printf("Acesta este parintele, pid-ul pentru child este %d\n",child_pid);
  else
	    printf("Acesta este child, pid-ul pentru child este %d\n", getpid());

   return(EXIT_SUCCESS);
}
