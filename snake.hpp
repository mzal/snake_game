#include <vector>
#include <utility>
#include "fruit.hpp"

class Snake {
    public:
        Snake(int start_x, int start_y, int gr_x, int gr_y);
        void moveSnake(int direction);
        std::vector< std::pair<int,int> > getLocation(void);
    private:
        int first_x, first_y, grid_x, grid_y;
        int length = 1;
        std::vector< std::pair<int,int> > location;

};

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
                if (first_x < grid_x - 1) first_x += 1;
                break;
            case 1:
                if (first_y > 0) first_y -= 1;
                break;
            case 2:
                if (first_x > 0) first_x -= 1;
                break;
            case 3:
                if (first_y < grid_y - 1) first_y += 1;
                break;
            default:
                break;
        }
    location.erase(location.begin());
    location.push_back(std::make_pair(first_x, first_y));
}

std::vector< std::pair<int,int> > Snake::getLocation(void){
    return location;
}
