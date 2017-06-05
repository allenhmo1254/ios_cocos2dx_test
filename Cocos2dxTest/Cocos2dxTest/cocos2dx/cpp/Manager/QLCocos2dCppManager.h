//
//  QLCocos2dCppManager.hpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/18.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#ifndef QLCocos2dCppManager_hpp
#define QLCocos2dCppManager_hpp

#include <stdio.h>
#include "QLSuperGiftAnimLayer.h"
#include "QLEnterRoomAnimLayer.h"

class QLCocos2dCppManager
{
public:
    static QLCocos2dCppManager* getInstance();
    
    void setSuperGiftAnimLayer(QLSuperGiftAnimLayer *layer){superGiftAnimLayer = layer;}
    QLSuperGiftAnimLayer *getSuperGiftAnimLayer(){return superGiftAnimLayer;};
    void setEnterRoomAnimLayer(QLEnterRoomAnimLayer *layer){enterRoomAnimLayer = layer;}
    QLEnterRoomAnimLayer *getEnterRoomAnimLayer(){return enterRoomAnimLayer;};
    
    void playEffect(int type);
    void stopEffect();
    
    void playEnterRoomEffect();
    void showSprite(cocos2d::Texture2D *tex);
    
    void setStartListener (const spine::StartListener& listener);
    void setEndListener (const spine::EndListener& listener);
    void setCompleteListener (const spine::CompleteListener& listener);
    void setEventListener (const spine::EventListener& listener);
    
protected:
    QLCocos2dCppManager();
    ~QLCocos2dCppManager();
    
private:
    QLSuperGiftAnimLayer *superGiftAnimLayer;
    QLEnterRoomAnimLayer *enterRoomAnimLayer;
};

#endif /* QLAnimManager_hpp */
