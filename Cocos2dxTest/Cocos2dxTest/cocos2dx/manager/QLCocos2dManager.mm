//
//  QLGiftViewCache.m
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/20.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#import "QLCocos2dManager.h"
#import "QLCocos2dView.h"
#import "QLCocos2dCppManager.h"
#import "cocos2d.h"

static QLCocos2dManager *instance = nil;

@interface QLCocos2dManager ()
{
    QLCocos2dCppManager *cocos2dCppManager;
}

@property(nonatomic, strong)QLCocos2dView *glView;
@property(nonatomic, strong)NSMutableArray *viewCache;
@property(nonatomic, assign)BOOL isGLViewAniming;

@end

@implementation QLCocos2dManager

+(instancetype)shareInstance
{
    @synchronized (self) {
        if (!instance) {
            instance = [[self alloc] init];
        }
        return instance;
    }
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self _initData];
    }
    return self;
}

-(QLCocos2dView *)createGLView
{
    if (!_glView) {
        _glView = [[QLCocos2dView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        [_viewCache addObject:_glView];
    }
    return _glView;
}

-(void)removeGLView
{
    if (_glView) {
        [_glView end];
        [_glView removeFromSuperview];
        _isGLViewAniming = NO;
    }
}

-(void)applicationDidEnterBackground
{
    if (!_isGLViewAniming) {
        return;
    }
    
    if (!_glView) {
        return;
    }
    
    [_glView stopAnimation];
    _glView.hidden = YES;
}

-(void)applicationWillEnterForeground
{
    if (!_isGLViewAniming) {
        return;
    }
    
    if (!_glView) {
        return;
    }
    
    [_glView startAnimation];
    _glView.hidden = NO;
}

-(cocos2d::Texture2D *)uImage2cTexture:(UIImage *)uiImage
{
    CGImageRef imageRef = [uiImage CGImage];
    NSUInteger width = CGImageGetWidth(imageRef);
    NSUInteger height = CGImageGetHeight(imageRef);
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    unsigned char* rawData = (unsigned char*) calloc(height * width * 4, sizeof(unsigned char));
    NSUInteger bytesPerPixel = 4;
    NSUInteger bytesPerRow = bytesPerPixel * width;
    NSUInteger bitsPerComponent = 8;
    CGContextRef context = CGBitmapContextCreate(rawData, width, height, bitsPerComponent, bytesPerRow, colorSpace, kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
    CGColorSpaceRelease(colorSpace);
    CGContextDrawImage(context, CGRectMake(0, 0, width, height), imageRef);
    CGContextRelease(context);
    cocos2d::Texture2D *texture = new cocos2d::Texture2D();
    texture->initWithData(rawData, sizeof(rawData),cocos2d::Texture2D::PixelFormat::RGBA8888, (int)width, (int)height, cocos2d::Size(width, height));
    return texture;
}

-(void)playEffect
{
    if (!_glView) {
        return;
    }
    
    if (_isGLViewAniming) {
        return;
    }
    
    _isGLViewAniming = YES;
    
    [self applicationWillEnterForeground];
    
    cocos2dCppManager -> playEffect(_animType);
    
    cocos2dCppManager -> setStartListener([self](int trackIndex) {
        NSLog(@"Start Animation");
    });
    
    cocos2dCppManager -> setEndListener([self](int trackIndex) {
        NSLog(@"End Animation");
    });
    
    cocos2dCppManager -> setCompleteListener([self](int trackIndex, int loopCount) {
        NSLog(@"Complete Animation");
    });
    
    cocos2dCppManager->setEventListener([self](int trackIndex, spEvent* event) {
        NSLog(@"Event Animation");
    });
}

-(void)stopEffect
{
    if (!_isGLViewAniming) {
        return;
    }
    _isGLViewAniming = NO;
    [self applicationDidEnterBackground];
}

-(void)setIsDrawScene:(int)isDrawScene
{
    _isDrawScene = isDrawScene;
    
    cocos2d::Director::getInstance() -> setIsDrawScene(isDrawScene);
}

#pragma mark - private

-(void)_initData
{
    _viewCache = [[NSMutableArray alloc] init];
    cocos2dCppManager = QLCocos2dCppManager::getInstance();
    _isGLViewAniming = NO;
}

@end
