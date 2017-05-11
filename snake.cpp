#include <utility>
#include <iostream>
#include "snake.hpp"
#include "fruit.hpp"

Snake::Snake(int start_x, int start_y, int gr_x, int gr_y){
    first_x = start_x;
    first_y = start_y;
    grid_x = gr_x;
    grid_y = gr_y;
    location.push_back(std::make_pair(first_x, first_y));
}

void Snake::moveSnake(int direction){
    switch(direction){
            case 0:
                first_x += 1;
                break;
            case 1:
                first_y -= 1;
                break;
            case 2:
                first_x -= 1;
                break;
            case 3:
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
        for (int i=0;i<location.size()-1;i++)
            if (location[location.size()-1] == location[i]) return true;
    if (first_x > grid_x ||
        first_y > grid_y ||
        first_x < 0 ||
        first_y < 0)
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
