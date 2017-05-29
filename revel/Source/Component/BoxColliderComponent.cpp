#include "Components.h"
#include "Entity/GameObject.h"

namespace rvl {
	BoxColliderComponent::BoxColliderComponent() {
	}
	
	BoxColliderComponent::BoxColliderComponent(GameObject * gameObject) : Component(gameObject) {
		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.position.Set(m_GameObject->GetTransform().GetPosition().x,
							 m_GameObject->GetTransform().GetPosition().y);

		m_Body = m_Context->physicsWorld->CreateBody(&bodyDef);

		b2PolygonShape groundBox;

		groundBox.SetAsBox((m_GameObject->GetTransform().GetSize().x / 2.0f),
							m_GameObject->GetTransform().GetSize().y / 2.0f);

		b2FixtureDef fixturedef;
		fixturedef.shape = &groundBox;
		fixturedef.density = 0.5f;
		fixturedef.friction = 0.7f;
		m_Body->CreateFixture(&fixturedef);
		m_Body->SetFixedRotation(true);

		m_Speed = b2Vec2(0.0f, 0.0f);
	}
	
	BoxColliderComponent::~BoxColliderComponent() {
	}
	
	void BoxColliderComponent::Awake() {
	}
	
	void BoxColliderComponent::Start() {
	}
	
	void BoxColliderComponent::FixedUpdate() {
	}
	
	void BoxColliderComponent::Update() {
		m_Body->SetLinearVelocity(m_Speed);
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		//	m_Body->SetLinearVelocity(b2Vec2(-20.0f, 0));
		//} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		//	//m_Body->ApplyForceToCenter(b2Vec2(100, 0), true);
		//	m_Body->SetLinearVelocity(b2Vec2(20.0f, 0));
		//} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		//	//m_Body->ApplyForceToCenter(b2Vec2(0, -100), true);
		//	m_Body->SetLinearVelocity(b2Vec2(0, -20.0f));
		//} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		//	//m_Body->ApplyForceToCenter(b2Vec2(0, 100), true);
		//	m_Body->SetLinearVelocity(b2Vec2(0, 20.0f));
		//}
		m_Speed.x = 0.0f;
		m_Speed.y = 0.0f;
	}
	
	void BoxColliderComponent::LateUpdate() {
	}
	
	void BoxColliderComponent::Draw() {
		sf::RectangleShape shape;

		sf::Vector2f size = m_GameObject->GetTransform().GetSize();
		b2Vec2 pos = m_Body->GetPosition();

		shape.setSize(size);
		shape.setFillColor(sf::Color::Black);
		shape.setPosition(pos.x, pos.y);
		m_Context->window->draw(shape);
	}
	
	void BoxColliderComponent::OnDestroy() {
	}
	
	const sf::Vector2f & BoxColliderComponent::GetPosition() const {
		sf::Vector2f pos(m_Body->GetPosition().x, m_Body->GetPosition().y);
		return pos;
	}
	
	const float & BoxColliderComponent::GetXPosition() const {
		return GetPosition().x;
	}
	
	const float & BoxColliderComponent::GetYPosition() const {
		return GetPosition().y;
	}
	
	const bool& BoxColliderComponent::GetStatic() const {
		return m_Body->GetType() == b2_staticBody;
	}
	
	void BoxColliderComponent::SetStatic(bool isStatic) {
		b2BodyType type = isStatic ? b2_staticBody : b2_dynamicBody;
		m_Body->SetType(type);
	}

	void BoxColliderComponent::Move(const float & x, const float & y) {
		m_Speed.x = x;
		m_Speed.y = y;
	}
	
	void BoxColliderComponent::DoBind(lua_State * L) {
		using namespace luabridge;
		getGlobalNamespace(L)
				.beginNamespace("rvl")
					.beginClass<BoxColliderComponent>("BoxCollider")
						.addProperty("isStatic", &GetStatic, &SetStatic)
						.addFunction("Move", &Move)
					.endClass()
			.endNamespace();
	}
}