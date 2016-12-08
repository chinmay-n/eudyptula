#include <linux/init.h>
#include <linux/slab.h>
#include <linux/usb.h>
#include <linux/device.h>
#include <linux/hid.h>
#include <linux/usb/input.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("c78fb75d06e4");


static struct usb_device_id hello_table [] = {
        { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
        USB_INTERFACE_SUBCLASS_BOOT,
            USB_INTERFACE_PROTOCOL_KEYBOARD) },
    { }
};

static int hello_probe(struct usb_interface *intf,
	const struct usb_device_id *id)
{
	return 0;
}

static void hello_disconn(struct usb_interface *intf)
{
	return;
}

struct usb_driver hello_driver = {
.name = "hello",
.id_table = hello_table,
.probe = hello_probe,
.disconnect = hello_disconn,
};

MODULE_DEVICE_TABLE(usb, hello_table);

static void __exit hello_cleanup(void)
{
	usb_deregister(&hello_driver);
	pr_notice("Module by Chinmay Nivsarkar\n");
}

static int __init hello_module_init(void)
{
	if(!usb_register(&hello_driver))
		pr_debug("Hello World");
	else
		pr_debug("Module inserted");

	return 0;
}


module_init(hello_module_init);
module_exit(hello_cleanup);
