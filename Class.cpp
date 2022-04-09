#include "Class.h"
#include <vector>
#include <iostream>

using namespace std;

void Square::setSide(const float& value) {
    side = value;
}

void Square::setAngle(const float& value) {
    angle = value;
}

void Square::setX(const float& value) {
    x = value;
}

void Square::setY(const float& value) {
    y = value;
}

void Square::setXYAngleSide(const float& fValue, const float& sValue, const float& tValue, const float& foValue) {
    side = fValue;
    angle = sValue;
    x = tValue;
    y = foValue;
}


float Square::getSide() const {
    return side;
}

float Square::getAngle() const {
    return angle;
}

float Square::getX() const {
    return x;
}

float Square::getY() const {
    return y;
}


bool operator == (Square fSide, Square sSide) {
    return (pow(fSide.side, 2) == pow(sSide.side, 2));
};

bool operator != (Square fSide, Square sSide) {
    return (pow(fSide.side, 2) != pow(sSide.side, 2));
};

bool operator > (Square fSide, Square sSide) {
    return (pow(fSide.side, 2) > pow(sSide.side, 2));
};

bool operator < (Square fSide, Square sSide) {
    return (pow(fSide.side, 2) < pow(sSide.side, 2));
};

double operator * (Square side, float a) {
    Square fSide{};
    fSide.side = side.side * a;
    return fSide;
}

void operator + (Square side, std::vector<float> a) {
    Square tSide{};
    tSide.x = side.x + a[0];
    tSide.y = side.y + a[1];
    return s3;
}




Subset::Subset() {
    len = 0;
}

int Subset::getLength() {
    return len;
}
int Subset::Subset::find(char ch) {
    int i;
    for (i = 0; i < len; i++) {
        if (elements[i] == ch)
            return i;
    }
    return -1;
}

void Subset::print() {
    for (int i = 0; i < len; i++) 
        cout << elements[i] << " ";
}


bool Subset::isMember(char ch) {
    if (find(ch) != -1)
        return true;
    else
        return false;
}


Subset Subset::operator + (char ch) {
    Subset new_subset;

    if (len == SIZE) {
        return *this;
    }

    new_subset = *this;
    if (find(ch) == -1) {
        new_subset.elements[new_subset.len] = ch;
        new_subset.len++;
    }

    return new_subset;
}


Subset Subset::operator-(char ch) {
    Subset newset;
    int i = find(ch);
    for (int j = 0; j < len; j++) {
        if (j != i)
            newset = newset + elements[j];
    }
    return newset;
}


Subset Subset::operator + (Subset ob2) {
    Subset newset = *this;

    for (int i = 0; i < ob2.len; i++)
        newset = newset + ob2.elements[i];

    return newset;
}

Subset Subset::operator - (Subset ob2) {
    Subset newset = *this;
    for (int i = 0; i < ob2.len; i++)
        newset = newset - ob2.elements[i];

    return newset;
}
