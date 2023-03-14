#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  int child_pid[4]={-1,-1,-1,-1};
  int i;

// prima generatie
  child_pid[0]  = fork();
// a 2a generatie
  child_pid[1]  = fork();
// a 3a generatie
  child_pid[2]  = fork();
// a 4a generatie
  child_pid[3]  = fork();

  for(i=0; i<4;i++)
	  if (child_pid[i]==-1)
		  printf("-");
		  else
		  {
			  if (child_pid[i]==0)
				  printf("C");
			  else
				  printf("P");
		  }
  printf("\n");
  fflush(stdout);

   return(EXIT_SUCCESS);
}