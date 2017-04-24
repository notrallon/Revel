#pragma once

#include <SFML/System.hpp>

namespace rvl {
	class Time {
	public:
						Time();
						~Time();

		void			Update();

		const float&	DeltaTime() const;
		const float&	UnScaledDeltaTime() const;

		void			SetTimeScale(const float& timeScale);
		const float&	GetTimeScale() const;

	private:
		float			m_TimeScale;
		float			m_DeltaTime;

		sf::Clock		m_Clock;
		sf::Time		m_ElapsedTime;

		void			RestartClock();
	};
}