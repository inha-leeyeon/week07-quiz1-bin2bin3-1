#pragma once
#include "Point.h"
#include <iostream>

class Square : public Point {
public:
    Square(const std::string, int, int, unsigned int = 0);
    unsigned int getSide() const;
    unsigned int getArea() const;
    std::string getName() const;
    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(std::string);
private:
    unsigned int side;
    unsigned int area{ 0 };
    std::string name;
};

