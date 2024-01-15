#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

#include "help.h"
#include "strutils.h"
#include "proc.h"

void proclist()
{
  procdir_t procd;
  openpdir (&procd);

  while (procdnxt (&procd))
  {
    proc_t proc;
    procread (&proc, procd.curpid);
    printf ("[%s]: %s - %s\n", proc.pid, proc.name, proc.memsize);
  }
}

void prockill(pid_t pid)
{
  int exitcode = kill(pid, SIGKILL);

  if (exitcode < 0) // error
  {
    perror("Error on killing the process");
    exit(1);
  }

  printf("Success");
  exit(0);
}

int main(const int argc, const char *argv[])
{
  if (argc >= 2)
  {
    if (! strcmp(argv[1], "-h"))
    {
      print_help();
    }
    else if (! strcmp(argv[1], "-k"))
    {
      if (argc < 3)
      {
        fprintf(stderr, "kill operation (-k) requires a PID as argument");
        exit(1);
      }

      pid_t pid = strtol(argv[2], NULL, 10);
      prockill(pid);
    }
  }

  proclist();
  return 0;
}
