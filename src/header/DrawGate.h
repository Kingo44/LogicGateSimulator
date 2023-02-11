#ifndef __DRAW_GATE__
#define __DRAW_GATE__

#include "Logic-Gate.h"
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

class DrawGate{
private:
    LogicGate* pgate;

    #define pinSize 15
    const int CharSize = 48;

    std::string name;

    sf::RectangleShape body;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;

    sf::Text labelName;
    sf::Font labelFont;

    struct pin{
        logicOperandi* connectedLOP;
        std::string name;
        sf::CircleShape body;
        sf::Vector2f offset;
    };

    std::vector<pin> pins;

public:
    DrawGate(LogicGate*);
    DrawGate(DrawGate&&);
    //DrawGate();

    int max(int,int);

    void setPosition(sf::Vector2f);

    void setBody();
    void updateBody();
    void setPins();
    void updatePins();
    void draw(sf::RenderWindow&,bool=true);

    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    std::string getName();
    LogicGate* getGate();

    logicOperandi* pressedPin(sf::Vector2i pos);
    LogicGate* pressedGate(sf::Vector2f pos);

};

#endif