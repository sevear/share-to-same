//
//  ShareDemoTableViewController.m
//  SameApiShareDemo
//
//  Created by LiuYang on 15/6/23.
//  Copyright (c) 2015年 same. All rights reserved.
//

#import "ShareDemoTableViewController.h"
#import "SameApi.h"
#import "SameApiObject.h"

typedef enum {
    ShareImageAndTextRow = 0,
    ShareImageOnlyRow,
    ShareTextOnlyRow,
    ShareNoinputCheckinRow,
    ShareNuminputCheckinRow,
    ShareTwoValueCheckinRow,
    ShareImageAndNumCheckinRow,
    ShareVideoRow,
} ShareDemoRowType;

@interface ShareDemoTableViewController()
@end

@implementation ShareDemoTableViewController
- (BOOL)prefersStatusBarHidden{
    return YES;
}

#pragma mark - UITableViewDelegate
- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    if (indexPath.row == ShareVideoRow) {
        //视频测试频道 80 代码小花
        [SameApi registerApp:@"10521d827b8c8740d0fed65550999e4650a53439"];
        SameShareVideoObject *video = [[SameShareVideoObject alloc] init];
        video.videoUrl = @"http://lxcdn.miaopai.com/stream/wx1bBXKBTyJKLKKea4woWg__.mp4";
        video.coverUrl = @"http://wsacdn1.miaopai.com/stream/wx1bBXKBTyJKLKKea4woWg___m.jpg";
        video.txt = @"这是一个测试视频分享的东西";
        SameAppShareDataPackage *package = [SameAppShareDataPackage dataPackageForCurrentApplicationWithMediaObj:video];
        [SameApi sendDataToApplicationWithScheme:80 dataPackage:package completionHandler:nil];
    }else if(indexPath.row == ShareTextOnlyRow){
        //1037393 测试 图文频道
        [SameApi registerApp:@"10521d827b8c8740d0fed65550999e4650a53439"];
        SameShareImageObject *imgObj = [[SameShareImageObject alloc] init];
        imgObj.txt = @"这是一个测试文本：“你这么漂亮，这么聪明，身材这么好，又体贴照顾人，将来一定会找到一个好男人的。”“不会的，没有男人配得上我。";
        SameAppShareDataPackage *package = [SameAppShareDataPackage dataPackageForCurrentApplicationWithMediaObj:imgObj];
        [SameApi sendDataToApplicationWithScheme:1037393 dataPackage:package completionHandler:nil];
    }else if(indexPath.row == ShareImageOnlyRow){
        //1037393 测试 图文频道
        [SameApi registerApp:@"10521d827b8c8740d0fed65550999e4650a53439"];
        SameShareImageObject *imgObj = [[SameShareImageObject alloc] init];
        imgObj.imgData = [UIImage imageNamed:@"same_office.jpg"];
        SameAppShareDataPackage *package = [SameAppShareDataPackage dataPackageForCurrentApplicationWithMediaObj:imgObj];
        [SameApi sendDataToApplicationWithScheme:1037393 dataPackage:package completionHandler:nil];
    }else if(indexPath.row == ShareImageAndTextRow){
        //1017286 天涯共此词Ci 图文频道
        [SameApi registerApp:@"same01cec4e07728524f02d8f43dc75443cc"];
        SameShareImageObject *imgObj = [[SameShareImageObject alloc] init];
        imgObj.imgData = [UIImage imageNamed:@"same_office.jpg"];
        imgObj.txt = @"这是一个测试文本：“你这么漂亮，这么聪明，身材这么好，又体贴照顾人，将来一定会找到一个好男人的。”“不会的，没有男人配得上我。";
        SameAppShareDataPackage *package = [SameAppShareDataPackage dataPackageForCurrentApplicationWithMediaObj:imgObj];
        [SameApi sendDataToApplicationWithScheme:1017286 dataPackage:package completionHandler:nil];
    }else if(indexPath.row == ShareNoinputCheckinRow){
        //TODO:
    }else if(indexPath.row == ShareImageAndNumCheckinRow){
        //1159840 测试图+数字打卡频道
        [SameApi registerApp:@"same35f1e831603a7f0e3adfec1c1be58aae"];
        SameShareCheckinObject *checkinObj = [[SameShareCheckinObject alloc] init];
        checkinObj.image = [UIImage imageNamed:@"same_office.jpg"];
        checkinObj.value1 = @"3.2";
        checkinObj.mediaDescription = @"今天跑了3.2公里哦";
        SameAppShareDataPackage *package = [SameAppShareDataPackage dataPackageForCurrentApplicationWithMediaObj:checkinObj];
        [SameApi sendDataToApplicationWithScheme:1159840 dataPackage:package completionHandler:nil];
    }
}
@end
