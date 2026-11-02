#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(QuantumMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto button = CCMenuItemSpriteExtra::create(
            CircleButtonSprite::create(
                CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png"),
                CircleBaseColor::Green
            ),
            this,
            menu_selector(QuantumMenuLayer::onQuantumClick)
        );

        button->setID("quantum-button"_spr);

        this->getChildByID("bottom-menu")->addChild(button);
        this->getChildByID("bottom-menu")->updateLayout();

        return true;
    }

    void onQuantumClick(CCObject*) {
        FLAlertLayer::create(
            "Quantum Mod",
            "Welcome to <cy>Quantum Mod</c>!",
            "Let's go!"
        )->show();
    }
};
