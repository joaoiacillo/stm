#include <stdio.h>
#include <stdlib.h>

void print_help()
{
  printf("usage: stm [OPTIONS] [ARGUMENTS]\n\n"
         "  Simple Linux Task Manager. Made by @joaoiacillo.\n\n"
         "  Running this program without any options and arguments\n"
         "  will result in a list of all the processes currently\n"
         "  active in the system, following the pattern:\n"
         "    [PID]: NAME - MEMORY USAGE\n\n"
         "Options:\n"
         "  -h            Prints the help message.\n"
         "  -k PID        Kills the process of PID\n");
  exit(0);
}
