#include <spawn.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <process.h>

int main(int argc, char **argv)
{
	char *args[] = { "", NULL };
	int status;
	pid_t pid, chid;
    // posix_spawn creaza un nou proces copil care va executa un fisier specificat
	// combina functionalitatile fork() + exec()
	if ((posix_spawn(&chid, "/bin/date", 0, NULL, args, NULL)) != 0)
		perror("spawn() failed");
	else
		printf("\nParinte (pid= %d): ID-ul procesului fiu este chid = %d\n",
		       getpid(), chid);
	// /bin/date afiseaza data curenta si timpul
	if ((posix_spawn(&chid, "/bin/cal", 0, NULL, args, NULL)) != 0)
		perror("spawn() failed");
	else
		printf("\nParinte (pid = %d): ID-ul procesului fiu este chid = %d\n",
		       getpid(), chid);
	// /bin/cal afiseaza data in Terminal
	while (1) {
		if ((pid = wait(&status)) == -1) {
			perror("wait() failed (nu mai sunt procese fiu?)");
			exit(EXIT_FAILURE);
		}
		printf("\n\nS-a terminat procesul fiu cu chid = %d\n", chid);
		/*return (EXIT_SUCCESS);*/
	}
}
