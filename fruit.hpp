#include <cstdlib>
#include <ctime>

class Fruit {
    public:
        int position_x, position_y, grid_x, grid_y;
        Fruit(int gr_x, int gr_y);
        void moveFruit(void);
};

Fruit::Fruit(int gr_x, int gr_y){
    grid_x = gr_x;
    grid_y = gr_y;
    srand(time(NULL));
    position_x = rand() % grid_x;
    position_y = rand() % grid_y;
}

void Fruit::moveFruit(void){
    srand(time(NULL));
    position_x = rand() % grid_x;
    position_y = rand() % grid_y;
}


