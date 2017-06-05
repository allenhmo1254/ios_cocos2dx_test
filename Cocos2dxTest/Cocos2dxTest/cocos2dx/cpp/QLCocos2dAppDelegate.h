//
//  Cocos2dAppDelegate.hpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#ifndef QLCocos2dAppDelegate_hpp
#define QLCocos2dAppDelegate_hpp

#include "cocos2d.h"
#include "QLMainScene.h"

class  QLCocos2dAppDelegate : public cocos2d::Application
{
public:
    QLCocos2dAppDelegate();
    virtual ~QLCocos2dAppDelegate();
    
    virtual void initGLContextAttrs();
    
    /**
     @brief    Implement Director and Scene init code here.
     @return true    Initialize success, app continue.
     @return false   Initialize failed, app terminate.
     */
    virtual bool applicationDidFinishLaunching();
    
    /**
     @brief  The function be called when the application enter background
     @param  the pointer of the application
     */
    virtual void applicationDidEnterBackground();
    
    /**
     @brief  The function be called when the application enter foreground
     @param  the pointer of the application
     */
    virtual void applicationWillEnterForeground();
    
    virtual void end();
    
private:
    QLMainScene* mainScene;
};

#endif /* Cocos2dAppDelegate_hpp */
