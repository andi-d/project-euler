#pragma once

#include <sstream>
#include <string>
#include <chrono>
#include <map>


template<class T, class D>
std::string strjoin(T t, D d) {
    std::stringstream ss;
    for (auto ii = std::begin(t); ii != (std::end(t)-1);ii++) {
        ss << *ii << d;
    }
    ss << *(std::end(t)-1);
    return ss.str();
}

namespace detail {
    template<typename T> std::string getSuffix();// { return ""; }
    template<> std::string getSuffix<std::nano>() { return "ns"; }
    template<> std::string getSuffix<std::micro>() { return "us"; }
    template<> std::string getSuffix<std::milli>() { return "ms"; }
    template<> std::string getSuffix<std::ratio<1>>() { return "s"; }
}

class Stopwatch
{
private:
    using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;
    struct Trial
    {
        time_point start_;
        time_point end_;
        bool ended_ = false;
    };
public:
    void start(std::string tag = std::string{""})
    {
        Trial t;
        t.start_ = std::chrono::high_resolution_clock::now();
        trials_.insert({ std::move(tag), std::move(t) });
    };

    void stop(std::string tag = std::string{ "" })
    {
        auto t = trials_.find(tag);
        if (t != trials_.end()) {
            stop(t->second);
        }
    }

    template<typename TimeUnit = std::ratio<1>>
    std::string get(std::string tag = std::string{ "" })
    {
        auto t = trials_.begin();
        if (t != std::end(trials_)) {
            if (!tag.empty()) {
                t = trials_.find(tag);
            }
            if (!t->second.ended_) {
                stop(t->second);
            }

            std::ostringstream ss;
            if (!t->first.empty()) {
                ss << t->first << ": ";
            }
            ss << count<TimeUnit>(t->second) << detail::getSuffix<TimeUnit>();
            trials_.erase(t->first);
            lastResult_ = ss.str();
        }
        return lastResult_;
    }

private:
    template<typename TimeUnit = std::ratio<1>>
    double count(Trial &t)
    {
        return std::chrono::duration<double, TimeUnit>(t.end_ - t.start_).count();
    }

    void stop(Trial &t)
    {
        t.end_ = std::chrono::high_resolution_clock::now();
        t.ended_ = true;
    }


    std::map<std::string, Trial> trials_;
    std::string lastResult_;
};