//
//  QLMainScene.hpp
//  Cocos2dxTest
//
//  Created by 景中杰 on 16/10/25.
//  Copyright © 2016年 jingzhongjie. All rights reserved.
//

#ifndef QLMainScene_h
#define QLMainScene_h

#include "cocos2d.h"
#include "QLSuperGiftAnimLayer.h"
#include "QLEnterRoomAnimLayer.h"

class QLMainScene : public cocos2d::Scene
{
public:
    void createAllLayers();
    void removeAllLayers();
    
    CREATE_FUNC(QLMainScene);
    
protected:
    virtual bool init();
    
    QLMainScene();
    ~QLMainScene();
    
private:
    QLSuperGiftAnimLayer *superGiftAnimLayer;
    QLEnterRoomAnimLayer *enterRoomAnimLayer;
};

#endif /* QLMainScene_hpp */
