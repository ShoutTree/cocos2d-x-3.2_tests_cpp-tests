#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../Classes/testBasic.h"

class TestLayerZorderLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestLayerZorderLayer);

private:
	bool pressedDown;
};


class TestLayerZorderScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif // __HELLOWORLD_SCENE_H__
