--- chrome/browser/about_flags.cc.orig	2019-09-09 21:55:09 UTC
+++ chrome/browser/about_flags.cc
@@ -633,7 +633,7 @@ const FeatureEntry::FeatureVariation
          nullptr}};
 #endif  // OS_ANDROID
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const FeatureEntry::FeatureParam
     kAutofillSaveCreditCardUsesImprovedMessagingStoreCard[] = {
         {autofill::features::
@@ -680,7 +680,7 @@ const FeatureEntry::FeatureVariation
              kAutofillSaveCreditCardUsesImprovedMessagingConfirmAndSaveCard),
          nullptr},
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const FeatureEntry::Choice kMemlogModeChoices[] = {
     {flags_ui::kGenericExperimentChoiceDisabled, "", ""},
@@ -733,7 +733,7 @@ const FeatureEntry::Choice kMemlogSamplingRateChoices[
      heap_profiling::kMemlogSamplingRate5MB},
 };
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -771,7 +771,7 @@ const FeatureEntry::FeatureVariation kOmniboxDocumentP
      base::size(kOmniboxDocumentProviderClientScoring), nullptr},
     {"server and client scores", kOmniboxDocumentProviderServerAndClientScoring,
      base::size(kOmniboxDocumentProviderServerAndClientScoring), nullptr}};
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 const FeatureEntry::FeatureParam kOmniboxUIMaxAutocompleteMatches3[] = {
     {OmniboxFieldTrial::kUIMaxAutocompleteMatchesParam, "3"}};
@@ -836,7 +836,7 @@ const FeatureEntry::FeatureVariation kOmniboxMaxURLMat
     {"6 matches", kOmniboxMaxURLMatches6, base::size(kOmniboxMaxURLMatches6),
      nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const FeatureEntry::FeatureParam kTranslateBubbleUIButton[] = {
     {language::kTranslateUIBubbleKey, language::kTranslateUIBubbleButtonValue}};
@@ -852,7 +852,7 @@ const FeatureEntry::FeatureVariation kTranslateBubbleU
     {"Tab", kTranslateBubbleUITab, base::size(kTranslateBubbleUITab), nullptr},
     {"Button_GM2", kTranslateBubbleUIButtonGM2,
      base::size(kTranslateBubbleUIButton), nullptr}};
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_BSD || OS_CHROMEOS
 
 const FeatureEntry::FeatureParam kOmniboxUIVerticalMargin0px[] = {
     {OmniboxFieldTrial::kUIVerticalMarginParam, "0"}};
@@ -1694,13 +1694,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCloudPrintXpsDescription, kOsWin,
      SINGLE_VALUE_TYPE(switches::kEnableCloudPrintXps)},
 #endif  // OS_WIN
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl2-compute-context",
      flag_descriptions::kWebGL2ComputeContextName,
      flag_descriptions::kWebGL2ComputeContextDescription,
      kOsWin | kOsLinux | kOsCrOS,
      SINGLE_VALUE_TYPE(switches::kEnableWebGL2ComputeContext)},
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl-draft-extensions",
      flag_descriptions::kWebglDraftExtensionsName,
      flag_descriptions::kWebglDraftExtensionsDescription, kOsAll,
@@ -1746,14 +1746,14 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OverrideTranslateTriggerInIndia")},
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"translate-ui-bubble-options", flag_descriptions::kTranslateBubbleUIName,
      flag_descriptions::kTranslateBubbleUIDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(language::kUseButtonTranslateBubbleUi,
                                     kTranslateBubbleUIVariations,
                                     "UseButtonTranslateBubbleUI")},
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS || OS_BSD
 
 #if BUILDFLAG(ENABLE_NATIVE_NOTIFICATIONS) && !defined(OS_CHROMEOS)
     {"enable-native-notifications",
@@ -1824,11 +1824,11 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCrostiniBackupDescription, kOsCrOS,
      FEATURE_VALUE_TYPE(chromeos::features::kCrostiniBackup)},
 #endif  // OS_CHROMEOS
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"terminal-system-app", flag_descriptions::kTerminalSystemAppName,
      flag_descriptions::kTerminalSystemAppDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(features::kTerminalSystemApp)},
-#endif  // OS_CHROMEOS || OS_LINUX
+#endif  // OS_CHROMEOS || OS_LINUX || defined(OS_BSD)
 #if defined(OS_ANDROID)
     {"enable-credit-card-assist", flag_descriptions::kCreditCardAssistName,
      flag_descriptions::kCreditCardAssistDescription, kOsAndroid,
@@ -1907,7 +1907,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          previews::features::kHTTPSServerPreviewsUsingURLLoader)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS,
      SINGLE_VALUE_TYPE(
@@ -2257,7 +2257,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kAndroidNightMode)},
 #endif  // BUILDFLAG(ENABLE_ANDROID_NIGHT_MODE)
 #endif  // OS_ANDROID
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     {"passwords-migrate-linux-to-login-db",
      flag_descriptions::kPasswordsMigrateLinuxToLoginDBName,
      flag_descriptions::kPasswordsMigrateLinuxToLoginDBDescription, kOsLinux,
@@ -2266,7 +2266,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableDbusAndX11StatusIconsName,
      flag_descriptions::kEnableDbusAndX11StatusIconsDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kEnableDbusAndX11StatusIcons)},
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     {"enable-experimental-accessibility-features",
      flag_descriptions::kExperimentalAccessibilityFeaturesName,
      flag_descriptions::kExperimentalAccessibilityFeaturesDescription, kOsCrOS,
@@ -2615,7 +2615,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxLocalEntitySuggestionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxLocalEntitySuggestions)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -2664,7 +2664,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_WITH_PARAMS_VALUE_TYPE(omnibox::kDocumentProvider,
                                     kOmniboxDocumentProviderVariations,
                                     "OmniboxBundledExperimentV1")},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -2875,13 +2875,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kDirectManipulationStylus)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"chrome-colors", flag_descriptions::kChromeColorsName,
@@ -3586,11 +3586,11 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(kClickToCallReceiver)},
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"click-to-call-ui", flag_descriptions::kClickToCallUIName,
      flag_descriptions::kClickToCallUIDescription, kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(kClickToCallUI)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
     {"enable-ambient-authentication-in-incognito",
      flag_descriptions::kEnableAmbientAuthenticationInIncognitoName,
@@ -3694,7 +3694,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kForceEnableSystemAec)},
 #endif  // defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-always-show-server-cards-in-sync-transport",
      flag_descriptions::kAutofillAlwaysShowServerCardsInSyncTransportName,
      flag_descriptions::
@@ -3702,7 +3702,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillAlwaysShowServerCardsInSyncTransport)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PRINT_PREVIEW) && defined(OS_MACOSX)
     {"enable-custom-mac-paper-sizes",
@@ -3711,13 +3711,13 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(printing::features::kEnableCustomMacPaperSizes)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"enable-reopen-tab-in-product-help",
      flag_descriptions::kReopenTabInProductHelpName,
      flag_descriptions::kReopenTabInProductHelpDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feature_engagement::kIPHReopenTabFeature)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"enable-audio-focus-enforcement",
@@ -3738,13 +3738,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableGpuServiceLoggingDescription, kOsAll,
      SINGLE_VALUE_TYPE(switches::kEnableGPUServiceLogging)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-settings-split-by-card-type",
      flag_descriptions::kAutofillSettingsSplitByCardTypeName,
      flag_descriptions::kAutofillSettingsSplitByCardTypeDescription,
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(autofill::features::kAutofillSettingsCardTypeSplit)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"hardware-media-key-handling",
@@ -4070,7 +4070,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kAudioWorkletRealtimeThreadDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kAudioWorkletRealtimeThread)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-autofill-save-credit-card-uses-improved-messaging",
      flag_descriptions::kEnableAutofillSaveCreditCardUsesImprovedMessagingName,
      flag_descriptions::
@@ -4080,7 +4080,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillSaveCreditCardUsesImprovedMessaging,
          kAutofillSaveCreditCardUsesImprovedMessagingVariations,
          "AutofillSaveCreditCardUsesImprovedMessaging")},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
     {"release-notes", flag_descriptions::kReleaseNotesName,
@@ -4162,12 +4162,12 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableSyncUSSNigoriDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kSyncUSSNigori)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControls)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
     {"win-use-native-spellchecker",
@@ -4180,12 +4180,12 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSafetyTipDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kSafetyTipUI)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"animated-avatar-button", flag_descriptions::kAnimatedAvatarButtonName,
      flag_descriptions::kAnimatedAvatarButtonDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAnimatedAvatarButton)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
     {"crostini-webui-installer", flag_descriptions::kCrostiniWebUIInstallerName,
