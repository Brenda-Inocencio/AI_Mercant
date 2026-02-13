#ifndef GAME_IA_
#define GAME_IA_

#include <SFML/Graphics.hpp>
#include <string>

enum class DayPhase { Morning, Day, Evening };

class GameDay {
public:
    GameDay();

    // Appelé depuis ton main
    void Update(float dt);
    DayPhase m_phase;
    inline int GetDay() { return day; }
    inline std::string GetTime() { return dayTime; }

private:
    void NextPhase();

private:
    float m_phaseTimer;
    float m_phaseDuration;
    int day;
    std::string dayTime;
};

#endif
