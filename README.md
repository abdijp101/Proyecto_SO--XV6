# Proyecto de Sistemas Operativos - Extensión de xv6

Este proyecto es una extensión del sistema operativo xv6, desarrollado como parte del curso de Sistemas Operativos.

## Integrantes

* Tapia Milaveres, Abdiel Jean Piere	2023-119062
* Vargas Centeno, Jarem Manuel		2023-119065

## Descripción del Proyecto

El objetivo de este proyecto es extender las funcionalidades del sistema operativo xv6 para añadir capacidades de monitoreo y análisis del sistema. Se han implementado las siguientes características:

1.  **Instrumentación de Llamadas al Sistema (`trace`):** Una nueva llamada al sistema que permite trazar la ejecución de otras llamadas al sistema para un proceso específico.
2.  **Contador de Invocaciones de Llamadas al Sistema (`syscallinfo`):** Un mecanismo para contar cuántas veces se ha invocado cada llamada al sistema, junto con un programa de usuario para visualizar estos contadores.

## Funcionalidades Implementadas

### 1. `trace` - Trazador de Llamadas al Sistema

*   **Llamada al sistema:** `int trace(int mask)`
*   **Programa de usuario:** `tracetest`

Esta funcionalidad permite activar un seguimiento de las llamadas al sistema para el proceso actual. La `mask` es un entero que funciona como una máscara de bits, donde cada bit corresponde al número de una llamada al sistema.

**Uso:**

Para probar esta funcionalidad, se ha creado el programa `tracetest`.

```sh
# Trazar la llamada al sistema getpid (número 11)
tracetest 2048
```

### 2. `syscallinfo` - Contador de Llamadas al Sistema

*   **Llamada al sistema:** `int getsyscallinfo(int *counts)`
*   **Programa de usuario:** `syscallinfo`

Esta funcionalidad cuenta cada invocación a las llamadas al sistema desde que el sistema arrancó. El programa `syscallinfo` permite visualizar estos contadores.

**Uso:**

```sh
# Muestra un resumen de todas las llamadas al sistema que se han invocado
syscallinfo

# Muestra el recuento de una llamada al sistema específica (por ejemplo, getpid, número 11)
syscallinfo 11
```
### 3. Comandos de Usuario Extendidos (`uptime`, `ps`)                                                                                                         
Se han implementado comandos de usuario extendidos para proporcionar información adicional sobre el estado del sistema.
#### `uptime` - Mostrar Tiempo de Actividad del Sistema                                               
                                                                                                       
 Este comando muestra el tiempo que el sistema lleva en funcionamiento (en ticks o segundos).          
                                                                                                       
 **Uso:**                                                                                              
                                                                                                       
 ```sh                                                                                                 
 uptime                                                                                                
 ```                                                                                                   
                                                                                                       
#### `ps` - Mostrar Procesos del Sistema                                                              
                                                                                                       
Este comando muestra información sobre los procesos activos en el sistema, incluyendo su PID, estado  
y nombre.                                                                                               
                                                                                                   
**Uso:**                                                                                             
```sh
ps 
```                                                                                

## Instrucciones para Compilar y Ejecutar

1.  **Configurar el ambiente:** Asegúrate de tener el [ambiente de compilación de xv6](https://pdos.csail.mit.edu/6.828/2014/tools.html) configurado (compilador cruzado, QEMU, make).
2.  **Compilar:**
    ```sh
    make
    ```
3.  **Ejecutar:**
    ```sh
    make qemu
    ```
