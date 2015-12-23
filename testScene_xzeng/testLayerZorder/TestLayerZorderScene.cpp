#include "TestLayerZorderScene.h"

USING_NS_CC;

const int MONKEY_TAG = 333;
const int GIRL_TAG = 222;

void TestLayerZorderScene::runThisTest()
{
    auto layer = TestLayerZorderLayer::create();
    addChild(layer);

    Director::getInstance()->replaceScene(this);
}

// on "init" you need to initialize your instance
bool TestLayerZorderLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "testLayerZorder/CloseNormal.png",
                                           "testLayerZorder/CloseSelected.png",
                                           CC_CALLBACK_1(TestLayerZorderLayer::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("testLayerZorder/HelloWorld.png");
    //auto sprite = Sprite::create("res/ui/noCompressed/angryBar/angryBar.png");

    // position the sprite on the center of the screen
	Vec2 center = Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    sprite->setPosition(center);

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	auto sprite_girl = Sprite::create("testLayerZorder/girl.jpg");
    auto sprite_monkey = Sprite::create("testLayerZorder/monkey.png");
    auto sprite_mouse = Sprite::create("testLayerZorder/mouse.jpg");
    auto sprite_picaqiu = Sprite::create("testLayerZorder/picaqiu.jpg");

	this->addChild(sprite_girl, 1);
	sprite_girl->addChild(sprite_monkey, -1);
	sprite_girl->setPosition(center);
	sprite_girl->setTag(GIRL_TAG);
	sprite_monkey->setPosition(Vec2(100, 0));
	sprite_monkey->setTag(MONKEY_TAG);
	
	this->addChild(sprite_mouse, 1);
	sprite_mouse->addChild(sprite_picaqiu, 0);
	sprite_mouse->setPosition(Vec2(center.x + 100, center.y));
	sprite_picaqiu->setPosition(Vec2(100, 0));
	
	pressedDown = false;
    
	//auto spriteWithMultiTexture = SpriteWithMultiTexture::create(
	//	"res/ui/noCompressed/angryBar/angryBar_Background.png",
	//	"res/ui/noCompressed/angryBar/angryBar.png",
	//	"res/ui/noCompressed/angryBar/fadeOutBar.png");

	//spriteWithMultiTexture->setPosition(Vec2(visibleSize.width/2 + origin.x, 0));
	//spriteWithMultiTexture->setTag(333);
	//this->addChild(spriteWithMultiTexture);
    
    return true;
}

//
//void TestLayerZorderLayer::menuCloseCallback(Ref* pSender)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}

void TestLayerZorderLayer::menuCloseCallback(Ref* pSender)
{
	auto sprite_girl = this->getChildByTag(GIRL_TAG);
	auto sprite_monkey = sprite_girl->getChildByTag(MONKEY_TAG);

	pressedDown = !pressedDown;
	if (pressedDown)
		sprite_monkey->setGlobalZOrder(10000);
	else
		sprite_monkey->setGlobalZOrder(0);
}
