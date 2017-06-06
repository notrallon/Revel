#pragma once

#include "SharedContext.h"
#include "Common.h"
#include "SceneLayer.h"

#include <Tmx/TmxTileLayer.h>

// Created by Richard Norqvist

namespace rvl {
    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// VertexLayer is responsible for drawing out a Tmx::TileLayer
    ///
    ////////////////////////////////////////////////////////////////////////////////
    class VertexLayer : public SceneLayer {
    public:
                                            VertexLayer(Tmx::TileLayer* layer, int tileWidth, int tileHeight, std::vector<sf::Texture*>& tileset);
        virtual                             ~VertexLayer() override;


	    /////////////////////////////////////
	    /// \brief Draw
	    ///
	    /// Draws all the VertexArrays to a specified sf::RenderWindow
	    /////////////////////////////////////
        void                                Draw(sf::RenderWindow& window) override;

    private:
	    std::vector<sf::VertexArray*>       m_VertexArrays;
	    std::vector<sf::Texture*>&          m_Tilesets;
    };
}