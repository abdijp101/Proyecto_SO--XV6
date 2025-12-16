#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// Entregable 1: Establecer mascara de rastreo
int
sys_trace(void)
{
  int mask;
  if(argint(0, &mask) < 0)
    return -1;
  myproc()->trace_mask = mask;
  return 0;
}

// Entregable 2: Llamada al sistema para inspeccion de procesos (ps)
int
sys_cps(void)
{
  proc_dump(); // Funcion definida en proc.c
  return 0;
}

extern int syscall_counts[];

// Entregable 3: Copia el array de recuentos de llamadas al sistema
int 
sys_getsyscallinfo(void)
{
    char *syscall_counts_ptr;
    // NOTA: Usamos 26 (tamano fijo) porque syscalls[] es estatico en syscall.c
    // Esto evita el error de compilacion "undeclared" o "invalid application of sizeof"
    int size = sizeof(int) * 26; 

    if (argptr(0, &syscall_counts_ptr, size) < 0)
        return -1;
    memmove(syscall_counts_ptr, syscall_counts, size);
    return 0;
}
