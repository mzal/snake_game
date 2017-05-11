#include <cstdlib>
#include <ctime>
#include "fruit.hpp"

Fruit::Fruit(int gr_x, int gr_y){
    grid_x = gr_x;
    grid_y = gr_y;
    srand(time(NULL));
    position_x = rand() % grid_x;
    position_y = rand() % grid_y;
}

void Fruit::moveFruit(std::vector< std::pair<int,int> > location){
    srand(time(NULL));
    bool in_snake;
    do {
        in_snake = false;
        position_x = rand() % grid_x;
        position_y = rand() % grid_y;
        for (int i=0;i<location.size();i++)
            if (position_x == location[i].first && position_y == location[i].second)
                in_snake = true;
    } while(in_snake);

}
