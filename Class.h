#pragma once
#include <vector>
#define SIZE 128

//2
class Square {

private:
    float side; 
    float angle;
    float x, y; 

public:

    void setSide(const float& value);
    float getSide() const;
    
    void setAngle(const float& value);
    float getAngle() const;

    void setX(const float& value);
    float getX() const;

    void setY(const float& value);
    float getY() const;

    void setXYAngleSide(const float& a, const float& b, const float& c, const float& d);

    friend bool operator == (Square fSide, Square sSide);
    friend bool operator != (Square fSide, Square sSide);
    friend bool operator > (Square fSide, Square sSide);
    friend bool operator < (Square fSide, Square sSide);
    friend double operator * (Square fSide, float a);
    friend void operator + (Square fSide, std::vector<float> a);

};

class Subset {
    int len;
    char elements[SIZE];

    int find(char ch);

public:
    Subset();
    int getLength();
    void print();
    bool isMember(char ch);

    Subset operator + (char ch);
    Subset operator - (char ch);
    Subset operator + (Subset ob2);
    Subset operator - (Subset ob2);
};




