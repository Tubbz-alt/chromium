--- ./net/base/net_util.h.orig	2014-06-30 21:02:51.000000000 +0200
+++ ./net/base/net_util.h	2014-07-01 22:46:25.000000000 +0200
@@ -13,6 +13,9 @@
 #elif defined(OS_POSIX)
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 #include <string>
