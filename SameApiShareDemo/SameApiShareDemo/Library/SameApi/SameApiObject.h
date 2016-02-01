//
//  SameApiObject.h
//  SameApi
//
//  Created by LiuYang on 15/6/23.
//  Copyright (c) 2015年 same. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SameApiObject : NSObject

@end

#pragma mark - SameShareMediaObject
extern NSString *kSameAppShareDataPackageUTI;

typedef enum {
    SameAppShareMediaIsInvalid = 0,
    SameAppShareMediaIsImage = 1,
    SameAppShareMediaIsVideo = 2,
    SameAppShareMediaIsCheckin = 3,
}SameAppShareMediaType;

static NSString *kSameMediaObjDescEncodeKey = @"kSameMediaObjDescEncodeKey";

@protocol SameShareMediaObject <NSObject>
- (NSData *)dataRepresentation;
@optional
@property (nonatomic, copy)NSString *mediaDescription;
@end

@interface SameAppShareDataPackage : NSObject <NSCoding>

// Metadata
@property (copy, nonatomic, readonly) NSString *sourceApplicationName;
@property (copy, nonatomic, readonly) NSString *sourceApplicationIdentifier;
@property (copy, nonatomic, readonly) NSString *sourceApplicationVersion;
@property (copy, nonatomic, readonly) NSString *sourceApplicationBuild;
@property (nonatomic, readonly) SameAppShareMediaType mediaType;

// Application Data
@property (strong, nonatomic, readonly) NSData *payload;

- (id)initWithSourceApplicationName:(NSString *)sourceApplicationName
        sourceApplicationIdentifier:(NSString *)sourceApplicationIdentifier
           sourceApplicationVersion:(NSString *)sourceApplicationVersion
             sourceApplicationBuild:(NSString *)sourceApplicationBuild
                            payload:(NSData *)payload
                          mediaType:(SameAppShareMediaType)mediaType;


+ (SameAppShareDataPackage *)dataPackageForCurrentApplicationWithMediaObj:(id)mediaObj;

- (NSData *)dataRepresentation;
+ (SameAppShareDataPackage *)unarchivePackageData:(NSData *)data;

@end

#pragma mark - SameShareImageObject
@interface SameShareImageObject : NSObject <NSCoding,SameShareMediaObject>

@property (copy, nonatomic) UIImage *imgData;
@property (copy, nonatomic) NSString *txt;

+ (SameShareImageObject *)shareImgWithData:(NSData *)data;
@end

#pragma mark - SameShareVideoObject
@interface SameShareVideoObject : NSObject <NSCoding,SameShareMediaObject>

@property (copy, nonatomic) NSString *videoUrl;
@property (copy, nonatomic) NSString *coverUrl;
@property (copy, nonatomic) NSString *txt;

+ (SameShareVideoObject *)shareVideoWithData:(NSData *)data;
@end

#pragma mark - SameShareCheckinObject
@interface SameShareCheckinObject : NSObject <NSCoding,SameShareMediaObject>

@property (copy, nonatomic) UIImage *image;
@property (copy, nonatomic) NSString *value1;
@property (copy, nonatomic) NSString *value2;

+ (SameShareCheckinObject *)shareCheckinWithData:(NSData *)data;

@end

