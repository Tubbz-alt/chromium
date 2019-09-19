--- chrome/renderer/chrome_content_renderer_client.cc.orig	2019-09-09 21:55:11 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -1038,7 +1038,7 @@ WebPlugin* ChromeContentRendererClient::CreatePlugin(
       }
 
       case chrome::mojom::PluginStatus::kRestartRequired: {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         placeholder = create_blocked_plugin(
             IDR_BLOCKED_PLUGIN_HTML,
             l10n_util::GetStringFUTF16(IDS_PLUGIN_RESTART_REQUIRED,
