#include "GameObject.h"

namespace rvl {
	GameObject::GameObject() : m_BoxCollider(nullptr) {
		m_Transform = AddComponent<rvl::Transform>();
	}
	
	GameObject::GameObject(rvl::SharedContext * context) : m_Context(context), m_BoxCollider(nullptr) {
		m_Transform = AddComponent<rvl::Transform>();
	}
	
	GameObject::~GameObject() {
		for (auto component : m_Components) {
			delete component.second;
			component.second = nullptr;
		}
		m_Components.clear();
	}

	void GameObject::Start() {
		for (auto component : m_Components) {
			component.second->Start();
		}
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

	const sf::Vector2f& GameObject::GetPosition() const {
		return m_Transform->GetPosition();
	}

    void GameObject::SetPosition(float x, float y) {
        m_Transform->SetPosition(x, y);
    }
	
	rvl::SharedContext* GameObject::GetContext() const {
		return m_Context;
	}

	const BoxCollider* GameObject::GetCollider() const {
		return m_BoxCollider;
	}

	void GameObject::SetCollider(rvl::BoxCollider* collider) {
		m_BoxCollider = collider;
	}
	
	void GameObject::DoBind(lua_State * L) {
		luabridge::getGlobalNamespace(L)
			.beginNamespace("rvl")
				.beginClass<GameObject>("GameObject")
					.addConstructor<void(*)(void)>()
					.addFunction("AddSprite", &AddComponent<SpriteComponent>)
					.addFunction("GetSprite", &GetComponent<SpriteComponent>)
					.addFunction("GetScript", &GetComponent<LuaComponent>)
					.addFunction("AddBoxCollider", &AddComponent<BoxColliderComponent>)
					.addFunction("GetBoxCollider", &GetComponent<BoxColliderComponent>)
				.endClass()
			.endNamespace();
	}
}