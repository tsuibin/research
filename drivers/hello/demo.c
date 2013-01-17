//-----------------------------------------------------------------
//  kello.c
//
//  This kernel module outputs a brief message to the console.
//
//      compile using: $ mmake hello 
//      install using: $ /sbin/insmod hello.ko
//
//  programmer: ALLAN CRUSE
//  written on: 23 AUG 2007
//-----------------------------------------------------------------
#include <linux/module.h>	// for printk()
static int __init init_hello(void)
{
	printk("\n   Kello, everybody! \n\n");
	return 0;
}

static void __exit exit_hello(void)
{
	printk("\n   Goodbye now... \n\n");
}

MODULE_LICENSE("GPL");
module_init(init_hello);
module_exit(exit_hello);
