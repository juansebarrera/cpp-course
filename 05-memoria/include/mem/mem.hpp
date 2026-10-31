#pragma once

#include <cstddef>
#include <memory>

namespace mem {

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size);
    IntBuffer(const IntBuffer& other);
    IntBuffer& operator=(const IntBuffer& other);
    IntBuffer(IntBuffer&&) noexcept = default;
    IntBuffer& operator=(IntBuffer&&) noexcept = default;
    ~IntBuffer();

    std::size_t size() const;
    bool empty() const;
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    int sum() const;

private:
    std::unique_ptr<int[]> data_;
    std::size_t size_ = 0;
};

}  // namespace mem
