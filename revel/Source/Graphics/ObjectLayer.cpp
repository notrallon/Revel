#include "ObjectLayer.h"
#include <iostream>
#include <Tmx/TmxObject.h>
#include <Tmx/TmxPolygon.h>
#include <Tmx/TmxPolyline.h>

namespace rvl {
	ObjectLayer::ObjectLayer(Tmx::ObjectGroup* objectGroup, const sf::Texture& tileset): m_Player(nullptr) {
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
					rect->setTexture(&tileset);
					rect->setOrigin(0, 16);
					int tu = (object->GetGid() - 1) % (tileset.getSize().x / 16);
					int tv = (object->GetGid() - 1) / (tileset.getSize().x / 16);

					//std::cout << "Object ID: " << object->GetId() << "tu: " << tu << " tv: " << tv << std::endl;

					rect->setTextureRect(sf::IntRect(tu * 16, tv * 16, 16, 16));
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
		m_Player->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		std::sort(m_GameObjects.begin(), m_GameObjects.end(), ObjectSort);

		for (auto object : m_GameObjects) {
			window.draw(*object);
		}
	}
}