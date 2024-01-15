#include "strutils.h"

#include <string.h>
#include <ctype.h>

int strisdigit(const char *string)
{
  for (int i = 0; i < strlen(string); i++)
  {
    if (! isdigit (string[i]))
    {
      return 0;
    }
  }
  return 1;
}

char *strltr(char *string)
{
  while (isspace ((unsigned char) *string)) string++;

  if (*string)
  {
    return string;
  }

  return string;
}
