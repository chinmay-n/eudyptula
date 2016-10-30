#include <linux/init.h>
#include <linux/slab.h>
#include <linux/usb.h>
#include <linux/device.h>
#include <linux/hid.h>
#include <linux/usb/input.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("c78fb75d06e4");

static void hello_cleanup(void)
{
	pr_notice("Module by Chinmay Nivsarkar\n");
}

static int __init hello_module_init(void)
{
	pr_debug("Hello World");

	return 0;
}

static struct usb_device_id hello_table [] = {
        { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
        USB_INTERFACE_SUBCLASS_BOOT,
            USB_INTERFACE_PROTOCOL_KEYBOARD) },
    { }
};

struct usb_driver hello_driver = {
.name = "hello",
.id_table = hello_table,
.probe = usb_hello_init,
.disconnect = usb_hello_exit,
};

MODULE_DEVICE_TABLE(usb, hello_table);

static int usb_hello_init(void)
{	
	int ret = device_register(&hello);
	if(ret)
		pr_notice("Failed to register");
	pr_notice("Used hello driver");
	return ret;
}

static void usb_hello_exit(void)
{
	usb_deregister(&hello);
}

module_init(hello_module_init);
module_exit(hello_cleanup);
