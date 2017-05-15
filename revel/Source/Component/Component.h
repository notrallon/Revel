#pragma once

namespace rvl {
	////////////////////////////////////////////////////////////////////////////////
	///
	/// Component is an abstract base class for everything that can be attached to 
	/// GameObjects.
	///
	////////////////////////////////////////////////////////////////////////////////
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