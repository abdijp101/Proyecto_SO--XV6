#include "types.h"
#include "stat.h"
#include "user.h"

// Nombres de las llamadas al sistema
static char *syscall_names[] = {
  "",
  "fork",
  "exit",
  "wait",
  "pipe",
  "read",
  "kill",
  "exec",
  "fstat",
  "chdir",
  "dup",
  "getpid",
  "sbrk",
  "sleep",
  "uptime",
  "open",
  "write",
  "mknod",
  "unlink",
  "link",
  "mkdir",
  "close",
  "trace",
  "getsyscallinfo"
};

int
main(int argc, char *argv[])
{
  int syscall_counts[24];
  int syscall_num;

  if (getsyscallinfo(syscall_counts) < 0) {
    printf(1, "Error al obtener la información de las llamadas al sistema\n");
    exit();
  }

  if (argc <= 1) {
    // Imprimir un resumen de todos los recuentos de llamadas al sistema
    printf(1, "Resumen de recuentos de llamadas al sistema:\n");
    for (int i = 1; i < 24; i++) {
      if (syscall_counts[i] > 0) {
        printf(1, "%s: %d\n", syscall_names[i], syscall_counts[i]);
      }
    }
  } else {
    // Imprimir el recuento para una llamada al sistema específica
    syscall_num = atoi(argv[1]);
    if (syscall_num > 0 && syscall_num < 24) {
      printf(1, "Recuento de la llamada al sistema %s: %d\n", syscall_names[syscall_num], syscall_counts[syscall_num]);
    } else {
      printf(1, "Número de llamada al sistema no válido\n");
    }
  }

  exit();
}
