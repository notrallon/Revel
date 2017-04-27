#include "ObjectLayer.h"
#include <iostream>
#include <Tmx/TmxObject.h>
#include <Tmx/TmxPolygon.h>
#include <Tmx/TmxPolyline.h>

namespace rvl {
	ObjectLayer::ObjectLayer(Tmx::ObjectGroup* objectGroup, const sf::Texture& tileset) {
		for (auto object : objectGroup->GetObjects()) {
			if (object->GetEllipse() != 0) {
				sf::CircleShape* circle = new sf::CircleShape(object->GetWidth() / 2);
				circle->setFillColor(sf::Color(0, 255, 0, 50));
				circle->setPosition(object->GetX(), object->GetY());
				m_GameObjects.push_back(circle);
			} else if (object->GetPolygon() != 0) {
				sf::ConvexShape* polygon = new sf::ConvexShape(object->GetPolygon()->GetNumPoints());

				for (uint32 i = 0; i < polygon->getPointCount(); i++) {
					polygon->setPoint(i, sf::Vector2f(object->GetPolygon()->GetPoint(i).x, object->GetPolygon()->GetPoint(i).y));
				}
				polygon->setFillColor(sf::Color(0, 0, 0, 0));
				polygon->setOutlineColor(sf::Color(255, 0, 0, 255));
				polygon->setOutlineThickness(5);
				polygon->setPosition(object->GetX(), object->GetY());

				m_GameObjects.push_back(polygon);
			} else if (object->GetPolyline() != 0) {
				sf::ConvexShape* polygon = new sf::ConvexShape(object->GetPolyline()->GetNumPoints());

				for (uint32 i = 0; i < polygon->getPointCount(); i++) {
					polygon->setPoint(i, sf::Vector2f(object->GetPolyline()->GetPoint(i).x, object->GetPolyline()->GetPoint(i).y));
				}
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
				} else {
					rect->setFillColor(sf::Color(0, 0, 255, 255));
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

	void ObjectLayer::Draw(sf::RenderWindow& window) {
		for (auto object : m_GameObjects) {
			window.draw(*object);
		}
	}

}