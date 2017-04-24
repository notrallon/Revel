#pragma once

namespace rvl {
	class Component {
	public:
		Component();
		~Component();

		virtual void Awake() = 0;
		virtual void Start() = 0;
		virtual void OnDestroy() = 0;



	protected:

		bool destroy = false;

	};
}