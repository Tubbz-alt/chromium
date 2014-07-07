--- ./chrome/browser/extensions/api/serial/serial_api.cc.orig	2014-06-30 21:02:27.000000000 +0200
+++ ./chrome/browser/extensions/api/serial/serial_api.cc	2014-07-07 13:59:49.000000000 +0200
@@ -84,7 +84,7 @@
 
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
-
+#if !defined(OS_FREEBSD) //XXX(rene) quick hack
   device::SerialDeviceInfoList devices;
   scoped_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
@@ -106,6 +106,7 @@
   }
 
   results_ = serial::GetDevices::Results::Create(out_devices);
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {}
