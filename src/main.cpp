#include <fstream>
#include <iostream>

#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

std::string urlBasePath = "https://rgc-exists.github.io/geometrydashdotcom";


class $modify(EditLevelLayerHook, EditLevelLayer) {

	void launchWeb(CCObject* sender) {
		std::string url = urlBasePath + "?songID=" + std::to_string(m_level->m_songID) + "&string=" + m_level->m_levelString;
		CCApplication::get()->openURL(url.c_str());
	}

	bool init(GJGameLevel* level) {
		if (!EditLevelLayer::init(level)) return false;

		auto sprite = CircleButtonSprite::createWithSpriteFrameName("web_title.png"_spr);
		auto button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(EditLevelLayerHook::launchWeb));

		auto menu = getChildByID("level-actions-menu");
		menu->addChild(button);
		menu->updateLayout();

		return true;
	}
};