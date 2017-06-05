//
//  QLSuperGiftAnimLayer.h
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#ifndef QLSuperGiftAnimLayer_h
#define QLSuperGiftAnimLayer_h

#include "cocos2d.h"
#include "editor-support/spine/spine.h"
#include "editor-support/spine/SkeletonAnimation.h"

class QLSuperGiftAnimLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    
    CREATE_FUNC(QLSuperGiftAnimLayer);
    
    void playEffect(int type);
    void stopEffect();
    
    void showSprite(cocos2d::Texture2D *tex);
    
    void setStartListener (const spine::StartListener& listener);
    void setEndListener (const spine::EndListener& listener);
    void setCompleteListener (const spine::CompleteListener& listener);
    void setEventListener (const spine::EventListener& listener);
    
protected:
    void initData();
    void initView();
    
    void playEffectNotificationHandle(cocos2d::Ref* ref);
    
private:
    spine::SkeletonAnimation* skeletonNode;
    bool drawType;
    cocos2d::Size viewSize;
    cocos2d::Sprite *sprite;
};

#endif /* QLAnimLayer_hpp */
