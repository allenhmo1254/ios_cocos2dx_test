//
//  QLCocos2dCppManager.cpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#include "QLCocos2dCppManager.h"
#include "cocos2d.h"

static QLCocos2dCppManager *instance = nullptr;

QLCocos2dCppManager* QLCocos2dCppManager::getInstance()
{
    if (instance == nullptr) {
        instance = new QLCocos2dCppManager();
    }
    return instance;
}

QLCocos2dCppManager::QLCocos2dCppManager()
{
    
}

QLCocos2dCppManager::~QLCocos2dCppManager()
{
    
}

void QLCocos2dCppManager::playEffect(int type)
{
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> playEffect(type);
    }
}

void QLCocos2dCppManager::stopEffect()
{
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> stopEffect();
    }
}

void QLCocos2dCppManager::showSprite(cocos2d::Texture2D *tex)
{
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> showSprite(tex);
    }
}

void QLCocos2dCppManager::setStartListener (const spine::StartListener& listener) {
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> setStartListener(listener);
    }
}

void QLCocos2dCppManager::setEndListener (const spine::EndListener& listener) {
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> setEndListener(listener);
    }
}

void QLCocos2dCppManager::setCompleteListener (const spine::CompleteListener& listener) {
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> setCompleteListener(listener);
    }
}

void QLCocos2dCppManager::setEventListener (const spine::EventListener& listener) {
    if (superGiftAnimLayer) {
        superGiftAnimLayer -> setEventListener(listener);
    }
}
