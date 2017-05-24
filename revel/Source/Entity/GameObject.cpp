#include "GameObject.h"

namespace rvl {
	GameObject::GameObject() {
	}
	
	GameObject::GameObject(rvl::SharedContext * context) : m_Context(context) {
		m_Transform = AddComponent<rvl::Transform>();
	}
	
	GameObject::~GameObject() {
		for (auto component : m_Components) {
			delete component.second;
			component.second = nullptr;
		}
		m_Components.clear();
	}
	
	void GameObject::FixedUpdate() {
		for (auto component : m_Components) {
			component.second->FixedUpdate();
		}
	}
	
	void GameObject::Update() {
		for (auto component : m_Components) {
			component.second->Update();
		}
	}
	
	void GameObject::LateUpdate() {
		for (auto component : m_Components) {
			component.second->LateUpdate();
		}
	}
	
	void GameObject::Draw() {
		for (auto component : m_Components) {
			component.second->Draw();
		}
	}
	
	const rvl::Transform& GameObject::GetTransform() const {
		return *m_Transform;
	}

	const sf::Vector2f & GameObject::GetPosition() const {
		return m_Transform->GetPosition();
	}
	
	rvl::SharedContext* GameObject::GetContext() const {
		return m_Context;
	}
}