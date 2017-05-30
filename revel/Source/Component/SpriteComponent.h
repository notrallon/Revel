#pragma once

#include "Component.h"

namespace rvl {
    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// SpriteComponent 
    ///
    ////////////////////////////////////////////////////////////////////////////////
    class SpriteComponent : public Component {
		friend void Bind<SpriteComponent>(lua_State*);
    public:
                                SpriteComponent();
                                SpriteComponent(GameObject* gameObject);
        virtual                 ~SpriteComponent();

        virtual void            Awake()         override;
        virtual void            Start()         override;
        virtual void            FixedUpdate()   override;
        virtual void            Update()        override;
        virtual void            LateUpdate()    override;
        virtual void            Draw()          override;
        virtual void            OnDestroy()     override;

        void                    SetTexture(const sf::Texture& texture);
		void			        SetTextureRect(const sf::IntRect& rect);

        void                    SetPosition(float x, float y);
        const sf::Vector2f&     GetPosition() const;

        const sf::Vector2f&     GetSize() const;
		void					SetSize(float x, float y);

		const float&			GetWidth() const;
		void					SetWidth(float x);
		
		const float&			GetHeight() const;
		void					SetHeight(float y);

        void                    SetOrigin(float x, float y);

	protected:
		static void				DoBind(lua_State* L);

    private:
		sf::RectangleShape		m_Rectangle;
    };
}