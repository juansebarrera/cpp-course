#include <iostream>

#include "mem/mem.hpp"

int main() {
    mem::IntBuffer buffer(5);
    for (std::size_t i = 0; i < buffer.size(); ++i) {
        buffer[i] = static_cast<int>(i) * 10;
    }

    std::cout << "size = " << buffer.size() << '\n';
    std::cout << "sum = " << buffer.sum() << '\n';

    mem::IntBuffer copy = buffer;
    copy[0] = 999;
    std::cout << "original[0] = " << buffer[0] << ", copia[0] = " << copy[0] << '\n';

    mem::IntBuffer empty(0);
    std::cout << "empty.size = " << empty.size() << ", empty.sum = " << empty.sum() << '\n';
    return 0;
}
