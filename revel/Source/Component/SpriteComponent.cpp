#include "SpriteComponent.h"
#include "Entity/GameObject.h"

namespace rvl {
    SpriteComponent::SpriteComponent() {
        m_Sprite = new sf::Sprite();
    }

    SpriteComponent::SpriteComponent(GameObject* gameObject) : Component(gameObject) {
        m_Context = m_GameObject->GetContext();
        m_Sprite = new sf::Sprite();
        m_Sprite->setPosition(m_GameObject->GetPosition());
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
    
    const sf::Vector2f& SpriteComponent::GetSize() const {
        // TODO: insert return statement here
        return sf::Vector2f(m_Sprite->getTextureRect().width, m_Sprite->getTextureRect().height);
    }
    
    void SpriteComponent::SetOrigin(float x, float y) {
        m_Sprite->setOrigin(x, y);
    }
}