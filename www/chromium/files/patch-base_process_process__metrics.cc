--- base/process/process_metrics.cc.orig	2019-07-24 18:58:02 UTC
+++ base/process/process_metrics.cc
@@ -57,7 +57,7 @@ SystemMetrics SystemMetrics::Sample() {
   SystemMetrics system_metrics;
 
   system_metrics.committed_memory_ = GetSystemCommitCharge();
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetVmStatInfo(&system_metrics.vmstat_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
@@ -75,7 +75,7 @@ std::unique_ptr<Value> SystemMetrics::ToValue() const 
   std::unique_ptr<DictionaryValue> res(new DictionaryValue());
 
   res->SetIntKey("committed_memory", static_cast<int>(committed_memory_));
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   std::unique_ptr<DictionaryValue> meminfo = memory_info_.ToValue();
   std::unique_ptr<DictionaryValue> vmstat = vmstat_info_.ToValue();
   meminfo->MergeDictionary(vmstat.get());
@@ -126,7 +126,7 @@ double ProcessMetrics::GetPlatformIndependentCPUUsage(
 }
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
@@ -138,7 +138,7 @@ int ProcessMetrics::GetIdleWakeupsPerSecond() {
   NOTIMPLEMENTED();  // http://crbug.com/120488
   return 0;
 }
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX)
 int ProcessMetrics::CalculatePackageIdleWakeupsPerSecond(
