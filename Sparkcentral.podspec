Pod::Spec.new do |s|
  s.name                  = "Sparkcentral"
  s.version               = "2.1.1"
  s.summary               = "Sparkcentral ios SDK for customers"
  s.homepage              = "https://sparkcentral.com/"
  s.author                = { "Sparkcentral" => "dev@sparkcentral.com" }
  s.source 	              = { :git => "https://github.com/sparkcentral/sparkcentral-ios.git", :tag =>"2.1.1" }
  s.license               = { :type => "Commercial", :text => "https://www.sparkcentral.com/tos/" }
  s.source_files          = "Sparkcentral.framework/Headers/Sparkcentral.h", "Sparkcentral.framework/Headers/SKCSettings.h", "Sparkcentral.framework/Headers/SKCUser.h", "Sparkcentral.framework/Headers/SKCConversation.h", "Sparkcentral.framework/Headers/SKCMessage.h", "Sparkcentral.framework/Headers/SKCMessageAction.h", "Sparkcentral.framework/Headers/SKCConversationActivity.h", "Sparkcentral.framework/Headers/SKCCoordinates.h"
  s.preserve_paths        = "Sparkcentral.framework/*"
  s.module_map            = "Sparkcentral.framework/Modules/module.modulemap"
  s.frameworks            = "Sparkcentral", "CoreText", "SystemConfiguration", "CoreTelephony", "Foundation", "CoreGraphics", "UIKit", "QuartzCore", "AssetsLibrary", "Photos", "AVFoundation", "CFNetwork"
  s.library               = "icucore"
  s.xcconfig              = { "FRAMEWORK_SEARCH_PATHS" => "$(PODS_ROOT)/Sparkcentral" }
  s.vendored_frameworks   = "Sparkcentral.framework"
  s.requires_arc          = true
  s.platform              = :ios
  s.ios.deployment_target = '8.0'
end
