#ifndef GAME_IA_
#define GAME_IA_

#include <SFML/Graphics.hpp>

enum class DayPhase { Morning, Day, Evening };

class GameDay {
public:
    GameDay();

    // Appelé depuis ton main
    void update(float dt);

private:
    void updateMorning(float dt);
    void updateDay(float dt);
    void updateEvening(float dt);
    void nextPhase();

private:
    DayPhase m_phase;
    float m_phaseTimer;
    float m_phaseDuration;
};

#endif
