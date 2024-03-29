#ifndef _LP_PROC_H
#define _LP_PROC_H

#include <dirent.h>

/// Structure for holding a process information.
typedef struct
{
  char name[128];
  char pid[8];
  char memsize[64];
} proc_t;

/// Structure for holding the process dir information.
typedef struct
{
  char curpid[8];
  DIR *dir;
} procdir_t;

/// Reads a process of pid into proc
extern void procread(proc_t *, const char *);

/// Opens the process directory into procd
extern void openpdir(procdir_t *);

/// Reads the next process dir and returns 1 if it exists, 0 otherwise.
/// Auto closes the procd once no more processes exist.
extern int procdnxt(procdir_t *);

#endif // _LP_PROC_H
