//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_STATES_H
#define OSUMANIA_STATES_H
#include <map>

enum states_enum{
    MOVING,
    LAST_STATE
};
class States {
private:
    std::map<states_enum, bool> states;
public:
    States();
    void enable_state(states_enum state);
    void disable_state(states_enum state);
    bool check_state(states_enum state);
    void toggle_state(states_enum state);
};

#endif //OSUMANIA_STATES_H
