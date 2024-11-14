#include <linux/kernel.h>       // Para usar funciones de impresión como printk
#include <linux/module.h>       // Para crear módulos en el kernel
#include <linux/init.h>         // Para usar las funciones de inicialización y finalización del módulo
#include <linux/kthread.h>      // Para trabajar con hilos del kernel (kthreads)
#include <linux/sched.h>        // Para trabajar con la programación de tareas (gestión de hilos)
#include <linux/delay.h>        // Para usar la función msleep (dormir el hilo un tiempo)
#include <linux/sched/signal.h> // Para manejar señales de control de tareas

static struct task_struct *kthread_1 = NULL; // Puntero para el primer hilo
static struct task_struct *kthread_2 = NULL; // Puntero para el segundo hilo

static int hilo_1(void *params) {
    while(!kthread_should_stop()) {
        printk("cabrera_martin_ej02: Hola desde el Hilo N°1");
        msleep(500); // Duerme 500 ms
    }
    return 0;
}

static int hilo_2(void *params) {
    while(!kthread_should_stop()) {
        printk("cabrera_martin_ej02: Hola desde el Hilo N°2");
        msleep(500); // Duerme 500 ms
    }
    return 0;
}

static int __init ej02_module_init(void) {
    kthread_1 = kthread_create(hilo_1, NULL, "kthread_1");
    if(kthread_1 == NULL) {
        printk(KERN_INFO "cabrera_martin_ej02: No se pudo hacer el Primer Hilo");
        return -1;
    }

    kthread_2 = kthread_create(hilo_2, NULL, "kthread_2");
    if(kthread_2 == NULL) {
        printk(KERN_INFO "cabrera_martin_ej02: No se pudo hacer el Segundo Hilo");
        return -1;
    }

    wake_up_process(kthread_1);
    wake_up_process(kthread_2);

    return 0;
}

static void __exit ej02_module_exit(void) {
    kthread_stop(kthread_1);
    kthread_stop(kthread_2);
}

module_init(ej02_module_init);
module_exit(ej02_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("");
MODULE_DESCRIPTION("");

