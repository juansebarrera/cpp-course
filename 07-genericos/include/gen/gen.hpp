#pragma once

#include <utility>
#include <vector>

namespace gen {

template <typename T>
T clamp_value(const T& value, const T& low, const T& high) {
    if (value < low) {
        return low;
    }
    if (value > high) {
        return high;
    }
    return value;
}

template <typename T>
class Box {
public:
    explicit Box(T value) : value_(std::move(value)) {}

    const T& get() const {
        return value_;
    }

    void set(T value) {
        value_ = std::move(value);
    }

private:
    T value_;
};

template <typename T>
T sum_all(const std::vector<T>& values) {
    T total{};
    for (const T& value : values) {
        total += value;
    }
    return total;
}

}  // namespace gen
