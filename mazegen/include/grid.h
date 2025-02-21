#pragma once 

#include <vector>

#include "cell.h"
#include "config.h"

class Grid{
    public:

    Grid(const GridConfig& gc);

    private:

    // private member functions
    void init();

    // data members 
    int m_rows;
    int m_cols;

    std::vector<Cell> m_grid;

};