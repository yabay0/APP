#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> p_x(new int);
    std::cout << "p_x use count: " << p_x.use_count() << "\n";

    *p_x = 5;
    std::cout << "*p_x = " << *p_x << "\n\n";

    std::shared_ptr<int> p_y = p_x;
    std::cout << "after p_y = p_x;\n";
    std::cout << "  p_x use count: " << p_x.use_count() << "\n";
    std::cout << "  p_y use count: " << p_y.use_count() << "\n\n";

    std::weak_ptr<int> w = p_x;
    std::cout << "after weak_ptr w = p_x;\n";
    std::cout << "  p_x use count: " << p_x.use_count() << "\n";
    std::cout << "  w.expired()? " << std::boolalpha << w.expired() << "\n";

    if (auto sp = w.lock()) {
        std::cout << "  *w.lock() = " << *sp << " (value is still alive)\n\n";
    } else {
        std::cout << "  w.lock() failed; resource gone\n\n";
    }

    p_y.reset();
    std::cout << "after p_y.reset();\n";
    std::cout << "  p_x use count: " << p_x.use_count() << "\n";
    std::cout << "  w.expired()? " << w.expired() << "\n\n";

    p_x.reset();
    std::cout << "after p_x.reset();\n";
    std::cout << "  p_x use count: " << p_x.use_count() << "\n"; // 0
    std::cout << "  w.expired()? " << w.expired() << "\n";

    if (auto sp2 = w.lock()) {
        std::cout << "  *w.lock() = " << *sp2 << "\n";
    } else {
        std::cout << "  w.lock() failed: the resource has been destroyed\n";
    }

    return 0;
}
