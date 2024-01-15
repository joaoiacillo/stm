#include "proc.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "strutils.h"

#define LINUX_PROC_DIR "/proc/"

const int procdlen = strlen (LINUX_PROC_DIR);
const int procslen = procdlen + strlen ("/status");

void procread(proc_t *proc, const char *pid)
{
  char *spath = malloc ((procslen + strlen(pid) + 1) * sizeof (char));
  strcpy (spath, LINUX_PROC_DIR);
  strcat (spath, pid);
  strcat (spath, "/status");

  FILE *sf = fopen (spath, "r");
  char buf[4096];

  if (! sf)
  {
    perror ("Error opening file.\n");
    return;
  }

  char name[128], memsize[64];

  while (fgets (buf, sizeof (buf), sf))
  {
    // Name, VmSize
    const char *fname = strtok (buf, "\t");
    char *fvalue = strtok (NULL, "\t");

    // Removes trailing \n at the end
    fvalue[strlen(fvalue) - 1] = '\0';

    if (! strcmp (fname, "Name:"))
    {
      strcpy (name, fvalue);
    }

    if (! strcmp (fname, "VmSize:"))
    {
      strcpy (memsize, strltr(fvalue));
    }
  }

  free (spath);

  strcpy (proc->name, name);
  strcpy (proc->pid, pid);
  strcpy (proc->memsize, memsize);
  return proc;
}

void openpdir(procdir_t *procd)
{
  procd->dir = opendir (LINUX_PROC_DIR);
  strcpy(procd->curpid, "-1");
}

int procdnxt(procdir_t *procd)
{
  struct dirent *ent = readdir (procd->dir);

  // Skipping . and .. links
  while (ent && ! strisdigit (ent->d_name))
  {
    ent = readdir (procd->dir);
  }

  if (!ent) {
    closedir(procd->dir);
    return 0;
  }

  strcpy(procd->curpid, ent->d_name);
  return 1;
}
