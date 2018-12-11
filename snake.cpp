#include <utility>
#include <iostream>
#include "snake.hpp"
#include "fruit.hpp"

Snake::Snake(int start_x, int start_y, int gr_x, int gr_y){
    this->first_x = start_x;
    this->first_y = start_y;
    this->grid_x = gr_x;
    this->grid_y = gr_y;
    location.push_back(std::make_pair(first_x, first_y));
}

void Snake::moveSnake(Direction dir){
    switch(dir){
    case Direction::RIGHT:
	first_x += 1;
	break;
    case Direction::UP:
	first_y -= 1;
	break;
    case Direction::LEFT:
	first_x -= 1;
	break;
    case Direction::DOWN:
	first_y += 1;
	break;
    default:
	break;
    }
    location.erase(location.begin());
    location.push_back(std::make_pair(first_x, first_y));
}

void Snake::enlargeSnake(void){
    location.insert(location.begin(),location[0]);
}

bool Snake::checkCollision(void){
    if (location.size() > 2)
        for (long unsigned int i = 0; i < location.size() - 1; i++)
            if (location[location.size()-1] == location[i]) return true;
    if (location[location.size()-1].first > grid_x ||
        location[location.size()-1].second > grid_y ||
        location[location.size()-1].first < 0 ||
        location[location.size()-1].second < 0)
        return true;
    return false;
}

std::vector< std::pair<int,int> > Snake::getLocation(void){
    return location;
}

void Snake::resetSnake(int start_x, int start_y){
    location.clear();
    first_x = start_x;
    first_y = start_y;
    location.push_back(std::make_pair(first_x,first_y));
}
