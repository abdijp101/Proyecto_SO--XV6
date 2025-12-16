#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  cps(); // Llama a la funcion del kernel (System Call 24)
  exit();
}

