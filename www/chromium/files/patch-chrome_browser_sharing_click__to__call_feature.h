--- chrome/browser/sharing/click_to_call/feature.h.orig	2019-09-16 07:22:52 UTC
+++ chrome/browser/sharing/click_to_call/feature.h
@@ -13,9 +13,9 @@
 extern const base::Feature kClickToCallReceiver;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Feature to allow click to call gets processed on desktop.
 extern const base::Feature kClickToCallUI;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #endif  // CHROME_BROWSER_SHARING_CLICK_TO_CALL_FEATURE_H_
