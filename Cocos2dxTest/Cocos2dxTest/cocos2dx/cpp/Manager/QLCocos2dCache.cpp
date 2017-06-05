//
//  QLCocos2dCache.cpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/27.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#include "QLCocos2dCache.h"

static QLCocos2dCache *instance = nullptr;

using namespace cocos2d;
using namespace spine;

QLCocos2dCache* QLCocos2dCache::getInstance()
{
    if (instance == nullptr) {
        instance = new QLCocos2dCache();
    }
    return instance;
}

void QLCocos2dCache::destroyInstance()
{
    if (instance) {
        instance -> release();
        instance = nullptr;
    }
}

SkeletonAnimation* QLCocos2dCache::addSkeletonAnimation(const char * jsonPath, const char * atlasPath)
{
    SkeletonAnimation *anim = (SkeletonAnimation *)superEffectDict -> objectForKey(jsonPath);
    if (!anim) {
        anim = SkeletonAnimation::createWithFile(jsonPath, atlasPath, 1.0f);
        superEffectDict -> setObject(anim, jsonPath);
    }
    return anim;
}

#pragma mark - protected

QLCocos2dCache::QLCocos2dCache()
:superEffectDict(nullptr)
{
    initData();
}

QLCocos2dCache::~QLCocos2dCache()
{
    CC_SAFE_RELEASE_NULL(superEffectDict);
}

void QLCocos2dCache::initData()
{
    superEffectDict = __Dictionary::create();
    CC_SAFE_RETAIN(superEffectDict);
}
