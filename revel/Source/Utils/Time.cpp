#include "Time.h"

namespace rvl {
	Time::Time() {
		m_TimeScale = 1.0f;
	}
	
	Time::~Time() {
	}

	void Time::Update() {
		RestartClock();
	}
	
	const float& Time::DeltaTime() const {
		return m_DeltaTime * m_TimeScale;
	}
	
	const float& Time::UnScaledDeltaTime() const {
		return m_DeltaTime;
	}
	
	void Time::SetTimeScale(const float& timeScale) {
		m_TimeScale = timeScale;
	}
	
	const float& Time::GetTimeScale() const {
		return m_TimeScale;
	}
	
	void Time::RestartClock() {
		m_ElapsedTime = m_Clock.restart();
		m_DeltaTime = m_ElapsedTime.asSeconds();
	}
}