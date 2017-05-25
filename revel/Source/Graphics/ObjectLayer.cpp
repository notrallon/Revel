#include "ObjectLayer.h"
#include "Entity/GameObject.h"
#include <iostream>
#include <Tmx/TmxMap.h>
#include <Tmx/TmxObject.h>
#include <Tmx/TmxPolygon.h>
#include <Tmx/TmxPolyline.h>
#include <Tmx/TmxTileset.h>

namespace rvl {
	ObjectLayer::ObjectLayer(Tmx::ObjectGroup* objectGroup, const std::vector<sf::Texture*>& tilesets, rvl::SharedContext* context): m_Player(nullptr), m_Context(context) {
		// Loop through all objects and create shapes depending on what type of object it is
		
		//lua_State* L = luaL_newstate();
		//luaL_openlibs(L);
		rvl::BindAll(context);
		//rvl::Bind<GameObject>(L);
		//Bind<SpriteComponent>(L);
/*
		if (luaL_dofile(L, "components.lua")) {
			std::cerr << lua_tostring(L, -1) << std::endl;
		}*/

		for (auto object : objectGroup->GetObjects()) {
            rvl::GameObject* gameObject = new rvl::GameObject(m_Context);
            //gameObject->GetTransform().SetSize(object->GetWidth(), object->GetHeight());
            gameObject->GetComponent<TransformComponent>()->SetSize(object->GetWidth(), object->GetHeight());
            gameObject->SetPosition(object->GetX(), object->GetY());
            m_GameObjects.push_back(gameObject);
			if (object->GetEllipse() != 0) {
				/*sf::CircleShape* circle = new sf::CircleShape(object->GetWidth() / 2);
				circle->setFillColor(sf::Color(0, 255, 0, 50));
				circle->setPosition(object->GetX(), object->GetY());
				m_GameObjects.push_back(circle);*/
			} else if (object->GetPolygon() != 0) {
				/*sf::ConvexShape* polygon = new sf::ConvexShape(object->GetPolygon()->GetNumPoints());

				for (uint32 i = 0; i < polygon->getPointCount(); i++) { polygon->setPoint(i, sf::Vector2f(object->GetPolygon()->GetPoint(i).x, object->GetPolygon()->GetPoint(i).y)); }
				polygon->setFillColor(sf::Color(0, 0, 0, 0));
				polygon->setOutlineColor(sf::Color(255, 0, 0, 255));
				polygon->setOutlineThickness(5);
				polygon->setPosition(object->GetX(), object->GetY());

				m_GameObjects.push_back(polygon);*/
			} else if (object->GetPolyline() != 0) {
				/*sf::ConvexShape* polygon = new sf::ConvexShape(object->GetPolyline()->GetNumPoints());

				for (uint32 i = 0; i < polygon->getPointCount(); i++) { polygon->setPoint(i, sf::Vector2f(object->GetPolyline()->GetPoint(i).x, object->GetPolyline()->GetPoint(i).y)); }
				polygon->setFillColor(sf::Color(0, 0, 0, 0));
				polygon->setOutlineColor(sf::Color(255, 255, 0, 125));
				polygon->setOutlineThickness(5);
				polygon->setPosition(object->GetX(), object->GetY());

				m_GameObjects.push_back(polygon);*/
			} else {
				/*sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(object->GetWidth(), object->GetHeight()));
				rect->setPosition(object->GetX(), object->GetY());*/

				if (object->GetGid() != 0) {
                    rvl::SpriteComponent* sprite = gameObject->AddComponent<rvl::SpriteComponent>();
					sprite->SetSize(object->GetWidth(), object->GetHeight());
					// For some reason: objectGroup->mapGetMap()->FindTileset(object->GetGid()) doesn't
					// work, so we have to first get the tileset index in order to get the tileset
					int tilesetIndex = objectGroup->mapGetMap()->FindTilesetIndex(object->GetGid());
					Tmx::Tileset* tmxTileset = objectGroup->mapGetMap()->GetTilesets()[tilesetIndex];
					int margin		= tmxTileset->GetMargin();
					int spacing		= tmxTileset->GetSpacing();
					int tileWidth	= tmxTileset->GetTileWidth();
					int tileHeight	= tmxTileset->GetTileHeight();
					int firstGid	= tmxTileset->GetFirstGid();
					sprite->SetTexture(*tilesets[tilesetIndex]);
					int tu = (object->GetGid() - firstGid) % (tilesets[tilesetIndex]->getSize().x / tileWidth);
					int tv = (object->GetGid() - firstGid) / (tilesets[tilesetIndex]->getSize().x / tileWidth);

					//rect->setTextureRect(sf::IntRect(tu * tileSize, tv * tileSize, tileSize, tileSize));
                    sprite->SetTextureRect(sf::IntRect(margin + tu * (tileWidth + spacing), margin + tv * (tileHeight + spacing), tileWidth, tileHeight));
					sprite->SetOrigin(0.0f, sprite->GetSize().y);
				} else {
					//rect->setFillColor(sf::Color(0, 0, 255, 125));
				}

				auto propList = object->GetProperties().GetList();

				if (propList.find("script") != propList.end()) {
					gameObject->AddComponent<LuaComponent>();
				}

				// We grab the player just so we can use it for debugging atm
				/*if (object->GetName() == "player-start") {
					m_Player = rect;
					rect->setOrigin(0, rect->getSize().y);
				}*/

				//m_GameObjects.push_back(rect);
			}
		}
	}

	ObjectLayer::~ObjectLayer() {
		for (auto object : m_GameObjects) {
			delete object;
		}
		m_GameObjects.clear();
	}

	bool SortObjects(const sf::Shape* A, const sf::Shape* B) {
		return A->getPosition().y < B->getPosition().y;
	}

	void ObjectLayer::Draw(sf::RenderWindow& window) {
		if (m_Player != nullptr) {
			m_Player->setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(), window.getView()));
		}

		std::sort(m_GameObjects.begin(), 
				  m_GameObjects.end(), 
				  [](const rvl::GameObject* A, const GameObject* B) { 
						return A->GetPosition().y < B->GetPosition().y; 
				  });

		for (auto object : m_GameObjects) {
			object->Draw();
		}
	}
}