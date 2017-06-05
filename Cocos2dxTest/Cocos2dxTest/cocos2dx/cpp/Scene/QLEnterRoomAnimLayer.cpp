//
//  QLEnterRoomAnimLayer.cpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#include "QLEnterRoomAnimLayer.h"

USING_NS_CC;

using namespace spine;

bool QLEnterRoomAnimLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    initData();
    initView();
    
    return true;
}

void QLEnterRoomAnimLayer::playEffect(int type)
{
    if (!skeletonNode) {
        skeletonNode = SkeletonAnimation::createWithFile("spine/bar/bar_Rleve4.json", "spine/bar/bar_Rleve4.atlas", 1.0f);
        skeletonNode->setAnimation(0, "Rleve4", true);
        skeletonNode->setScale(1.0);
        
        skeletonNode->setPosition(Vec2(0, viewSize.height * 0.75));
        addChild(skeletonNode);
        
        this -> scheduleUpdate();
    }
}

void QLEnterRoomAnimLayer::stopEffect()
{
    if (skeletonNode) {
        skeletonNode -> stopAllActions();
        skeletonNode -> clearTracks();
    }
}

void QLEnterRoomAnimLayer::setStartListener (const spine::StartListener& listener) {
    skeletonNode -> setStartListener(listener);
}

void QLEnterRoomAnimLayer::setEndListener (const spine::EndListener& listener) {
    skeletonNode -> setEndListener(listener);
}

void QLEnterRoomAnimLayer::setCompleteListener (const spine::CompleteListener& listener) {
    skeletonNode -> setCompleteListener(listener);
}

void QLEnterRoomAnimLayer::setEventListener (const spine::EventListener& listener) {
    skeletonNode -> setEventListener(listener);
}

#pragma mark - private

void QLEnterRoomAnimLayer::initData()
{
    viewSize = Director::getInstance() -> getWinSize();
}

void QLEnterRoomAnimLayer::initView()
{
    
}
