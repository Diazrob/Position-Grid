#include "Position.h"
#include <iostream>

using namespace std;

void Position::display()
{
    if (cRow > 500) {
        cRow = hRow;
    }
    if (cColumn > 500) {
        cColumn = hColumn;
    }
    char c = '*';
    char d = '.';

    for (int i = x; i >= 0; i--) {
        for (int j = 0; j < y; ++j) {
            if (i == cRow && j == cColumn) {
                cout << c;
            }
            else {
                cout << d;
            }
        }

        cout << endl;
    }
    // if (hColumn != 0) {
     //      hColumn++;
     //}
    cout << "Home Position: (" << hRow << "," << hColumn << ")" << endl;

}

Position::Position() {
    hRow = 0;
    hColumn = 0;
    x = 9; // grid row max
    y = 10; // grid column max
}

Position::Position(int row, int column) {
    hRow = row;
    hColumn = column - 1;
    x = 9; // grid row max
    y = 10; // grid column max
}
Position::Position(int row, int column, int rowMax, int columnMax) {
    hRow = row;
    hColumn = column;
    x = rowMax - 1;
    y = columnMax;
    cRow = row;
    cColumn = column - 1;
}

int Position::reset() {
    cRow = hRow;
    cColumn = hColumn;

    return cRow;
    return cColumn;
}

int Position::rehome() {
    hRow = cRow;
    hColumn = cColumn;

    return hRow;
    return hColumn;
}

int Position::move(int d) {

    if (d == 1) {
        cRow--;
        cColumn--;
    }
    else if (d == 2) {
        cRow--;
    }
    else if (d == 3) {
        cRow--;
        if (cColumn == y || cColumn == y - 1) {
            cColumn = y - 1;
        }
        else {
            cColumn++;
        }
    }
    else if (d == 4) {
        cColumn--;
    }
    else if (d == 6) {
        if (cColumn == y || cColumn == y - 1) {
            cColumn = y - 1;
        }
        else {
            cColumn++;
        }
    }
    else if (d == 7) {
        if (cRow == x) {
            cRow = x;
        }
        else {
            cRow++;
        }
        cColumn--;
    }
    else if (d == 8) {
        if (cRow == x) {
            cRow = x;
        }
        else {
            cRow++;
        }
    }
    else if (d == 9) {
        if (cRow == x) {
            cRow = x;
        }
        else {
            cRow++;
        }
        if (cColumn == y || cColumn == y - 1) {
            cColumn = y - 1;
        }
        else {
            cColumn++;
        }
    }

    return cRow;
    return cColumn;
}

bool Position::operator==(const Position& rhs)
{
    bool same = false;
    if (hRow != rhs.hRow) {
        return same;
    }
    else if (hColumn != rhs.hColumn) {
        return same;
    }
    else if (x != rhs.x) {
        return same;
    }
    else if (y != rhs.y) {
        return same;
    }
    else {
        same = true;
    }
    return same;
}