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
	}
	
	void TransformComponent::LateUpdate() {
	}
	
	void TransformComponent::Draw() {
	}
	
	void TransformComponent::OnDestroy() {
	}
	
	const sf::Vector2f& TransformComponent::GetPosition() const {
		return m_Transform.getPosition();
	}
}