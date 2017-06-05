//
//  QLGiftViewCache.h
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/20.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import <UIKit/UIKit.h>

@class QLCocos2dView;

@interface QLCocos2dManager : NSObject

@property(nonatomic, assign)int animType;
@property(nonatomic, assign)int isDrawScene;

/**
 *  分享管理器对象
 *
 *  @return MSVideoManager* 管理器对象
 */
+(instancetype)shareInstance;

/**
 *  创建GLView
 *
 *  @return QLCocos2dView* glview的对象
 */
-(QLCocos2dView *)createGLView;

/**
 *  将GLView从父试图中清空
 */
-(void)removeGLView;

/**
 *  应用切换到后台
 */
-(void)applicationDidEnterBackground;

/**
 *  应用切换到前台
 */
-(void)applicationWillEnterForeground;

/**
 *  开始播放特效
 */
-(void)playEffect;

/**
 *  停止播放特效
 */
-(void)stopEffect;

@end
