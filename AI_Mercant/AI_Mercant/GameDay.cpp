#include "GameDay.h"
#include <iostream>

GameDay::GameDay()
    : m_phase(DayPhase::Morning),
    m_phaseTimer(0.f),
    m_phaseDuration(60.f)
{}

void GameDay::update(float dt) {
    m_phaseTimer += dt;

    switch (m_phase) {
    case DayPhase::Morning: updateMorning(dt); break;
    case DayPhase::Day:     updateDay(dt);     break;
    case DayPhase::Evening: updateEvening(dt); break;
    }

    if (m_phaseTimer >= m_phaseDuration)
        nextPhase();
}


void GameDay::updateMorning(float dt) {
    std::cout << "Phase : Matin\n";
}

void GameDay::updateDay(float dt) {
    std::cout << "Phase : Journée\n";
}

void GameDay::updateEvening(float dt) {
    std::cout << "Phase : Soir\n";
}

void GameDay::nextPhase() {
    m_phaseTimer = 0.f;

    switch (m_phase) {
    case DayPhase::Morning: m_phase = DayPhase::Day; break;
    case DayPhase::Day:     m_phase = DayPhase::Evening; break;
    case DayPhase::Evening: m_phase = DayPhase::Morning; break;
    }
}
