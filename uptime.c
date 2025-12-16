#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int ticks = uptime();
  // En XV6, 100 ticks son aprox 1 segundo.
  printf(1, "uptime: %d ticks (~%d segundos)\n", ticks, ticks/100);
  exit();
}

