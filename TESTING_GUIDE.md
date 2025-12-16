# Guía de Pruebas para `syscallinfo`

Esta guía describe cómo probar el programa `syscallinfo` y la funcionalidad de conteo de llamadas al sistema.

## Prerrequisitos

Asegúrate de tener el ambiente de compilación de xv6 configurado correctamente. Esto incluye:

- Un compilador cruzado de GCC para i386 (por ejemplo, `i386-jos-elf-gcc`).
- QEMU para emular el sistema operativo.
- `make` para automatizar el proceso de compilación.

## Pasos para Probar

### 1. Compilar y Ejecutar xv6

1.  Abre una terminal en el directorio `repo` (o `xv6`).
2.  Ejecuta `make` para compilar el kernel y los programas de usuario.
3.  Ejecuta `make qemu` para iniciar xv6 en el emulador QEMU.

### 2. Probar el Resumen de `syscallinfo`

Una vez que estés en la terminal de xv6 dentro de QEMU:

1.  Ejecuta el comando `ls`. Este comando realiza varias llamadas al sistema para funcionar (como `exec`, `fork`, `wait`, `open`, `read`, `fstat`, `close`).
2.  A continuación, ejecuta `syscallinfo`. Deberías ver una salida similar a esta, mostrando las llamadas al sistema que se han ejecutado y su recuento:

    ```
    Resumen de recuentos de llamadas al sistema:
    fork: 1
    wait: 2
    exec: 2
    open: 3
    read: 3
    fstat: 3
    close: 3
    ... (y otras llamadas al sistema)
    ```

    *Nota: Los números exactos pueden variar dependiendo de las acciones que hayas realizado antes de ejecutar `syscallinfo`.*

### 3. Probar el Recuento de una Llamada al Sistema Específica (`getpid`)

La llamada al sistema `getpid` (número 11) es invocada por varios programas. Para probar que el contador se incrementa, puedes seguir estos pasos:

1.  **Verificar el contador inicial:** En la terminal de xv6, ejecuta `syscallinfo 11` para ver el número inicial de veces que se ha llamado a `getpid`.
2.  **Ejecutar un comando:** Ejecuta cualquier comando simple, como `ls`. El shell (la línea de comandos) creará un nuevo proceso y esperará a que termine, lo cual involucra llamadas a `fork`, `exec` y `wait`. El programa `ls` en sí mismo también hace llamadas al sistema.
3.  **Verificar el incremento:** Vuelve a ejecutar `syscallinfo 11`. Notarás que el contador para `getpid` ha aumentado.
4.  **Prueba más exhaustiva con `usertests`:**
    *   Ejecuta `syscallinfo 11` para ver el contador actual.
    *   Ejecuta el programa `usertests`. Este programa realiza una gran cantidad de pruebas y llama a `getpid` en varias de ellas (por ejemplo, en el test `mem`).
    *   Una vez que `usertests` termine, ejecuta `syscallinfo 11` de nuevo. Verás un incremento significativo en el contador.

### 4. Probar con `tracetest`

También puedes usar el programa `tracetest` para verificar que las llamadas al sistema se están contando.

1.  En la terminal de xv6, ejecuta `tracetest 2048` (2048 es 2^11, para `getpid`).
2.  Luego, ejecuta `syscallinfo 11`. El recuento de `getpid` debería haber aumentado en 1.
