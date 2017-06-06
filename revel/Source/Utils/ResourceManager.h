#pragma once

#include "Common.h"

// Created by Richard Norqvist

namespace rvl {
    template <typename Derived, typename T>
    ////////////////////////////////////////////////////////////////////////////////
    /// 
    /// ResourceManager takes care of automated resource handling. It tracks the amount
    /// of objects/components that is requiring a specific resource, and removes the resource
    /// from memory when no object in the game needs it anymore.
    /// 
    ////////////////////////////////////////////////////////////////////////////////
    class ResourceManager {
    public:
                    ResourceManager();
        virtual     ~ResourceManager();



    protected:
        T* Load(const std::string& path) {
            return static_cast<Derived*>(this)->Load(path);
        }
    private:
        typedef std::unordered_map<std::string, std::pair<T*, uint32>> ResourceContainer;
        typedef std::unordered_map<std::string, std::string> PathsContainer;

        ResourceContainer   m_Resources;
        PathsContainer      m_Paths;

    };

    /*template <typename Derived, typename T>
    T* ResourceManager::Load(const std::string& path) {
        return static_cast<Derived*>(this)->Load(path);
    }*/
}