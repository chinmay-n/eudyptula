#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_module_init(void)
{
    printk(KERN_DEBUG "Hello World");
    return 0;
}

static void __exit hello_cleanup(void)
{
    printk(KERN_DEBUG "Module by Chinmay Niv
		sarkar<mit.chinmayn@gmail.com>");
}

module_init(hello_module_init);
module_exit(hello_cleanup);
