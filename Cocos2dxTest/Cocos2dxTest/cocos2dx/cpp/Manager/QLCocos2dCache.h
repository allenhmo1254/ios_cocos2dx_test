//
//  QLCocos2dCache.hpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/27.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#ifndef QLCocos2dCache_h
#define QLCocos2dCache_h

#include "cocos2d.h"
#include "editor-support/spine/spine.h"
#include "editor-support/spine/SkeletonAnimation.h"

class QLCocos2dCache : public cocos2d::Ref {
public:
    static QLCocos2dCache* getInstance();
    static void destroyInstance();
    spine::SkeletonAnimation* addSkeletonAnimation(const char * jsonPath, const char * atlasPath);
protected:
    QLCocos2dCache();
    ~QLCocos2dCache();
    void initData();
private:
    cocos2d::__Dictionary *superEffectDict;
};

#endif /* QLCocos2dCache_hpp */
