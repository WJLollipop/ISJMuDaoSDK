 //
//  FanbeiCreditManager.h
//  FanbeiCreditSDK
//
//  Created by ryan on 2018/6/8.
//  Copyright © 2018年 Fanbei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*
 当前SDK版本为1.6.4
 */
NS_ASSUME_NONNULL_BEGIN

// SDK外部的app类型：【0 SDK demo】【1 爱上街等】【2 阿拉借吧】
typedef NS_ENUM(NSInteger, MuDaoAppType) {
    MuDaoAppTypeSDKDemo = 0,//SDKDemo
    MuDaoAppTypeChannel = 1,//爱上街等渠道
    MuDaoAppTypeALaJieBa = 2//阿拉借吧
};

// 配置SDK的环境：【0测试环境】【1为线上环境】【2预发环境】
typedef NS_ENUM(NSInteger, MuDaoEnvironmentType) {
    MuDaoEnvironmentTypeTest = 0,
    MuDaoEnvironmentTypeOnline = 1,
    MuDaoEnvironmentTypePreview = 2
};

// 花吧入口
typedef NS_ENUM(NSInteger, MuDaoSDKTarget) {
    MuDaoSDKTargetIndex             = 0, // 首页
    MuDaoSDKTargetBill              = 1, // 我的账单页面
    MuDaoSDKTargetLimit             = 2, // 额度页面
    MuDaoSDKTargetAssessment        = 3, // 授权认证页面
    MuDaoSDKTargetAuthList          = 4, // 补充认证页面
    MuDaoSDKTargetProtocol          = 5, // 协议页面
    MuDaoSDKTargetSellProtocol      = 6  // 爱上街销售协议页面
};

@interface FanbeiCreditManager : NSObject

#pragma mark - 初始化沐道SDK
/**
 借吧：对外API
 V1.6.4 新增初始化方法

 @param appId 申请的appId
 @param appKey 申请的appKey
 @param mobile 用户手机号，必须传
 @param appType 枚举类型 0:SDKDemo; 1:爱上街等; 2:阿拉借吧
 @param environmentType 枚举类型 0:测试; 1:线上; 2:预发
 @param customAddr 非测试环境，传nil;测试环境，可以自定义服务器地址，传空默认是`http://btesteca.91ala.com`
 @param didClickAlaJieBa 是否点了阿拉借吧渠道（SDK demo中有入口）
 @param finish 认证结果的回调为yes时可以调取SDK，为no时表示初始化失败
 */
+ (void)initWithAppId:(NSString *)appId appKey:(NSString *)appKey mobile:(NSString *)mobile appType:(MuDaoAppType)appType environmentType:(MuDaoEnvironmentType)environmentType customAddr:(nullable NSString *)customAddr didClickAlaJieBa:(BOOL)didClickAlaJieBa finish:(void(^)(BOOL License))finish;

/**
 如有需要
 自定义花吧H5的测试环境地址
 huabaH5TestAddress为空时，默认为 `https://testhuabah5.ishangjie.com`

 @param huabaH5TestAddress 花吧H5的页面地址，只有在测试环境有效
 */
+ (void)setupTestHuaBaH5PageAddress:(NSString *)huabaH5TestAddress;

/**
 如有需要
 自定义借吧H5的测试环境地址，默认为 `http://testeca.91ala.com:48060`
 
 @param jiebaH5TestAddress 借吧H5的页面地址，只有在测试环境有效
 */
+ (void)setupTestJieBaH5PageAddress:(NSString *)jiebaH5TestAddress;

/**
 在SDK初始化，授权成功后调用

 @param viewController      当前viewController
 @param mobile              用户手机号
 */
+ (void)startFanbeiCredit:(UIViewController *)viewController mobile:(NSString *)mobile;

/**
 芝麻信用完成的回调
 */
+ (void)zmAuthenticateCompleteCallback;

/**
 授权判断

 @param mobile 手机号
 @return 是否授权
 */
+ (BOOL)getLicenseWithMobile:(NSString *)mobile;

//+ (void)configTestEnvironmentServerAddr:(NSString *)serverAddr;

/**
 花吧: 打开SDK的指定页面
 @param viewController viewController
 @param mobile mobile
 @param appToken 应用的token
 @param type type
 @param params 其余参数，现在不需要
 */
+ (void)startFanbeiCredit:(UIViewController *)viewController mobile:(NSString *)mobile appToken:(nullable NSString *)appToken targetType:(MuDaoSDKTarget)type params:(NSDictionary *)params;

/**
 此API为SDKV1.5.1版本新增
 使用花吧功能时，必须配置
 配置支付宝回调schema（花吧支付宝预授权，必须配置）
 
 @param appSchema 外部AppappSchema
 */
+ (void)configAppSchema:(NSString *)appSchema;

/**
 花吧SDK打开外部APP页面(爱上街原生页面)
 @param finish finish
 */
+ (void)backtrackAppFinish:(BOOL(^)(UINavigationController *nav, NSDictionary *params))finish;


/**
 设置是否在console输出sdk的log信息
 
 @param enabled 默认NO(不输出log); 设置为YES, 输出可供调试参考的log信息. 发布产品时必须设置为NO
 */
+ (void)setLogEnabled:(BOOL)enabled;

/**
 获取当前的SDK版本信息
 
 @return 返回SDK的版本号 如 @"1.0.0"
 */
+ (NSString *)getSDKVersion;

/**
 获取SDK的环境信息
 
 @return 1为线上环境，0为测试，2为预发
 */
+ (NSInteger)getSDKOnline;



#pragma mark - 以下为内部接口
/**
 内部接口
 获取当前配置的Schema

 @return 获取当前配置的Schema
 */
+ (NSString *)getCurrentAppSchema;


/**
 内部接口
 是否是阿拉借吧渠道

 @return 是否是阿拉借吧
 */
+ (BOOL)isAlaJiebaChannel;


/**
 内部接口
 是不是阿拉借吧app

 @return YES，阿拉借吧app；NO，不是阿拉借吧app
 */
+ (BOOL)isAlaJiebaApp;

@end

NS_ASSUME_NONNULL_END
