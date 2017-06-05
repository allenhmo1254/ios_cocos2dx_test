//
//  ViewController.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/17.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "ViewController.h"
#import "QLRoomViewController.h"
#import "QLApngViewController.h"
#import "QLKeyAnimViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.title = @"动画DEMO";
    
    CGFloat width = 150, height = 50;
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];
    button1.frame = CGRectMake(self.view.bounds.size.width / 2 - width / 2, CGRectGetHeight(self.view.bounds) / 2 - height / 2 - 50, width, height);
    [button1 setTitle:@"Spine动画" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(spineButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button0 = [UIButton buttonWithType:UIButtonTypeCustom];
    button0.frame = CGRectMake(self.view.bounds.size.width / 2 - width / 2, CGRectGetHeight(self.view.bounds) / 2 - height / 2, width, height);
    [button0 setTitle:@"序列帧动画" forState:UIControlStateNormal];
    [button0 addTarget:self action:@selector(frameButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button0];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectMake(self.view.bounds.size.width / 2 - width / 2, CGRectGetHeight(self.view.bounds) / 2 - height / 2 + 50, width, height);
    [button2 setTitle:@"Apng动画" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(apngButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
}

-(void)spineButtonClick:(id)sender
{
    QLRoomViewController *vc = [[QLRoomViewController alloc] initWithType:1];
    [self.navigationController pushViewController:vc animated:YES];
}

-(void)frameButtonClick:(id)sender
{
    QLKeyAnimViewController *vc = [[QLKeyAnimViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

-(void)apngButtonClick:(id)sender
{
    QLApngViewController *vc = [[QLApngViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
