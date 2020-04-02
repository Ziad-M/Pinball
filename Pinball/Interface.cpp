#include "Interface.h"

Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(true);
}

void Interface::getControls(bool & exit, bool & left, bool & right)
{
    sf::Event event;
    while (window.pollEvent(event));
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}

void Interface::drawBall(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}


void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.x, center.y);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.x, center.y);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.x, center.y);
    window.draw(insideCircle);

    // Draw the top line
    sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.x, center.y);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.x, center.y);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall(float position)
{
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(position, 0), outlineColor),
                    sf::Vertex(sf::Vector2f(position, GAME_HEIGHT), outlineColor)
            };
    window.draw(line, 2, sf::Lines);
}

void Interface::drawCeiling(float position)
{
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(0, position), outlineColor),
            sf::Vertex(sf::Vector2f(GAME_WIDTH, position), outlineColor)
    };
    window.draw(line, 2, sf::Lines);
}
void Interface::drawGround(float position)
{
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(0, position), outlineColor),
            sf::Vertex(sf::Vector2f(GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), position), outlineColor),

    };
    window.draw(line, 2, sf::Lines);

    sf::Vertex line2[] =
    {
           sf::Vertex(sf::Vector2f(GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), position), outlineColor),
           sf::Vertex(sf::Vector2f(GAME_WIDTH, position), outlineColor)

    };
    window.draw(line2, 2, sf::Lines);
}


void Interface::drawPop_Bumper(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness+5);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawThrust_Bumper(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness + 5);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}


void Interface::drawVibranium_Bumper(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness + 40);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawKicker(Vector2D position, KickerType type)
{
    float kicker_width = 0.1 * GAME_WIDTH;
    float kicker_height = 0.1 * GAME_HEIGHT;
    sf::VertexArray triangle(sf::Triangles, 3);
    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(position.x, position.y);
    triangle[1].position = sf::Vector2f(position.x + kicker_width * type, position.y);
    triangle[2].position = sf::Vector2f(position.x, position.y - kicker_height);
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Red;
    triangle[2].color = sf::Color::Red;

    window.draw(triangle);
}

void Interface::drawCollectables(Vector2D position)
{

    sf::Font font;
    sf::Transformable;
    if (!font.loadFromFile("Philosopher.ttf"))
    {
        
    }
    sf::Text text;

    text.setFont(font);

    text.setString("C I E 2 0 2");

    text.setCharacterSize(30);

    text.setFillColor(sf::Color::Red);

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(position.x, position.y);

    window.draw(text);

}

void Interface::drawgates(Vector2D Po) {
    sf::VertexArray line2(sf::Lines, 4);
    line2[0].position = sf::Vector2f(Po.x, Po.y);
    line2[1].position = sf::Vector2f(Po.x, Po.y + 600.0f);
    line2[2].position = sf::Vector2f(Po.x + 30.0f, Po.y);
    line2[3].position = sf::Vector2f(Po.x + 30.0f, Po.y + 600.0f);

    line2[0].color = sf::Color::Green;
    line2[1].color = sf::Color::Green;
    line2[2].color = sf::Color::Green;
    line2[3].color = sf::Color::Green;
    window.draw(line2);
}

void Interface::drawswitches(Vector2D Po) {
    sf::VertexArray line2(sf::Lines, 4);
    line2[0].position = sf::Vector2f(Po.x, Po.y);
    line2[1].position = sf::Vector2f(Po.x, Po.y + 600.0f);
    line2[2].position = sf::Vector2f(Po.x + 30.0f, Po.y);
    line2[3].position = sf::Vector2f(Po.x + 30.0f, Po.y + 600.0f);

    line2[0].color = sf::Color::Red;
    line2[1].color = sf::Color::Red;
    line2[2].color = sf::Color::Red;
    line2[3].color = sf::Color::Red;
    window.draw(line2);
}
void Interface::drawSpeedBoosters(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(center.x, center.y);
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Yellow);

    sf::CircleShape circle1(radius);
    circle1.setOrigin(radius, radius);
    circle1.setPosition(center.x + radius * 3, center.y);
    circle1.setOutlineColor(sf::Color::White);
    circle1.setFillColor(sf::Color::Yellow);
    sf::CircleShape circle2(radius);

    circle2.setOrigin(radius, radius);
    circle2.setPosition(center.x + radius * 6, center.y);
    circle2.setOutlineColor(sf::Color::White);
    circle2.setFillColor(sf::Color::Yellow);
    window.draw(circle);
    window.draw(circle1);
    window.draw(circle2);
}
