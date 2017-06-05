//
//  QLRoomViewController.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/24.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "QLRoomViewController.h"
#import "QLCocos2dViewController.h"

@interface QLRoomViewController ()

@end

@implementation QLRoomViewController
{
    bool isDrawState;
    QLCocos2dViewController *vc;
    int _type;
}

-(instancetype)initWithType:(int)type
{
    self = [super init];
    if (self) {
        _type = type;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    CGFloat width = 150, height = 50;
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(self.view.bounds.size.width / 2 - width / 2, CGRectGetHeight(self.view.frame) - 100, width, height);
    [button setTitle:@"开始/停止" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(dragonBonesButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    vc = [[QLCocos2dViewController alloc] initWithType:_type];
    [self addChildViewController:vc];
    [self.view addSubview:vc.view];
}

-(void)dragonBonesButtonClick:(id)sender
{
    isDrawState = !isDrawState;
    [vc setDrawSceneState:isDrawState];
    vc.view.hidden = !isDrawState;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
