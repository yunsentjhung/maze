// HEADERS
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <array>

// MACROS
#define WINDOW_X 50
#define WINDOW_Y 20
#define START_X 1
#define START_Y 1
#define END_X 48
#define END_Y 18

// TOOLS
#define LOG(X) std::cout << X << std::endl

// ENUMS
enum Direction {
    Left = 'a', Up = 'w', Right = 'd', Down = 's', Quit = 'q'
};
enum State {
    E = 0, W = 1, N = 2
};

// STRUCT
struct Point {
public:
    // VARIABLES
    int x{0}, y{0};

public:
    // CONSTRUCTOR
    Point() {

    }
    Point(const int& x, const int& y)
    : x(x), y(y) {

    }
    
    // PUBLIC FUNCTIONS
    Point direction(const Direction& dir) const {
        switch(dir){
            case Left:
                return Point(this->x - 1, this->y);
            case Up:
                return Point(this->x, this->y - 1);
            case Right:
                return Point(this->x + 1, this->y);
            case Down:
                return Point(this->x, this->y + 1);
            default:
                return Point(0, 0);
                break;
        }
    }

    // OPERATOR OVERLOADED FUNCTIONS
    bool operator==(const Point& other) const {
        return (this->x == other.x) && (this->y == other.y);
    }
};

// TYPEDEF
typedef std::array<std::array<State, WINDOW_X>, WINDOW_Y> ArrayXY;
typedef std::vector<Point> VectorPT;
