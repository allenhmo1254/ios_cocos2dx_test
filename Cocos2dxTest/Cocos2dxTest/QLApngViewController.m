//
//  QLApngViewController.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/24.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "QLApngViewController.h"
#import "YYImage.h"
#import "UIImage+GIF.h"

@interface QLApngViewController ()

@end

@implementation QLApngViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    YYImage *image = [YYImage imageNamed:@"1"];
    YYAnimatedImageView *imageView = [[YYAnimatedImageView alloc] initWithImage:image];
    CGFloat width = CGRectGetWidth(imageView.frame), height = CGRectGetHeight(imageView.frame);
    imageView.frame = CGRectMake(CGRectGetWidth(self.view.frame) / 2 - width / 2, CGRectGetHeight(self.view.frame) / 2 - height, width, height);
    [self.view addSubview:imageView];
    
    UIImage *gifImage = [UIImage sd_animatedGIFNamed:@"baobao_1"];
    UIImageView *gifImageView = [[UIImageView alloc] initWithImage:gifImage];
    gifImageView.frame = CGRectMake(CGRectGetWidth(self.view.frame) / 2 - width / 2, CGRectGetHeight(self.view.frame) / 2 + height, width, height);
    [self.view addSubview:gifImageView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
