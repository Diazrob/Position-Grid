#pragma once

class Position {
private:
    unsigned short int x; // grid row max
    unsigned short int y; // grid column max
    unsigned short int hRow; // home row
    unsigned short int hColumn; // home column
    unsigned short int cRow; // current row
    unsigned short int cColumn; // current column
public:
    //constructor
    Position(int row, int column, int rowMax, int columnMax);
    Position(int row, int column);
    Position();

    //accessor
    int getPosition(int row, int column);

    // mutator
    int move(int d);
    int rehome();
    int reset();

    // other
    void display();
    bool operator ==(const Position& rhs); // create an overload of the equal operator
};