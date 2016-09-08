--- /home/chinmay/Downloads/coding_style.c	2016-09-06 13:44:37.273345797 +0530
+++ coding_style.c	2016-09-08 23:19:17.599992760 +0530
@@ -1,40 +1,34 @@
-#include <linux/module.h>
-#include <linux/kernel.h>
-#include <asm/delay.h>
-#include <linux/slab.h>
-
-int do_work( int * my_int, int retval ) {
-	int x;
-	int y=*my_int;
-	int z;
-	
-	for(x=0;x< * my_int;++x) {
-		udelay(10);
-	}
-
-	if (y < 10 )
-		// That was a long sleep, tell userspace about it
-		printk("We slept a long time!");
-
-	z = x * y;
-
-	return z;
-}
-
-int
-my_init (void)
-{
-	int x = 10;
-
-	x = do_work(&x, x);
-
-	return x;
-}
-
-void my_exit( void )
-{
-	return;
-}
-
-module_init(my_init);
-module_exit(my_exit);
+#include <linux/module.h>
+#include <linux/kernel.h>
+#include <linux/delay.h>
+#include <linux/slab.h>
+
+int do_work(int *my_int, int retval)
+{
+	int x;
+	int y = *my_int;
+	int z;
+
+	for (x = 0; x < *my_int; ++x)
+		udelay(10);
+	if (y < 10)
+		// That was a long sleep, tell userspace about it
+		pr_debug("We slept a long time!");
+	z = x * y;
+	return z;
+}
+
+int my_init(void)
+{
+	int x = 10;
+
+	x = do_work(&x, x);
+	return x;
+}
+
+void my_exit(void)
+{
+}
+
+module_init(my_init);
+module_exit(my_exit);
\ No newline at end of file
