#include <fstream>
#include <iostream>

#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;



class $modify(EditLevelLayerHook, EditLevelLayer) {

	void launchWeb(CCObject* sender) {
		geode::createQuickPopup("IMPORTANT! WHICH MOD?", "There are currently two major mods for GD Web Browser that this Geode mod supports.\nAs of the time I'm writing this, web Dash has more features, but is not allowed on the Web Browser Demon List.\n\nAs it stands this mod uses forks of the two main mods that add the functionality I need. This means they are often BEHIND the originals as of now, until I hopefully get the \"load from url\" feature in the official mods, in which case I will update this mod accordingly.",
			"Open WBDL mod", "Open Web Dash mod",
			[this](auto, bool btn2) {
				std::string urlBasePath = "https://rgc-exists.github.io/geometrydashdotcom";
				if (btn2) {
					urlBasePath = "https://rgc-exists.github.io/web-dashers-fork";
				}

				std::string url = urlBasePath + "?songID=" + std::to_string(m_level->m_songID) + "&string=" + m_level->m_levelString;
				CCApplication::get()->openURL(url.c_str());
		});
	}

	bool init(GJGameLevel* level) {
		if (!EditLevelLayer::init(level)) return false;

		auto sprite = CircleButtonSprite::createWithSprite("web_title.png"_spr);
		auto button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(EditLevelLayerHook::launchWeb));

		auto menu = getChildByID("level-actions-menu");
		menu->addChild(button);
		menu->updateLayout();

		return true;
	}
};