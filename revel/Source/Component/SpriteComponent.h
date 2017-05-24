#pragma once

#include "Component.h"

namespace rvl {
    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// SpriteComponent 
    ///
    ////////////////////////////////////////////////////////////////////////////////
    class SpriteComponent : public Component {
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

        const sf::Vector2f&     GetSize() const;

        void                    SetOrigin(float x, float y);

    private:
        sf::Sprite*             m_Sprite;
    };
}