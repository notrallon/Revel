#include "SpriteComponent.h"

namespace rvl {
    SpriteComponent::SpriteComponent() {
    }

    SpriteComponent::SpriteComponent(GameObject* gameObject) : Component(gameObject) {
        m_Sprite = new sf::Sprite();
    }

    SpriteComponent::~SpriteComponent() {
    }

    void SpriteComponent::Awake() {
    }

    void SpriteComponent::Start() {
    }

    void SpriteComponent::FixedUpdate() {
    }

    void SpriteComponent::Update() {
    }

    void SpriteComponent::LateUpdate() {
    }

    void SpriteComponent::Draw() {
    }

    void SpriteComponent::OnDestroy() {
    }

    void SpriteComponent::SetTexture(sf::Texture & texture) {
        m_Sprite->setTexture(texture);
    }
}