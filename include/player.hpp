#include "build.hpp"

class Player {
public:
    // CONSTRUCTOR AND DESTRUCTOR
    Player(const int&, const int&);
    ~Player();

    // DELETING
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player(Player&&) = delete;
    Player& operator=(Player&&) = delete;

    // PUBLIC FUNCTIONS
    void move(const char&);
    void move_back();
    void restart();
    bool collision(const ArrayXY&) const;
    bool finish() const;
    int X() const;
    int Y() const;
    bool R() const;

private:
    // PRIVATE VARIABLES
    int x, y;
    int prevX, prevY;
    bool run;
};