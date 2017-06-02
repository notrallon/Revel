#pragma once

#include "Component.h"

//Skriven av Alexander
namespace rvl {
    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// SpriteComponent renders and sets the properties to any object in need of a sprite.
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

		////////////////////
		/// \brief void Update()
		///
		/// Update runs every frame and sets the Sprite to the same position as the GameObject's Position.
		////////////////////
        virtual void            Update()        override;

        virtual void            LateUpdate()    override;

		////////////////////
		/// \brief void Draw()
		///
		/// Draws a sprite based on a set texture to the Sprite.
		////////////////////
        virtual void            Draw()          override;

        virtual void            OnDestroy()     override;

		////////////////////
		/// \brief void SetTexture()
		///
		/// Takes in a Texture reference and sets it to the Sprite.
		////////////////////
        void                    SetTexture(const sf::Texture& texture);

		////////////////////
		/// \brief void SetTextureRect()
		///
		/// Takes an IntRect, a RectangleShape with it's size in whole numbers.
		/// Then sets the size of the SpriteComponents RectangleShape to the new set size.
		////////////////////
		void			        SetTextureRect(const sf::IntRect& rect);

		////////////////////
		/// \brief void GetPosition()
		///
		/// \return The RectangleShape's position in the form of a 2D Vector.
		////////////////////
        const sf::Vector2f&     GetPosition() const;

		////////////////////
		/// \brief void SetPosition()
		///
		/// Takes in two floats, one for the X-Position and one for the Y-Position.
		/// Then creates a new 2D-Vector and sets it to be the new position of the Sprite.
		////////////////////
        void                    SetPosition(float x, float y);

		////////////////////
		/// \brief void GetSize()
		///
		/// \return The set size of the Sprite
		////////////////////
        const sf::Vector2f&     GetSize() const;

		////////////////////
		/// \brief void SetSize()
		///
		/// Takes in two floats, one for the X-Size and one for the Y-Size.
		/// Then creates a new 2D-Vector and sets it to be the new Size of the Sprite.
		////////////////////
		void					SetSize(float x, float y);

		////////////////////
		/// \brief void GetWidth()
		///
		/// Mainly used for LUABind, since LUA doesn't have a definiton for a vector.
		///
		/// \return The Width of the Sprite
		////////////////////
		const float&			GetWidth() const;

		////////////////////
		/// \brief void SetWidth()
		///
		/// Mainly used for LUABind, since LUA doesn't have a definiton for a vector.
		/// SetWidth() sets the Width of the Sprite.
		////////////////////
		void					SetWidth(float x);
		
		////////////////////
		/// \brief void GetHeight()
		///
		/// Mainly used for LUABind, since LUA doesn't have a definiton for a vector.
		///
		/// \return The Height of the Sprite
		////////////////////
		const float&			GetHeight() const;

		////////////////////
		/// \brief void SetHeight()
		///
		/// Mainly used for LUABind, since LUA doesn't have a definiton for a vector.
		/// SetHeight sets the Height of the Sprite.
		////////////////////
		void					SetHeight(float y);

		////////////////////
		/// \brief void SetOrigin()
		///
		/// Sets the origin of the Sprite
		////////////////////
        void                    SetOrigin(float x, float y);

	protected:
		static void				DoBind(lua_State* L);

    private:
		sf::RectangleShape		m_Rectangle;
    };
}