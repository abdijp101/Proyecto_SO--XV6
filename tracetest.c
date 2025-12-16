#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  if(argc <= 1){
    printf(1, "usage: tracetest syscall_mask\n");
    exit();
  }

  int mask = atoi(argv[1]);
  trace(mask);

  printf(1, "Starting trace test with mask %d\n", mask);

  // Any syscall will be traced here.
  // For example, getpid() is syscall 11.
  getpid();

  trace(0);
  printf(1, "Trace test finished.\n");

  exit();
}

