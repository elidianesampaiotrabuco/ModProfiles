#include <filesystem>

#include <Geode/Geode.hpp>
#include "ModProfilesPopup.h"

#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;
namespace fs = std::filesystem;

class $modify(ModProfilesMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("mod-profiles-button.png"_spr),
			this,
			menu_selector(ModProfilesMenuLayer::onMyButton)
		);
		myButton->setScale(10.25f);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);
		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		ModProfilesPopup* popup = ModProfilesPopup::create();
		popup->show();
	}
};

