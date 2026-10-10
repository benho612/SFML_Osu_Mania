//
// Created by Ben Ho on 4/3/2023.
//

#include "SfmlScore.h"

std::vector<std::string> PokeType = {"RoyalFlush","StraightFlush","FourOfAKind","FullHouse","Flush",
                                     "Straight","ThreeOfAKind","TwoPair","OnePair","HighCard"};

void SfmlScore::draw(sf::RenderTarget &window) const {
    for (const auto & i : GroupsOfText) {
        i.draw(window);
    }

}

void SfmlScore::addText(SfmlSingleScore &t, int x, int y) {
    SfmlSingleScore text = t;
    text.setPosition({static_cast<float>(x),static_cast<float>(y)});
    GroupsOfText.push_back(text);
}


SfmlScore::SfmlScore() = default;

SfmlScore::SfmlScore(PokerScore &score, const int timeRunning):localScore(score), timeRunningProgram(timeRunning) {
    HighCard();
    OnePair();
    TwoPair();
    ThreeOfAKind();
    Straight();

    FourOfAKind();
    Flush();
    FullHouse();
    StraightFlush();
    RoyalFlush();

}


void SfmlScore::HighCard() {
    SfmlSingleScore HighCard;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[9] <<" \n Probability "<< double(timeRunningProgram/localScore.HighCard) <<": 1"<<std::endl;
    HighCard.setWord(message.str());
    addText(HighCard, 1600, 750);
}

void SfmlScore::OnePair() {
    SfmlSingleScore OnePair;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[8] <<" \n Probability "<< double(timeRunningProgram/localScore.OnePair) <<": 1"<<std::endl;
    OnePair.setWord(message.str());
    addText(OnePair, 1600 , 580);
}

void SfmlScore::TwoPair() {
    SfmlSingleScore TwoPair;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[7] <<" \n Probability "<< double(timeRunningProgram/localScore.TwoPair) <<": 1"<<std::endl;
    TwoPair.setWord(message.str());
    addText(TwoPair, 1600 , 400);
}

void SfmlScore::ThreeOfAKind() {
    SfmlSingleScore ThreeOfAKind;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[6] <<" \n Probability "<< double(timeRunningProgram/localScore.ThreeOfAKind) <<": 1"<<std::endl;
    ThreeOfAKind.setWord(message.str());
    addText(ThreeOfAKind, 1600, 220);
}

void SfmlScore::Straight() {
    SfmlSingleScore Straight;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[5] <<" \n Probability "<< double(timeRunningProgram/localScore.Straight) <<": 1"<<std::endl;
    Straight.setWord(message.str());
    addText(Straight, 1600, 50);
}

void SfmlScore::Flush() {
    SfmlSingleScore Flush;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[4] <<" \n Probability "<< double(timeRunningProgram/localScore.Flush) <<": 1"<<std::endl;
    Flush.setWord(message.str());
    addText(Flush, 700, 750);
}

void SfmlScore::FullHouse() {
    SfmlSingleScore FullHouse;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[3] <<" \n Probability "<< double(timeRunningProgram/localScore.FullHouse) <<": 1"<<std::endl;
    FullHouse.setWord(message.str());
    addText(FullHouse, 700, 580);
}

void SfmlScore::FourOfAKind() {
    SfmlSingleScore FourOfAKind;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[2] <<" \n Probability "<< double(timeRunningProgram/localScore.FourOfAKind) <<": 1"<<std::endl;
    FourOfAKind.setWord(message.str());
    addText(FourOfAKind, 700, 400);
}

void SfmlScore::StraightFlush() {
    SfmlSingleScore StraightFlush;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[1] <<" \n Probability "<< double(timeRunningProgram/localScore.StraightFlush) <<": 1"<<std::endl;
    StraightFlush.setWord(message.str());
    addText(StraightFlush, 700, 220);
}

void SfmlScore::RoyalFlush() {
    SfmlSingleScore RoyalFlush;
    std::stringstream message;
    std::string str;
    message <<"PokeType:" << PokeType[0] <<" \n Probability "<< double(timeRunningProgram/localScore.RoyalFlush) <<": 1"<<std::endl;
    RoyalFlush.setWord(message.str());
    addText(RoyalFlush, 700, 50);
}