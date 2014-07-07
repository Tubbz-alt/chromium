--- ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2014-06-30 21:04:13.000000000 +0200
+++ ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi	2014-07-01 22:46:25.000000000 +0200
@@ -107,6 +107,11 @@
             ],
           },
         }],
+        ['os_bsd==1', {
+          'include_dirs': [
+            '<(prefix_dir)/include',
+          ],
+        }],
         ['OS!="win" and OS!="mac" and use_x11==0', {
           'sources': [
             "mouse_cursor_monitor_null.cc",
