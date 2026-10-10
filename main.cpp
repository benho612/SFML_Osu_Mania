#include "Application.h"
#include "MainMenu.h"
#include "playingScreen.h"
#include "OptionScreen.h"
#include "GameOverScreen.h"
#include "GreenCircleScreen.h"
#include "BouncingBall.h"
#include "twoDArray.h"
#include "SFMLCard/Card.h"
#include "Phaser/AnimatedSprite.h"
#include "Phaser/Images.h"
#include "PokerAnalysis/testing.h"
int main() {
    MainMenu s0;
    playingScreen s1;
    OptionScreen s2;
    GameOverScreen s3(s1.getPerfect(), s1.getGreat(), s1.getGood(), s1.getMiss());
    GreenCircleScreen s4;
    BouncingBall s5;
    twoDArray s6;
    Card s7(KINGS,HEART);
    AnimatedSprite s8;
    s8.setSpeed(10);
    testing s9;
    Application::addComponents(s0);
    Application::addComponents(s1);
    Application::addComponents(s2);
    Application::addComponents(s3);
    Application::addComponents(s4);
    Application::addComponents(s5);
    Application::addComponents(s6);
    Application::addComponents(s7);
    Application::addComponents(s8);
    Application::addComponents(s9);
    Application::run();
}
