#ifndef _SNAKE_H
#define _SNAKE_H

#include <vector>

class Snake {
    public:
        Snake(int start_x, int start_y, int gr_x, int gr_y);
        void moveSnake(int direction);
        void enlargeSnake(void);
        bool checkCollision(void);
        std::vector< std::pair<int,int> > getLocation(void);
        void resetSnake(int start_x, int start_y);
    private:
        int first_x, first_y, grid_x, grid_y;
        int length = 1;
        std::vector< std::pair<int,int> > location;

};

#endif
