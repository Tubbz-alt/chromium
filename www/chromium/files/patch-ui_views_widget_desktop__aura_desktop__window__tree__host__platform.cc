--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2019-09-09 21:55:47 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -104,7 +104,7 @@ void DesktopWindowTreeHostPlatform::OnNativeWidgetCrea
     const Widget::InitParams& params) {
   native_widget_delegate_->OnNativeWidgetCreated();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Setup a non_client_window_event_filter, which handles resize/move, double
   // click and other events.
   DCHECK(!non_client_window_event_filter_);
@@ -551,7 +551,7 @@ void DesktopWindowTreeHostPlatform::Relayout() {
 }
 
 void DesktopWindowTreeHostPlatform::RemoveNonClientEventFilter() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!non_client_window_event_filter_)
     return;
 
