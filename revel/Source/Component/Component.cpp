#include "Component.h"

namespace rvl {
    Component::Component() : m_GameObject(nullptr) {
        m_Context = nullptr;
    }

    Component::Component(GameObject * gameObject) : m_GameObject(gameObject) {
        m_Context = m_GameObject->GetContext();
    }

    Component::~Component() {
    }
}
