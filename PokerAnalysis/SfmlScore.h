//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_SFMLSCORE_H
#define OSUMANIA_SFMLSCORE_H
#include "PokerScore.h"
#include "SfmlSingleScore.h"
#include <sstream>
#include "SFML/Graphics.hpp"

class SfmlScore
        {
        private:
            std::vector<SfmlSingleScore> GroupsOfText;
            PokerScore localScore;
            double timeRunningProgram;
        public:
            SfmlScore();
            SfmlScore(PokerScore &score, const int timeRunning);
            void addText(SfmlSingleScore &text, int x, int y);
            void draw(sf::RenderTarget &window) const;
            void RoyalFlush();
            void StraightFlush();
            void FourOfAKind();
            void FullHouse();
            void Flush();
            void Straight();
            void ThreeOfAKind();
            void TwoPair();
            void OnePair();
            void HighCard();

};
#endif //OSUMANIA_SFMLSCORE_H
