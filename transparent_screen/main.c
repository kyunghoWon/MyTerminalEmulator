#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	char *buf;
	while(1)
	{
		buf = (char *)malloc(100);
		printf("kyungho bash@ubuntu:~$ ");
		fgets(buf, 100, stdin);
		// fgets adds '\n' end of the string.
		buf[strlen(buf)-1] = '\0';
		if(strcmp(buf, "exit") == 0)
		{
			break;
		}
		system(buf);
	}
	return 0;
}
