//
//  QLGiftViewController.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "QLCocos2dViewController.h"
#import "QLCocos2dManager.h"
#import "QLCocos2dView.h"

@interface QLCocos2dViewController ()

@end

@implementation QLCocos2dViewController

-(instancetype)initWithType:(int)type
{
    self = [super init];
    if (self) {
        
        [QLCocos2dManager shareInstance].animType = type;
        
        [self _initGLView];
    }
    return self;
}

- (void)loadView
{
    [super loadView];
}

-(void)viewDidLoad
{
    [super viewDidLoad];
    
    if ([QLCocos2dManager shareInstance].animType == 0) {
        self.title = @"DragonBones动画";
    } else {
        self.title = @"Spine动画";
    }
    
    self.view.userInteractionEnabled = NO;
    self.view.backgroundColor = [UIColor clearColor];
}

- (void)dealloc
{
    [[QLCocos2dManager shareInstance] removeGLView];
    [QLCocos2dManager shareInstance].isDrawScene = 1;
}

-(void)setDrawSceneState:(BOOL)state
{
    if (state) {
        [QLCocos2dManager shareInstance].isDrawScene = 2;
        [[QLCocos2dManager shareInstance] playEffect];
    } else {
        [QLCocos2dManager shareInstance].isDrawScene = 0;
    }
}

#pragma mark - private

-(void)_initGLView
{
    [self.view addSubview:[[QLCocos2dManager shareInstance] createGLView]];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [[QLCocos2dManager shareInstance] applicationDidEnterBackground];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [[QLCocos2dManager shareInstance] applicationWillEnterForeground];
}

@end
