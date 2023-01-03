Pod::Spec.new do |s|
  s.name                  = "Sparkcentral"
  s.version               = "7.0.0"
  s.summary               = "Sparkcentral ios SDK for customers"
  s.homepage              = "https://sparkcentral.com/"
  s.author                = { "Sparkcentral" => "dev@sparkcentral.com" }
  s.source 	              = { :git => "https://github.com/sparkcentral/sparkcentral-ios.git", :tag =>"7.0.0" }
  s.license               = { :type => "Commercial", :text => "https://www.sparkcentral.com/tos/" }
  s.preserve_paths        = "Sparkcentral.xcframework/*"
  s.frameworks            = "Sparkcentral", "CoreText", "SystemConfiguration", "CoreTelephony", "Foundation", "CoreGraphics", "UIKit", "QuartzCore", "AssetsLibrary", "Photos", "AVFoundation", "CFNetwork"
  s.library               = "icucore"
  s.xcconfig              = { "FRAMEWORK_SEARCH_PATHS" => "$(PODS_ROOT)/Sparkcentral" }
  s.vendored_frameworks   = "Sparkcentral.xcframework"
  s.requires_arc          = true
  s.platform              = :ios
  s.ios.deployment_target = '8.0'
end
