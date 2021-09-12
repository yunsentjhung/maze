#include "player.hpp"

// CONSTRUCTOR AND DESTRUCTOR
Player::Player(const int&x, const int& y)
: x(x), y(y), prevX(x), prevY(y), run(true) {

}

Player::~Player() {
  
}

// PUBLIC FUNCTIONS
void Player::move(const char& dir) {
    this->prevX = this->x;
    this->prevY = this->y;
    switch(dir) {
        case Left:
            --this->x;
            break;
        case Up:
            --this->y;
            break;
        case Right:
            ++this->x;
            break;
        case Down:
            ++this->y;
            break;
        case Quit:
            this->run = false;
            break;
        default:
            break;
    }
}

void Player::move_back() {
    this->x = this->prevX;
    this->y = this->prevY;
}

void Player::restart() {
    this->x = START_X;
    this->y = START_Y;
    this->prevX = START_X;
    this->prevY = START_Y;
}

bool Player::collision(const ArrayXY& map) const {
    return true && map[this->y][this->x];
}

bool Player::finish() const {
    return this->x == END_X && this->y == END_Y;
}

int Player::X() const {
    return this->x;
}

int Player::Y() const {
    return this->y;
}

bool Player::R() const {
    return this->run;
}
