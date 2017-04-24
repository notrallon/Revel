#pragma once

namespace rvl {
	class Component {
	public:
		Component();
		~Component();

		virtual void Awake() = 0;
		virtual void Start() = 0;
		//virtual void FixedUpdate() = 0;
		//virtual void Update() = 0;
		//virtual void Draw() = 0;

		bool Destroy();

		virtual void OnDestroy() = 0;



	private:


	};
}