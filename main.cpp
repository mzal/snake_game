#include <SFML/Graphics.hpp>
#include <sstream>
#include "snake.hpp"
#include "fruit.hpp"
#include "config.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), WINDOW_TITLE);

    int start_x = 0,
        start_y = 0,
        grid_x = WINDOW_X/SCALE,
        grid_y = WINDOW_Y/SCALE,
        score = 0;

    Direction direction = Direction::RIGHT,
	init_direction = direction;

    Fruit fruit(WINDOW_X/SCALE, WINDOW_Y/SCALE);
    Snake snake(start_x, start_y, grid_x, grid_y);

    std::vector< std::pair<int,int> > location;

    sf::Font font;
    font.loadFromFile(FONT_FILE);
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
		    if (init_direction != Direction::LEFT) direction = Direction::RIGHT;
		    break;
		case sf::Keyboard::Up:
		    if (init_direction != Direction::DOWN) direction = Direction::UP;
		    break;
		case sf::Keyboard::Left:
		    if (init_direction != Direction::RIGHT) direction = Direction::LEFT;
		    break;
		case sf::Keyboard::Down:
		    if (init_direction != Direction::UP) direction = Direction::DOWN;
		    break;
		case sf::Keyboard::R:
		    snake.resetSnake(start_x, start_y);
		    fruit.moveFruit(location);
		    direction = Direction::RIGHT;
		    score = 0;
		    ss.str("");
		    ss << score;
		    score_text.setString(ss.str());
		    break;
		case sf::Keyboard::Escape:
		case sf::Keyboard::Q:
		    window.close();
		default:
		    break;
                }
            }
        }

        init_direction = direction;

        if (!snake.checkCollision()) {
            snake.moveSnake(direction);
            location = snake.getLocation();

            if (fruit.position_x == location[location.size()-1].first && fruit.position_y == location[location.size()-1].second){
                fruit.moveFruit(location);
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
            for (long unsigned int i = 0; i < location.size(); i++){
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
