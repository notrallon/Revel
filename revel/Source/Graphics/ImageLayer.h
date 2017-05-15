#pragma once

#include "SceneLayer.h"

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// ImageLayer handles and draws an imagelayer imported from tiled.
	///
	////////////////////////////////////////////////////////////////////////////////
	class ImageLayer : public SceneLayer {
						ImageLayer();
		virtual			~ImageLayer();


		/////////////////////////////////////
		/// \brief Draw(sf::RenderWindow& window)
		///
		/// Draws the imagelayer to the specified sf::RenderWindow
		/////////////////////////////////////
		virtual void	Draw(sf::RenderWindow& window);
	};
}