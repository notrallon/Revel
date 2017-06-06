#pragma once

#include "LuaBind.h"
#include "Components.h"
#include "Common.h"
#include "SharedContext.h"

#include <vector>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <iostream>

// Created by Richard Norqvist

namespace rvl {
    class GameObject
    {
		friend void Bind<GameObject>(lua_State*);
		////////////////////////////////////////////////////////////////////////////////
	    ///
	    /// Base class for all types of objects in the Scenes.
	    ///
	    ////////////////////////////////////////////////////////////////////////////////
    public:
	            GameObject();
                GameObject(rvl::SharedContext* context);
	            ~GameObject();

		void	Start();

        ////////////////////
        /// \brief void FixedUpdate()
        ///
        /// FixedUpdate runs every n seconds, depending on engine settings.
        ////////////////////
        void    FixedUpdate();

        ////////////////////
        /// \brief void Update()
        ///
        /// Update runs every frame.
        ////////////////////
        void    Update();

        ////////////////////
        /// \brief void LateUpdate()
        ///
        /// LateUpdate runs every frame, after the regular Update function.
        ////////////////////
        void    LateUpdate();


        ////////////////////
        /// \brief void Draw
        ///
        /// Draw runs every frame and draws everything on the screen.
        ////////////////////
        void    Draw();

        template <typename T>
        ////////////////////
        /// \brief T* GetComponent()
        ///
        /// GetComponent() tries to find a component attached to
        /// this GameObject. If the Component is found it returns
        /// a pointer to it. Otherwise it returns nullptr.
        ///
        /// \returns Found component/nullptr.
        ////////////////////
        T* GetComponent() {
            auto component = m_Components.find(typeid(T));
            if (component != m_Components.end()) {
                return static_cast<T*>(component->second);
            }
            std::cerr << "Could not find component type.. " << std::endl;
            return nullptr;
        }

        template <typename T>
        ////////////////////
        /// \brief T* AddComponent()
        ///
        /// AddComponent attempts to add a component to
        /// this gameobject, by first looking through the map
        /// to see if that type of component already exists. 
        /// If the component type does not exist, it adds it
        /// to this gameobject and returns it. If the component
        /// type already exists it takes that component and returns it.
        ///
        /// \return Added/found component.
        ////////////////////
        T* AddComponent() {
            auto foundComponent = m_Components.find(typeid(T));
            if (foundComponent == m_Components.end()) {
                T* component = new T(this);
                m_Components.emplace(typeid(T), component);
                return component;
            }
            std::cerr << "Could not add because of duplicate component type. Returning found component." << std::endl;
            return static_cast<T*>(foundComponent->second);
        }

        template <typename T>
        ////////////////////
        /// \brief void AddComponent(T* component)
        ///
        /// AddComponent(T* component) attempts to add a
        /// component that was created outside this gameobject.
        ////////////////////
        void AddExistingComponent(T* component) {
            if (m_Components.find(typeid(T)) == m_Components.end()) {
                m_Components.emplace(typeid(T), component);
            }
        }

        ////////////////////
	    /// \brief Get the object transform
	    ///
	    /// \return The transform of the gameobject.
        ////////////////////
	    const rvl::Transform&   GetTransform() const;

		////////////////////
		/// \brief sf::Vector2f& GetPosition() const
		///
		/// \return The position of this gameobject.
		////////////////////
		const sf::Vector2f&		GetPosition() const;

		////////////////////
		/// \brief void SetPosition(float x, float y)
		///
		/// \return Set the position of this gameobject.
		////////////////////
        void                    SetPosition(float x, float y);

		////////////////////
		/// \brief SharedContext* GetContext() const
		///
		/// \return The context this gameobject is bound to.
		////////////////////
        rvl::SharedContext*     GetContext() const;

		const BoxCollider*		GetCollider() const;
		void					SetCollider(rvl::BoxCollider*);

	protected:
		static void DoBind(lua_State* L);

    private:
	    typedef std::unordered_map<std::type_index, rvl::Component*> ComponentContainer;

	    ComponentContainer		m_Components;
        rvl::SharedContext*		m_Context;
		rvl::Transform*			m_Transform;
		rvl::BoxCollider*		m_BoxCollider;
    };

}
