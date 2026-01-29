#pragma once

#include <iostream>


enum class DayPhase{ Morning, Day, Evening};

class Game{
public:
	Game();

	void update(float dt) {
		switch (m_phase) {

			case DayPhase::Morning: updateMorning(dt); break;
			case DayPhase::Day: updateDay(dt); break;
			case DayPhase::Evening: updateEvening(dt); break;
		}
	}

	void updateMorning(float dt);
	void updateDay(float dt);
	void updateEvening(float dt);

	~Game();

private:
	DayPhase m_phase;
	float m_phaseTime; 

};

