//
//  QLMainScene.cpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/25.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#include "QLMainScene.h"
#include "QLCocos2dCppManager.h"

void QLMainScene::createAllLayers()
{
    if (!enterRoomAnimLayer) {
        enterRoomAnimLayer = QLEnterRoomAnimLayer::create();
        addChild(enterRoomAnimLayer);
        
        QLCocos2dCppManager::getInstance() -> setEnterRoomAnimLayer(enterRoomAnimLayer);
    }
    if (!superGiftAnimLayer) {
        superGiftAnimLayer = QLSuperGiftAnimLayer::create();
        addChild(superGiftAnimLayer);
        
        QLCocos2dCppManager::getInstance() -> setSuperGiftAnimLayer(superGiftAnimLayer);
    }
}

void QLMainScene::removeAllLayers()
{
    removeAllChildren();
    superGiftAnimLayer = nullptr;
    QLCocos2dCppManager::getInstance() -> setSuperGiftAnimLayer(nullptr);
    enterRoomAnimLayer = nullptr;
    QLCocos2dCppManager::getInstance() -> setEnterRoomAnimLayer(nullptr);
}

#pragma mark - protected

bool QLMainScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    
    createAllLayers();
    
    return true;
}

QLMainScene::QLMainScene()
:superGiftAnimLayer(nullptr)
{
    
}

QLMainScene::~QLMainScene()
{
    removeAllLayers();
}
