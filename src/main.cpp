#include "curses.hpp"

int main() {
    std::unique_ptr<Curses> curses = std::make_unique<Curses>();
    curses->Display();
    return 0;
}
