#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main( int argc, char *argv[] )
{

  int fp, rd;
  char path[1035];
  char *buf;
  buf = (char *)malloc(256);
  scanf("%s", buf);
  sprintf(buf, "%s > ~/kyungho/myProject/proj/lib/cmd", buf);
  system(buf);
  
  /* Open the command for reading. */
  fp = open("cmd", O_RDONLY);
  if (fp == -1) {
    perror("open ");
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while ((rd = read(fp, path, 1035) > 0))
  {
    printf("%s", path);
  }

  /* close */
  close(fp);

  return 0;
}
