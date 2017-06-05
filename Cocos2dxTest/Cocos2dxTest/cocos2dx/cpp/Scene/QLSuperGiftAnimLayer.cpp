//
//  QLSuperGiftAnimLayer.cpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#include "QLSuperGiftAnimLayer.h"

USING_NS_CC;

using namespace spine;

bool QLSuperGiftAnimLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    initData();
    initView();
    
    return true;
}

void QLSuperGiftAnimLayer::playEffect(int type)
{
    if (!skeletonNode) {
        skeletonNode = SkeletonAnimation::createWithFile("spine/spineboy.json", "spine/spineboy.atlas", 1.0f);
        skeletonNode->setAnimation(0, "walk", true);
        skeletonNode->setScale(1.0);
        
        skeletonNode->setPosition(Vec2(viewSize.width / 2, viewSize.height * 0.5));
        addChild(skeletonNode);
        
//        skeletonNode -> setStartListener([this](int trackIndex) {
//            if (_startListener) _startListener(trackIndex);
//        });
//        //播放结束的时候被调用
//        skeletonNode->setEndListener([this](int trackIndex){
//            if (_endListener) _endListener(trackIndex);
//        });
//        
//        //每次播放结束的时候被调用
//        skeletonNode->setCompleteListener([this](int trackIndex, int loopCount){
//            if (_completeListener) _completeListener(trackIndex, loopCount);
//        });
//        
//        skeletonNode->setEventListener([this](int trackIndex, spEvent* event) {
//            if (_eventListener) _eventListener(trackIndex, event);
//        });
        
        this -> scheduleUpdate();
        
//        EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
//        listener->onTouchBegan = [this](Touch* touch, Event* event) -> bool {
//            if (!skeletonNode->getDebugBonesEnabled())
//                skeletonNode->setDebugBonesEnabled(true);
//            else if (skeletonNode->getTimeScale() == 1)
//                skeletonNode->setTimeScale(0.3f);
//            else
//            {
//                skeletonNode->setTimeScale(1);
//                skeletonNode->setDebugBonesEnabled(false);
//            }
//            
//            return true;
//        };
//        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }
}

void QLSuperGiftAnimLayer::stopEffect()
{
    if (skeletonNode) {
        skeletonNode -> stopAllActions();
        skeletonNode -> clearTracks();
    }
}

void QLSuperGiftAnimLayer::showSprite(cocos2d::Texture2D *tex)
{
    sprite = Sprite::createWithTexture(tex);
    sprite -> setPosition(Vec2(100, 100));
    addChild(sprite);
}

void QLSuperGiftAnimLayer::setStartListener (const spine::StartListener& listener) {
    skeletonNode -> setStartListener(listener);
}

void QLSuperGiftAnimLayer::setEndListener (const spine::EndListener& listener) {
    skeletonNode -> setEndListener(listener);
}

void QLSuperGiftAnimLayer::setCompleteListener (const spine::CompleteListener& listener) {
    skeletonNode -> setCompleteListener(listener);
}

void QLSuperGiftAnimLayer::setEventListener (const spine::EventListener& listener) {
    skeletonNode -> setEventListener(listener);
}

#pragma mark - private

void QLSuperGiftAnimLayer::initData()
{
    viewSize = Director::getInstance() -> getWinSize();
    __NotificationCenter::getInstance() -> addObserver(this, callfuncO_selector(QLSuperGiftAnimLayer::playEffectNotificationHandle), "PlayEffect", nullptr);
}

void QLSuperGiftAnimLayer::playEffectNotificationHandle(Ref* ref)
{
    __Integer *value = (__Integer *)ref;
    if (value) {
        playEffect(value -> getValue());
    }
}

void QLSuperGiftAnimLayer::initView()
{
    
}
