#pragma once

#include <sstream>

template<class T>
std::string strjoin(T t, std::string d) {
    std::stringstream ss;
    for (auto ii = std::begin(t); ii != (std::end(t)-1);ii++) {
        ss << *ii << d;
    }
    ss << *(std::end(t)-1);
    return ss.str();
}