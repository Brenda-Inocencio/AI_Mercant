#include "GameDay.h"
#include <iostream>

GameDay::GameDay()
    : m_phase(DayPhase::Morning), m_phaseTimer(0.f), m_phaseDuration(60.f), day(0), dayTime("Morning") {
}

void GameDay::Update(float dt) {
    m_phaseTimer += dt;

    switch (m_phase) {
    case DayPhase::Morning: {
        dayTime = "Morning";
        break;
    }
    case DayPhase::Day: {
        dayTime = "Day";
        break;
    }
    case DayPhase::Evening: {
        dayTime = "Evening";
        break;
    }
    default:
        break;
    }

    if (m_phaseTimer >= m_phaseDuration)
        NextPhase();
}

void GameDay::NextPhase() {
    m_phaseTimer = 0.f;

    switch (m_phase) {
    case DayPhase::Morning: m_phase = DayPhase::Day; break;
    case DayPhase::Day:     m_phase = DayPhase::Evening; break;
    case DayPhase::Evening: m_phase = DayPhase::Morning; day += 1; break;
    }
}
