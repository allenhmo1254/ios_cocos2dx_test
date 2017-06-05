//
//  QLGiftView.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/20.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "QLCocos2dView.h"
#import "CCEAGLView-ios.h"
#import "cocos2d.h"
#import "QLCocos2dAppDelegate.h"

static QLCocos2dAppDelegate s_sharedApplication;

@interface QLCocos2dView ()

@end

@implementation QLCocos2dView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self _initGLView];
    }
    return self;
}

#pragma mark - private

-(void)_initGLView
{
    cocos2d::Application *application = cocos2d::Application::getInstance();
    application->initGLContextAttrs();
    cocos2d::GLViewImpl::convertAttrs();
    // Init the CCEAGLView
    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: [self bounds]
                                         pixelFormat: (__bridge NSString*)cocos2d::GLViewImpl::_pixelFormat
                                         depthFormat: cocos2d::GLViewImpl::_depthFormat
                                  preserveBackbuffer: NO
                                          sharegroup: nil
                                       multiSampling: NO
                                     numberOfSamples: 0 ];
    // Enable or disable multiple touches
    [eaglView setMultipleTouchEnabled:NO];
    [eaglView setUserInteractionEnabled:NO];
    [eaglView setBackgroundColor:[UIColor clearColor]];
    
    // Use RootViewController manage CCEAGLView
    [self addSubview:eaglView];
    
    // IMPORTANT: Setting the GLView should be done after creating the RootViewController
    cocos2d::GLView *glview = cocos2d::GLViewImpl::createWithEAGLView((__bridge void*)eaglView);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    
    application->run();
}

-(void)startAnimation
{
    s_sharedApplication.applicationWillEnterForeground();
}

-(void)stopAnimation
{
    s_sharedApplication.applicationDidEnterBackground();
}

-(void)end
{
    s_sharedApplication.end();
}

@end
