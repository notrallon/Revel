#include "SpriteComponent.h"
#include "Entity/GameObject.h"

namespace rvl {
    SpriteComponent::SpriteComponent() {
    }

    SpriteComponent::SpriteComponent(GameObject* gameObject) : Component(gameObject) {
        m_Sprite = new sf::Sprite();
    }

    SpriteComponent::~SpriteComponent() {
		OnDestroy();
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
		m_Sprite->setPosition(m_GameObject->GetPosition());
    }

    void SpriteComponent::Draw() {
		m_Context->window->draw(*m_Sprite);
    }

    void SpriteComponent::OnDestroy() {
		delete m_Sprite;
		m_Sprite = nullptr;
    }

    void SpriteComponent::SetTexture(const sf::Texture& texture) {
        m_Sprite->setTexture(texture);
    }

	void SpriteComponent::SetTextureRect(const sf::IntRect& rect) {
		m_Sprite->setTextureRect(rect);
	}
}