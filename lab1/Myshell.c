#include "apue.h"
#include <sys/wait.h>


static void	sig_int(int);		/* our signal-catching function */

int
main(void)
{
		char	buf[MAXLINE];	/* from apue.h */
		pid_t	pid;
		int		status;

		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal error");

		printf("# ");	/* print prompt */
		while (fgets(buf, MAXLINE, stdin) != NULL) {
				if (buf[strlen(buf) - 1] == '\n')
						buf[strlen(buf) - 1] = 0; /* replace newline with null */

				char** file;
				char deli[] = " ";
				int file_count = 0;
				char* start = buf;
				file = malloc(sizeof(char*) * 40);
				for (int i = 0; i < 40; i++)
				{
					file[i] = malloc(sizeof(char) * 40);
				}

				start = strtok(start, deli);
				while (start != NULL)
				{
					strcpy(file[file_count], start);
					file_count++;
					start = strtok(NULL, deli);
				}
				file[file_count] = NULL;

				if(strcmp(file[0], "cd") == 0)
				{
					chdir(file[1]);
				}
				else
				{
				
					if ((pid = fork()) < 0) {
							err_sys("fork error");
					} else if (pid == 0) {		/* child */
							execvp(file[0], file);
							err_ret("couldn't execute: %s", buf);
							exit(127);
					}
	
					/* parent */
					if ((pid = waitpid(pid, &status, 0)) < 0)
							err_sys("waitpid error");
				}
			printf("# ");
		}
		exit(0);
}

		void
sig_int(int signo)
{
		printf("interrupt\n%% ");
}

