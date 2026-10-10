cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME osuMania)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Application.cpp Application.h Component.cpp Component.h SoundEffect.cpp SoundEffect.h Images.cpp Images.h MainMenu.cpp MainMenu.h MouseEvent.cpp MouseEvent.h playingScreen.cpp playingScreen.h OptionScreen.cpp OptionScreen.h Bitmask.cpp Bitmask.h Note.cpp Note.h NotePool.cpp NotePool.h Judgment.h ScoreSystem.cpp ScoreSystem.h GameOverScreen.cpp GameOverScreen.h GreenCircleScreen.cpp GreenCircleScreen.h BouncingBall.cpp BouncingBall.h twoDArray.cpp twoDArray.h SFMLCard/Background.cpp SFMLCard/Background.h SFMLCard/Card.cpp SFMLCard/Card.h SFMLCard/Font.cpp SFMLCard/Font.h SFMLCard/Images.cpp SFMLCard/Images.h SFMLCard/Position.cpp SFMLCard/Position.h SFMLCard/Rank.cpp SFMLCard/Rank.h SFMLCard/Ranks.h SFMLCard/Suit.cpp SFMLCard/Suit.h SFMLCard/Suits.h Phaser/AnimatedSprite.cpp Phaser/AnimatedSprite.h Phaser/Images.cpp Phaser/Images.h Phaser/States.cpp Phaser/States.h PokerAnalysis/PokerCard.cpp PokerAnalysis/PokerCard.h PokerAnalysis/CardHand.cpp PokerAnalysis/CardHand.h PokerAnalysis/CardHandScorer.cpp PokerAnalysis/CardHandScorer.h PokerAnalysis/Deck.cpp PokerAnalysis/Deck.h PokerAnalysis/PokerScore.cpp PokerAnalysis/PokerScore.h PokerAnalysis/rowOfCard.cpp PokerAnalysis/rowOfCard.h PokerAnalysis/SfmlCard.cpp PokerAnalysis/SfmlCard.h PokerAnalysis/SfmlScore.cpp PokerAnalysis/SfmlScore.h PokerAnalysis/SfmlSingleScore.cpp PokerAnalysis/SfmlSingleScore.h PokerAnalysis/PokerSuits.h PokerAnalysis/PokerRanks.h PokerAnalysis/testing.cpp PokerAnalysis/testing.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()