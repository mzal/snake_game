#ifndef _FRUIT_H
#define _FRUIT_H

class Fruit {
    public:
        int position_x, position_y, grid_x, grid_y;
        Fruit(int gr_x, int gr_y);
        void moveFruit(void);
};

#endif
