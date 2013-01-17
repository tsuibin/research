//-------------------------------------------------------------------
//  newproc.c
//
//  programmer: <YOUR NAME>
//  date begun: 20 AUG 2012
//-------------------------------------------------------------------
#include <linux/module.h>   // for init_module() 
#include <linux/proc_fs.h>  // for create_proc_read_entry() 
char modname[] = "newproc";
int my_proc_read( char *buf, char **start, off_t off, int count, 
                         int *eof, void *data ) 
{
    int len;
    len = 0;
    len += sprintf( buf+len, "\n%s\n", modname );
    len += sprintf( buf+len, "\n" );
    return  len;
}
static int __init newproc_init( void )
{
    printk( "<1>\nInstalling \'%s\' module\n", modname );
    create_proc_read_entry( modname, 0, NULL, my_proc_read, NULL );
    return  0;  //SUCCESS
}
static void __exit newproc_exit(void )
{
    remove_proc_entry( modname, NULL );
    printk( "<1>Removing \'%s\' module\n", modname );
}
module_init( newproc_init );
module_exit( newproc_exit );
MODULE_LICENSE("GPL");
