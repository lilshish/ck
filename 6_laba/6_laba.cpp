#include <iostream>
#include <vector>
#include "Predicts.h"
#include "Point.h"

int main() {
	std::vector<int> allOf{ 1, 1, 1, 1 };
	std::cout << "all_of = " << all_of(allOf.cbegin(), allOf.cend(), eqOne<int>) << std::endl;
	std::vector<int> onlyOne{ 1, 4, 0, 0, 2, -7 };
	
	std::vector<int> sorted{ 3, 1, 2, 5 };
	std::cout << "is_sorted = " << is_sorted(sorted.cbegin(), sorted.cend(), isMore<int>) << std::endl;
	std::cout << "is_sorted = " << is_sorted(onlyOne.cbegin(), onlyOne.cend(), isMore<int>) << std::endl;
	std::vector<int> partitioned{ 6, 4, 3, 1, 1, 1, 1 };
	
	std::vector<int> symmetric{ 3, 2, 1, 0, 1, 2, 3 };
	std::cout << "is_palindrome = " << is_palindrome(symmetric.cbegin(), symmetric.cend(), isEqual<int>) << std::endl;
	
	std::cout << "----- With Point class -----" << std::endl;
	Point n1(1, 0), n2(1, 0), n3(1, 0);
	std::vector <Point> arrPoint = { n1, n2, n3 };
	std::cout << "all_of = " << all_of(arrPoint.cbegin(), arrPoint.cend(), eqOne<Point>) <<
		std::endl;
	
	Point n4(3, 2), n5(2, 3), n6(5, 3);
	std::vector <Point> arrPointSort = { n1, n2, n3, n5, n6, n4 };
	std::cout << "is_sorted = " << is_sorted(arrPointSort.cbegin(), arrPointSort.cend(), isMore<Point>) << std::endl;
	
	std::vector <Point> arrPointPal = { n1, n2, n5, n2, n1 };
	std::cout << "is_palindrome = " << is_palindrome(arrPointPal.cbegin(), arrPointPal.cend(), isEqual<Point>) << std::endl;
	return 0;
}