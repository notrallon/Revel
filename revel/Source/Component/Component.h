#pragma once

namespace rvl {
	/////////////////////////////////////
	/// \brief Component
	///
	/// Component is an abstract class that is used
	/// by all the different types of components available.
	/////////////////////////////////////
	class Component {
	public:
							Component();
		virtual				~Component();

		virtual void		Awake() = 0;
		virtual void		Start() = 0;
		virtual void		OnDestroy() = 0;



	protected:
		bool				destroy;
	};
}