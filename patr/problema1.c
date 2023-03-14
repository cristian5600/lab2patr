#include  <stdio.h>
#include  <sys/types.h>

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(int, int);               /* parent process prototype */

void  main(void)
{
	
  int child_pid[2]={-1,-1};

  int i;



  for(i=0; i<2;i++){
	  child_pid[i]=fork();
	  if (child_pid[i]==-1)
		  printf("-");
		  else
		  {
			  if (child_pid[i])
					 ParentProcess(getpid(), child_pid[i]);
				 else 
					 ChildProcess(getpid()); 
		  }
}
}

void  ChildProcess(int id)
{
     printf("Acesta este child, pid-ul pentru child este %d\n", id);
}

void  ParentProcess(int id_p, int id)
{
     printf("Acesta este parintele %d, pid-ul pentru child este %d\n",id_p, id);
}