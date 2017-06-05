//
//  QLEnterRoomAnimLayer.h
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#ifndef QLEnterRoomAnimLayer_h
#define QLEnterRoomAnimLayer_h

#include "cocos2d.h"
#include "editor-support/spine/spine.h"
#include "editor-support/spine/SkeletonAnimation.h"

class QLEnterRoomAnimLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    
    CREATE_FUNC(QLEnterRoomAnimLayer);
    
    void playEffect(int type);
    void stopEffect();
    
    
    void setStartListener (const spine::StartListener& listener);
    void setEndListener (const spine::EndListener& listener);
    void setCompleteListener (const spine::CompleteListener& listener);
    void setEventListener (const spine::EventListener& listener);
    
protected:
    void initData();
    void initView();
private:
    spine::SkeletonAnimation* skeletonNode;
    cocos2d::LabelTTF *contentLabel;
    bool drawType;
    cocos2d::Size viewSize;
};

#endif /* QLAnimLayer_hpp */
