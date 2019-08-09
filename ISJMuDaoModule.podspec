#
# Be sure to run `pod lib lint ISJMuDaoModule.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ISJMuDaoModule'
  s.version          = '0.1.1'
  s.summary          = '花吧SDK&&借吧SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  花吧、借吧SDK的主要工程文件
                       DESC

  s.homepage         = 'https://github.com/WJLollipop/ISJMuDaoSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'WJLollipop' => 'frank204866@gmail.com' }
  s.source           = { :git => 'https://github.com/WJLollipop/ISJMuDaoSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  # s.source_files = 'ISJMuDaoModule/Classes/**/*'
  s.vendored_frameworks = 'ISJMuDaoModule/Classes/*.{framework}'
  s.resource = 'ISJMuDaoModule/Assets/FanbeiCreditSDKResource.bundle'
  
  # s.resource_bundles = {
  #   'ISJMuDaoModule' => ['ISJMuDaoModule/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
