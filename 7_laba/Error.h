#pragma once

class MyException : public std::exception {
public:
    explicit MyException(const char* error) : error_(error) {};
    const char* Error() const {
        return error_;
    };
private:
    const char* error_;
};
