//
//  JsObjCManager.h
//  JavaScriptAndObjectiveC
//
//  Created by grx on 2019/8/14.
//  Copyright © 2019 huangyibiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol JavaScriptObjectiveCDelegate <JSExport>

/** =========js调起oc系统方法无传参========== */
- (void)callSystemCamera;
/** =========js调起oc系统方法并传参给oc(在JS中调用时，函数名应该为showAlertMsg(arg1, arg2))======= */
- (void)showAlert:(NSString *)title msg:(NSString *)msg;
/** =========js调起oc系统方法并传参给oc(字典数据)========== */
- (void)callWithDict:(NSDictionary *)params;
/** =========JS调用Oc，然后在OC中通过调用JS方法来传值给JS========== */
- (void)jsCallObjcAndObjcCallJsWithDict:(NSDictionary *)params;

/** =========OC调用JS方法==================== */
- (void)ocCallJsFunc;//无参数
- (void)ocCallJsParamFunc;//传参给js

@end

@interface JsObjCManager : NSObject<JavaScriptObjectiveCDelegate>

@property (nonatomic, weak) JSContext *jsContext;
@property (nonatomic, weak) UIWebView *webView;

@end

NS_ASSUME_NONNULL_END
