#
#  Be sure to run `pod spec lint SLPlayer.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "SLPlayer"
  s.version      = "0.1.5"
  s.summary      = "SLPlayer 是一个多功能的音乐播放器"

s.homepage     = "https://github.com/1kevins/SLplayer"
s.license      = 'MIT'
s.author       = { "kevin lai" => "come_on_yes@163.com" }
s.platform     = :ios, "7.0"
s.ios.deployment_target = "7.0"
s.source       = { :git => "https://github.com/1kevins/SLplayer.git", :tag => s.version}
s.source_files  = 'SLPlayer/SLPlayer-lib/*'
s.requires_arc = true

end
