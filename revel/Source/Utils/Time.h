#pragma once

#include <SFML/System.hpp>

// Created by Richard Norqvist

namespace rvl {
	class Time {
	public:
						Time();
						~Time();

		void			Update();

		////////////////////
		/// \brief const float& DeltaTime() const
		///
		/// \return The deltatime based on timescale.
		////////////////////
		const float&	DeltaTime() const;

		////////////////////
		/// \brief const float& UnScaledDeltaTime() const
		///
		/// \return Deltatime without applying timescale.
		////////////////////
		const float&	UnScaledDeltaTime() const;

		////////////////////
		/// \brief void SetTimeScale(const float&)
		///
		/// Set the timescale to the specified value.
		////////////////////
		void			SetTimeScale(const float& timeScale);

		////////////////////
		/// \brief const float& GetTimeScale() const
		///
		/// \return The timescale.
		////////////////////
		const float&	GetTimeScale() const;

	private:
		float			m_TimeScale;
		float			m_DeltaTime;

		sf::Clock		m_Clock;
		sf::Time		m_ElapsedTime;

		////////////////////
		/// \brief void RestartClock()
		///
		/// Restarts the clock to give us the new deltatime.
		////////////////////
		void			RestartClock();
	};
}