#pragma once
#include "math.h"
#include "iostream"

class Point {
private:
	int x_;
	int y_;
public:
	Point() = default;
	explicit Point(int x) : x_(x), y_(x) {
	};
	Point(int x, int y) : x_(x), y_(y) {
	};
	double Distance() const {
		return sqrt(x_ * x_ + y_ * y_);
	}
	int getX() const {
		return x_;
	}
	int getY() const {
		return y_;
	}
	Point& operator=(Point const& other) = default;
	bool operator==(const Point& other) const {
		if (this->Distance() == other.Distance()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator==(const int& other) const {
		if (this->Distance() == other) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Point& other) const {
		return !(operator==(other));
	}
	bool operator>(const Point& other) const {
		return (this->Distance() > other.Distance());
	}
	bool operator<(const Point& other) const {
		return (this->Distance() < other.Distance());
	}
	friend std::ostream& operator<<(std::ostream& output, const Point& value) {
		output << "(" << value.getX() << ", " << value.getY() << ")";
		return output;
	}
};

