//
//  QLKeyAnimViewController.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/11/3.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "QLKeyAnimViewController.h"

@interface QLKeyAnimViewController ()

@property(nonatomic, strong)UIImageView *imageView;

@end

@implementation QLKeyAnimViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"mfcb_0"]];
    _imageView.frame = self.view.bounds;
    [self.view addSubview:_imageView];
    
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (int i = 1; i < 129; i ++) {
        NSString *path = [NSString stringWithFormat:@"mfcb_%d",i];
        [array addObject:[UIImage imageNamed:path]];
    }
    _imageView.animationImages = array;
    _imageView.animationDuration = 15;
    [_imageView startAnimating];
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
