//
//  QLCocos2dAppDelegate.cpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#include "QLCocos2dAppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(720, 1280);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 800);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1080, 1920);

QLCocos2dAppDelegate::QLCocos2dAppDelegate()
{
}

QLCocos2dAppDelegate::~QLCocos2dAppDelegate()
{
    //SimpleAudioEngine::end();
//    cocostudio::ArmatureDataManager::destroyInstance();
}

void QLCocos2dAppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool QLCocos2dAppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("GiftView");
        director->setOpenGLView(glview);
    }
    
    director->setClearColor(Color4F(0, 0, 0, 0));
    
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0f / 30);
    
    register_all_packages();
    
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_WIDTH);
    
    auto frameSize = glview->getFrameSize();
    
    if (!mainScene) {
        mainScene = QLMainScene::create();
        director -> runWithScene(mainScene);
    }
    
    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void QLCocos2dAppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

// this function will be called when the app is active again
void QLCocos2dAppDelegate::applicationWillEnterForeground()
{
    if (mainScene) {
        mainScene -> createAllLayers();
    }
    Director::getInstance()->startAnimation();
}

void QLCocos2dAppDelegate::end()
{
    mainScene -> removeAllLayers();
}
