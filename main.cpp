#include <SFML/Graphics.hpp>
#include <sstream>
#include "snake.hpp"
#include "fruit.hpp"
#define WINDOW_X 800
#define WINDOW_Y 600
#define DELAY_TIME 0.1 //seconds
#define SCALE 20
#define SCORE_F 100
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "snake");

    int start_x = 0,
        start_y = 0,
        grid_x = WINDOW_X/SCALE,
        grid_y = WINDOW_Y/SCALE,
        direction = 0, //0 = Right, 1 = Up, 2 = Left, 3 = Down
        score = 0;

    Fruit fruit(WINDOW_X/SCALE, WINDOW_Y/SCALE);
    Snake snake(start_x, start_y, grid_x, grid_y);

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text score_text;
    score_text.setFont(font);
    std::stringstream ss;
    ss << score;
    score_text.setString(ss.str());

    sf::Text game_over_text;
    game_over_text.setFont(font);
    game_over_text.setString("GAME OVER");
    game_over_text.setOrigin(game_over_text.getLocalBounds().width/2, game_over_text.getLocalBounds().height/2);
    game_over_text.setPosition(sf::Vector2f(WINDOW_X/2,WINDOW_Y/2));

    sf::Time delay = sf::seconds(DELAY_TIME);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Right:
                        if (direction != 2) direction = 0;
                        break;
                    case sf::Keyboard::Up:
                        if (direction != 3) direction = 1;
                        break;
                    case sf::Keyboard::Left:
                        if (direction != 0) direction = 2;
                        break;
                    case sf::Keyboard::Down:
                        if (direction != 1) direction = 3;
                        break;
                    case sf::Keyboard::R:
                        snake.resetSnake(start_x, start_y);
                        fruit.moveFruit();
                        direction = 0;
                        score = 0;
                        ss.str("");
                        ss << score;
                        score_text.setString(ss.str());
                        break;
                    case sf::Keyboard::Escape:
                        window.close();
                    default:
                        break;
                }
            }
        }


        if (!snake.checkCollision()) {
            snake.moveSnake(direction);
            std::vector< std::pair<int,int> > location = snake.getLocation();

            if (fruit.position_x == location[location.size()-1].first && fruit.position_y == location[location.size()-1].second){
                fruit.moveFruit();
                snake.enlargeSnake();
                score += SCORE_F;
                ss.str("");
                ss << score;
                score_text.setString(ss.str());
            }

            //GRAPHICS
            window.clear(sf::Color::Black);
            sf::RectangleShape rectangle(sf::Vector2f(SCALE, SCALE));
            rectangle.setFillColor(sf::Color::Cyan);
            for (int i=0;i<location.size();i++){
                rectangle.setPosition(location[i].first*SCALE, location[i].second*SCALE);
                window.draw(rectangle);
            }
            sf::CircleShape circle(SCALE/2);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(fruit.position_x*SCALE, fruit.position_y*SCALE);
            window.draw(circle);
            window.draw(score_text);
            window.display();
            //END OF GRAPHICS
        }

        else {
            window.draw(game_over_text);
            window.display();
        }
        sf::sleep(delay);
    }

    return 0;
}
