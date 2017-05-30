#include "TransformComponent.h"
#include "Entity/GameObject.h"

namespace rvl {
	TransformComponent::TransformComponent() {
	}
	
	TransformComponent::TransformComponent(GameObject* gameObject) : Component(gameObject) {
	}
	
	TransformComponent::~TransformComponent() {
	}
	
	void TransformComponent::Awake() {
	}
	
	void TransformComponent::Start() {
	}
	
	void TransformComponent::FixedUpdate() {
	}
	
	void TransformComponent::Update() {
		const BoxCollider* collider = m_GameObject->GetCollider();
		if (collider == nullptr) return;
		SetPosition(collider->GetPosition().x, collider->GetPosition().y);
	}
	
	void TransformComponent::LateUpdate() {
	}
	
	void TransformComponent::Draw() {
        sf::RectangleShape shape;
        shape.setSize(m_Size);
        shape.setPosition(m_Transform.getPosition());
        //m_Context->window->draw(shape);
	}
	
	void TransformComponent::OnDestroy() {
	}
	
	const sf::Vector2f& TransformComponent::GetPosition() const {
		return m_Transform.getPosition();
	}

    void TransformComponent::SetPosition(float x, float y) {
        m_Transform.setPosition(sf::Vector2f(x, y));
    }
    
    const sf::Vector2f & TransformComponent::GetSize() const {
        return m_Size;
    }
    
    void TransformComponent::SetSize(int x, int y) {
        m_Size = sf::Vector2f(x, y);
    }
}