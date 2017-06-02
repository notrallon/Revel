#include "SpriteComponent.h"
#include "Entity/GameObject.h"

namespace rvl {
    SpriteComponent::SpriteComponent() {
    }

    SpriteComponent::SpriteComponent(GameObject* gameObject) : Component(gameObject) {
        m_Context = m_GameObject->GetContext();
		m_Rectangle.setPosition(m_GameObject->GetPosition());
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
		m_Rectangle.setPosition(m_GameObject->GetPosition());
    }

    void SpriteComponent::LateUpdate() {
    }

    void SpriteComponent::Draw() {
		m_Context->window->draw(m_Rectangle);
    }

    void SpriteComponent::OnDestroy() {
    }

    void SpriteComponent::SetTexture(const sf::Texture& texture) {
		m_Rectangle.setTexture(&texture);
    }

	void SpriteComponent::SetTextureRect(const sf::IntRect& rect) {
		m_Rectangle.setTextureRect(rect);
	}

	const sf::Vector2f & SpriteComponent::GetPosition() const {
		return m_Rectangle.getPosition();
	}

    void SpriteComponent::SetPosition(float x, float y) {
        m_Rectangle.setPosition(sf::Vector2f(x, y));
    }
    
	const sf::Vector2f& SpriteComponent::GetSize() const {
		return m_Rectangle.getSize();
	}

	void SpriteComponent::SetSize(float x, float y) {
		m_Rectangle.setSize(sf::Vector2f(x, y));
	}

	const float & SpriteComponent::GetWidth() const {
		return GetSize().x;
	}

	const float & SpriteComponent::GetHeight() const {
		return GetSize().y;
	}

	void SpriteComponent::SetWidth(float x) {
		SetSize(x, GetSize().y);
	}

	void SpriteComponent::SetHeight(float y) {
		SetSize(GetSize().x, y);
	}
    
    void SpriteComponent::SetOrigin(float x, float y) {
		m_Rectangle.setOrigin(x, y);
    }

	void SpriteComponent::DoBind(lua_State * L) {
		using namespace luabridge;
		getGlobalNamespace(L)
			.beginNamespace("rvl")
				.beginClass<SpriteComponent>("Sprite")
					.addProperty("width", &GetWidth, &SetWidth)
					.addProperty("height", &GetHeight, &SetHeight)
				.endClass()
			.endNamespace();
	}
}