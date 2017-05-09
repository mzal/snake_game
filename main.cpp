#include <SFML/Graphics.hpp>
#include "snake.hpp"
#define WINDOW_X 800
#define WINDOW_Y 600
#define DELAY_TIME 0.1
#define SCALE 20
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "snake");
    int start_x = 0, start_y = 0, grid_x = WINDOW_X/SCALE, grid_y = WINDOW_Y/SCALE;
    Fruit fruit(WINDOW_X/SCALE, WINDOW_Y/SCALE);
    Snake snake(start_x, start_y, grid_x, grid_y);
    int direction = 0;  //0 = Right, 1 = Up, 2 = Left, 3 = Down
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
                    case sf::Keyboard::Escape:
                        window.close();
                    default:
                        break;
                }
            }
        }

        snake.moveSnake(direction);
        std::vector< std::pair<int,int> > location = snake.getLocation();

        if (fruit.position_x == location[location.size()-1].first && fruit.position_y == location[location.size()-1].second)
            fruit.moveFruit();

        window.clear(sf::Color::Black);
        sf::CircleShape circle(SCALE/2);
        circle.setFillColor(sf::Color::White);
        for (int i=0;i<location.size();i++){
            circle.setPosition(location[i].first*SCALE, location[i].second*SCALE);
            window.draw(circle);
        }
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(fruit.position_x*SCALE, fruit.position_y*SCALE);
        window.draw(circle);
        window.display();
        sf::sleep(delay);
    }
    return 0;
}
