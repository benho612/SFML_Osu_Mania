//
// Created by Ben Ho on 4/30/2023.
//

#include "ScoreSystem.h"


std::string ScoreSystem::setString(Judgment judgment) {
    switch (judgment) {
        case Judgment::Perfect: return "Perfect";
            break;
        case Judgment::Great: return "Great";
            break;
        case Judgment::Good: return "Good";
            break;
        case Judgment::Miss: return "Miss";
            break;
        default:
            break;
    }
}

ScoreSystem::ScoreSystem()
{
}


