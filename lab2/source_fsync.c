#include "apue.h"
#ifndef BUFFSIZE
#define BUFFSIZE 100
#endif

int main(void)
{
		int		n;
		char	buf[BUFFSIZE];
		int fd_out;

		fd_out = open("/dev/null", O_WRONLY);

		while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		{
			fsync(STDIN_FILENO);
			if (write(fd_out, buf, n) != n)
				err_sys("write error");
		}

		if (n < 0)
				err_sys("read error");


		exit(0);
}

