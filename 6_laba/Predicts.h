#pragma once

template<class T>
bool eqOne(const T& value) {
	if (value == 1) return true;
	else return false;
}
template<class T>
bool eqNull(T value) {
	return (value == 0);
}
template<class T>
bool isMore(const T a, const T b) {
	return (a > b);
}
template<class T>
bool isLess(const T a, const T b) {
	return (a < b);
}
template<class T>
bool isEqual(const T a, const T b) {
	return (a == b);
}

template<class T, class Func>
bool all_of(const T& begin, const T& end, const Func& func) {
	for (T i = begin; i < end; i++) {
		if (!func(*i))
			return false;
	}
	return true;
}


template <class T, class Func>
bool is_sorted(const T& begin, const T& end, const Func& func) {
	for (T i = begin; i < end - 1; i++) {
		if (func(*i, *(i + 1)))
			return false;
	}
	return true;
}

template<class T, class Func>
bool is_palindrome(const T& begin, const T& end, const Func& func) {
	for (T i = begin, j = end - 1; i < j; i++, j--) {
		if (!func(*i, *j))
			return false;
	}
	return true;
}

