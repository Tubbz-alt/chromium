--- base/base_switches.cc.orig	2020-09-08 19:13:57 UTC
+++ base/base_switches.cc
@@ -117,7 +117,7 @@ const char kDisableHighResTimer[] = "disable-highres-t
 const char kDisableUsbKeyboardDetect[]      = "disable-usb-keyboard-detect";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // The /dev/shm partition is too small in certain VM environments, causing
 // Chrome to fail or crash (see http://crbug.com/715363). Use this flag to
 // work-around this issue (a temporary directory will always be used to create
@@ -142,7 +142,7 @@ const char kReachedCodeSamplingIntervalUs[] =
     "reached-code-sampling-interval-us";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Controls whether or not retired instruction counts are surfaced for threads
 // in trace events on Linux.
 //
