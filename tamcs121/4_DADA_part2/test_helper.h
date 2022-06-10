#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <iostream>
#include <string>

const double DBL_EQUALITY = 1e-6;

bool EXPECT_EQ(const int actual, const int expected, const std::string mssg);
bool EXPECT_EQ(const double actual, const double expected, const std::string mssg);
bool EXPECT_EQ(const double actual[], const double expected[], const unsigned int len, const std::string mssg);

template<typename T>
void print_array(const T arr[], const unsigned int len, std::ostream& out) {
    out << "[";
    if (len > 0) {
        out << arr[0];
    }
    unsigned int i = 1;
    while (i < len) {
        out << ", " << arr[i];
        i++;
    }
    out << "]";
}


#endif
