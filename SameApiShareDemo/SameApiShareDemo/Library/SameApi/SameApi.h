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
typedef void(^SameAppDataSharingHandler)(SameAppShareDataPackage *retrievedPackage, NSError *error);

extern NSString *kReadPasteboardDataQuery;

typedef enum
{
    SameAppDataSharingErrorTypeNoApplicationAvailableForScheme = 100,
    SameAppDataSharingErrorTypeNoPasteboardForName = 200,
    SameAppDataSharingErrorTypeNoDataFound = 300,
} ENHAppDataSharingErrorType;

@interface SameApi : NSObject
+(BOOL) registerApp:(NSString *)key;

+(void) sendDataToApplicationWithScheme:(NSUInteger)channelId
                           dataPackage:(SameAppShareDataPackage *)dataPackage
                     completionHandler:(SameAppDataSharingSendDataHandler)completionHandler;

+(void) handleSendPasteboardDataURL:(NSURL *)sendPasteboardDataURL
                 completionHandler:(SameAppDataSharingHandler)completionHandler;
@end

NSDictionary *DictionaryFromURLEncodedStringWithEncoding(NSString *URLEncodedString, NSStringEncoding encoding);

