# share-to-same
分享到 same 的 iOS SDK

向 fye@same.com 或者 sevear@same.com 发邮件申请 APP Key，邮件需要附带分享到的频道名、频道ID，需要分享什么类型的内容。
目前分享到same只支持以下类型内容：

* 纯文字
* 纯图片
* 图片+文字
* 视频

## 分享视频内容到same某个频道

```
  [SameApi registerApp:@"#APP-KEY#"];
  SameShareVideoObject *video = [[SameShareVideoObject alloc] init];
  video.videoUrl = @"http://lxcdn.miaopai.com/stream/wx1bBXKBTyJKLKKea4woWg__.mp4";
  video.coverUrl = @"http://wsacdn1.miaopai.com/stream/wx1bBXKBTyJKLKKea4woWg___m.jpg";
  video.txt = @"这是一个测试视频分享的东西";
  SameAppShareDataPackage *package = [SameAppShareDataPackage dataPackageForCurrentApplicationWithMediaObj:video];
  [SameApi sendDataToApplicationWithScheme:#channel_id# dataPackage:package completionHandler:nil];
```
