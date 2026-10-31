#include "mem/mem.hpp"

#include <algorithm>

namespace mem {

IntBuffer::IntBuffer(std::size_t size) : data_(size > 0 ? new int[size]{} : nullptr), size_(size) {}

IntBuffer::IntBuffer(const IntBuffer& other)
    : data_(other.size_ > 0 ? new int[other.size_] : nullptr), size_(other.size_) {
    if (size_ > 0) {
        std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
    }
}

IntBuffer& IntBuffer::operator=(const IntBuffer& other) {
    if (this != &other) {
        IntBuffer copy(other);
        *this = std::move(copy);
    }
    return *this;
}

IntBuffer::~IntBuffer() = default;

std::size_t IntBuffer::size() const {
    return size_;
}

bool IntBuffer::empty() const {
    return size_ == 0;
}

int& IntBuffer::operator[](std::size_t index) {
    return data_[index];
}

const int& IntBuffer::operator[](std::size_t index) const {
    return data_[index];
}

int IntBuffer::sum() const {
    int total = 0;
    for (std::size_t i = 0; i < size_; ++i) {
        total += data_[i];
    }
    return total;
}

}  // namespace mem
