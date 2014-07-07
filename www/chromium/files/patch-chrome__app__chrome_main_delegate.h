--- ./chrome/app/chrome_main_delegate.h.orig	2014-06-30 21:02:36.000000000 +0200
+++ ./chrome/app/chrome_main_delegate.h	2014-07-01 22:46:25.000000000 +0200
@@ -35,7 +35,7 @@
   virtual bool ShouldSendMachPort(const std::string& process_type) OVERRIDE;
   virtual bool DelaySandboxInitialization(
       const std::string& process_type) OVERRIDE;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   virtual content::ZygoteForkDelegate* ZygoteStarting() OVERRIDE;
   virtual void ZygoteForked() OVERRIDE;
 #endif
