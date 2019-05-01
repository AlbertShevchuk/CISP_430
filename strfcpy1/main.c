#include <stdio.h>
#include "strfcpy.h"

int main()
{
  char src[256] = "this is a string\n";
  char dest[256];
  char allow[256] = "aeiou";

  fgets(src, sizeof(src), stdin);
  printf("%s\n",strfcpy(dest, src, allow));
  return 0;
}
