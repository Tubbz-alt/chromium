--- ./third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-06-30 21:03:04.000000000 +0200
+++ ./third_party/libXNVCtrl/libXNVCtrl.gyp	2014-07-01 22:46:25.000000000 +0200
@@ -13,6 +13,9 @@
         'NVCtrlLib.h',
         'nv_control.h',
       ],
+      'include_dirs': [
+        '<(prefix_dir)/include',
+      ],
     },
   ],
 }
