--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -234,11 +234,11 @@
 #include "chrome/browser/ui/webui/conflicts/conflicts_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
@@ -382,7 +382,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if defined(OS_CHROMEOS)
@@ -755,7 +755,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
 #endif
@@ -803,17 +803,17 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
     return &NewWebUI<media_router::MediaRouterInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUIBrowserSwitchHost)
     return &NewWebUI<BrowserSwitchUI>;
 #endif
