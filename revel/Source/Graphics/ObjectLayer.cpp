#include "ObjectLayer.h"
#include <iostream>
#include <Tmx/TmxMap.h>
#include <Tmx/TmxObject.h>
#include <Tmx/TmxPolygon.h>
#include <Tmx/TmxPolyline.h>
#include <Tmx/TmxTileset.h>

namespace rvl {
	ObjectLayer::ObjectLayer(Tmx::ObjectGroup* objectGroup, const std::vector<sf::Texture*>& tilesets): m_Player(nullptr) {
		// Loop through all objects and create shapes depending on what type of object it is
		for (auto object : objectGroup->GetObjects()) {
			if (object->GetEllipse() != 0) {
				sf::CircleShape* circle = new sf::CircleShape(object->GetWidth() / 2);
				circle->setFillColor(sf::Color(0, 255, 0, 50));
				circle->setPosition(object->GetX(), object->GetY());
				m_GameObjects.push_back(circle);
			} else if (object->GetPolygon() != 0) {
				sf::ConvexShape* polygon = new sf::ConvexShape(object->GetPolygon()->GetNumPoints());

				for (uint32 i = 0; i < polygon->getPointCount(); i++) { polygon->setPoint(i, sf::Vector2f(object->GetPolygon()->GetPoint(i).x, object->GetPolygon()->GetPoint(i).y)); }
				polygon->setFillColor(sf::Color(0, 0, 0, 0));
				polygon->setOutlineColor(sf::Color(255, 0, 0, 255));
				polygon->setOutlineThickness(5);
				polygon->setPosition(object->GetX(), object->GetY());

				m_GameObjects.push_back(polygon);
			} else if (object->GetPolyline() != 0) {
				sf::ConvexShape* polygon = new sf::ConvexShape(object->GetPolyline()->GetNumPoints());

				for (uint32 i = 0; i < polygon->getPointCount(); i++) { polygon->setPoint(i, sf::Vector2f(object->GetPolyline()->GetPoint(i).x, object->GetPolyline()->GetPoint(i).y)); }
				polygon->setFillColor(sf::Color(0, 0, 0, 0));
				polygon->setOutlineColor(sf::Color(255, 255, 0, 125));
				polygon->setOutlineThickness(5);
				polygon->setPosition(object->GetX(), object->GetY());

				m_GameObjects.push_back(polygon);
			} else {
				sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(object->GetWidth(), object->GetHeight()));
				rect->setPosition(object->GetX(), object->GetY());

				if (object->GetGid() != 0) {
					int tilesetIndex = objectGroup->mapGetMap()->FindTilesetIndex(object->GetGid());
					int tileSize = 16;
					int firstGid = objectGroup->mapGetMap()->GetTilesets()[tilesetIndex]->GetFirstGid();
					rect->setTexture(tilesets[tilesetIndex]);
					rect->setOrigin(0, rect->getSize().y);
					int tu = (object->GetGid() - firstGid) % (tilesets[tilesetIndex]->getSize().x / tileSize);
					int tv = (object->GetGid() - firstGid) / (tilesets[tilesetIndex]->getSize().x / tileSize);

					rect->setTextureRect(sf::IntRect(tu * tileSize, tv * tileSize, tileSize, tileSize));
				} else {
					rect->setFillColor(sf::Color(0, 0, 255, 125));
				}

				if (object->GetName() == "player-start") {
					m_Player = rect;
					rect->setOrigin(0, 16);
				}

				m_GameObjects.push_back(rect);
			}
		}
	}

	ObjectLayer::~ObjectLayer() {
		for (auto object : m_GameObjects) {
			delete object;
		}
		m_GameObjects.clear();
	}

	bool ObjectSort(const sf::Shape* A, const sf::Shape* B) {
		return A->getPosition().y < B->getPosition().y;
	}

	void ObjectLayer::Draw(sf::RenderWindow& window) {
		if (m_Player != nullptr) {
			m_Player->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		}
		std::sort(m_GameObjects.begin(), m_GameObjects.end(), [](const sf::Shape* A, const sf::Shape* B) { return A->getPosition().y < B->getPosition().y; });

		for (auto object : m_GameObjects) {
			window.draw(*object);
		}
	}
}