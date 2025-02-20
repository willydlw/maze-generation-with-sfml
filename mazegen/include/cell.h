#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

struct Cell{
    int x;
    int y;

    bool visited;
    bool wallRight;
    bool wallDown;

    //sf::Color color;

    Cell(const int& x, const int& y) : x(x), y(y), visited(false), 
            wallRight(true), wallDown(true) {}
};


#endif 