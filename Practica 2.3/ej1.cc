/*

Muestra o modifica los atributos de planificación de tiempo real de un proceso.

Establece las políticas:
 chrt [opciones] <prioridad> <orden> [<arg>...]
 chrt [opciones] --pid <prioridad> <pid>

Obtiene las políticas:
 chrt [opciones] -p <pid>

Opciones de las políticas:
 -b, --batch          establece la política SCHED_BATCH
 -d, --deadline       establece la política SCHED_DEADLINE
 -f, --fifo           establece la política SCHED_FIFO
 -i, --idle           establece la política SCHED_IDLE
 -o, --other          establece la política SCHED_OTHER
 -r, --rr             establece la política SCHED_RR (predeterminado)

Opciones de planificación:
 -R, --reset-on-fork       set reset-on-fork flag
 -T, --sched-runtime <ns>  parámetro tiempo de ejecución para DEADLINE
 -P, --sched-periodo <ns>  parámetro tiempo para DEADLINE
 -D, --sched-deadline <ns> parámetro plazo de vencimiento para DEADLINE

Otras opciones:
 -a, --all-tasks      actúa sobre todas las tareas (hilos) de un pid determinado
 -m, --max            muestra las prioridades válidas mínima y máxima
 -p, --pid            actúa sobre el pid existente dado
 -v, --verbose        muestra información sobre el estado

 -h, --help           display this help
 -V, --version        display version

Para más detalles véase chrt(1).



*/
