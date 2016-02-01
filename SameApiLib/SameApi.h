//
//  SameApi.h
//  SameApi
//
//  Created by LiuYang on 15/6/23.
//  Copyright (c) 2015年 same. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SameAppShareDataPackage;

typedef void(^SameAppDataSharingSendDataHandler)(BOOL sent, NSError *error);
typedef void(^SameAppDataSharingHandler)(SameAppShareDataPackage *retrievedPackage, NSString *appkey, NSError *error);

extern NSString *kReadPasteboardDataQuery;

typedef enum
{
    SameAppDataSharingErrorTypeNoApplicationAvailableForScheme = 100,
    SameAppDataSharingErrorTypeNoPasteboardForName = 200,
    SameAppDataSharingErrorTypeNoDataFound = 300,
} ENHAppDataSharingErrorType;

@interface SameApi : NSObject

/**
 注册第三方App，一般放在didFinishLaunchingWithOptions里调用
 * @param key 第三方 App key
 **/
+(BOOL) registerApp:(NSString *)key;

/**
 检测same app是否安装
 **/
+(BOOL) isSameAppInstalled;

/**
 分享数据到same
 * @param channelId 要分享到的same的频道Id
 * @param dataPackage 分享的统一数据包，里面是各种media，比如视频、图文、打卡
 * @param completionHandler 分享结果的回调，这里只是说打包数据调用same成功了，并不代表已经在same发表了内容
 **/
+(void) sendDataToApplicationWithScheme:(NSUInteger)channelId
                           dataPackage:(SameAppShareDataPackage *)dataPackage
                     completionHandler:(SameAppDataSharingSendDataHandler)completionHandler;

/**
 处理分享到same的数据，第三方App不用关心此接口
 **/
+(void) handleSendPasteboardDataURL:(NSURL *)sendPasteboardDataURL
                 completionHandler:(SameAppDataSharingHandler)completionHandler;
@end

NSDictionary *DictionaryFromURLEncodedStringWithEncoding(NSString *URLEncodedString, NSStringEncoding encoding);

