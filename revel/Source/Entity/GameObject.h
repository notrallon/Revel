#pragma once

#include "Component/Component.h";
#include "Common.h"
#include "SharedContext.h"

#include <vector>;
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace rvl {

    class GameObject
    {
	    ////////////////////////////////////////////////////////////////////////////////
	    ///
	    /// Base class for all types of objects in the Scenes.
	    ///
	    ////////////////////////////////////////////////////////////////////////////////
    public:
	            GameObject();
                GameObject(rvl::SharedContext* context);
	            ~GameObject();

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
        T* GetComponent() const {
            auto component = m_Components.find(typeid(T));
            if (component != m_Components.end()) {
                return static_cast<T*>(component->second);
            }
            std::cout << "Could not find component type.. " << std::endl;
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
            auto findComponent = m_Components.find(typeid(T));
            if (findComponent == m_Components.end()) {
                T* component = new T(this);
                m_Components.emplace(typeid(T), component);
                return component;
            }
            std::cout << "Could not add because of duplicate component type. Returning found component." << std::endl;
            return static_cast<T*>(findComponent->second);
        }

        template <typename T>
        ////////////////////
        /// \brief void AddComponent(T* component)
        ///
        /// AddComponent(T* component) attempts to add a
        /// component that was created outside this gameobject.
        ////////////////////
        void AddComponent(T* component) {
            if (m_Components.find(typeid(T)) == m_Components.end()) {
                m_Components.emplace(typeid(T), component);
            }
        }

        ////////////////////
	    /// \brief Get the object transform
	    ///
	    /// \return The transform of the gameobject.
        ////////////////////
	    void                    GetTransform();

        rvl::SharedContext*     GetContext() const;

    private:
	    typedef std::unordered_map<std::type_index, rvl::Component*> ComponentContainer;

	    ComponentContainer m_Components;
        rvl::SharedContext* m_Context;
    };

}
