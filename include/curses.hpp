#include "player.hpp"

class Curses {
public:
    // CONSTRUCTOR AND DESTRUCTOR
    Curses();
    ~Curses();
    
    // DELETING
    Curses(const Curses&) = delete;
    Curses& operator=(const Curses&) = delete;
    Curses(Curses&&) = delete;
    Curses& operator=(Curses&&) = delete;
    
    // PUBLIC FUNCTIONS
    void Display();

private:
    // PRIVATE FUNCTIONS
    void get_input();
    void set_map();
    void display_map();
    void display_player();
    void display_instruction();
    
private:
    // PRIVATE VARIABLES
    std::unique_ptr<Player> player;
    ArrayXY map;
    char ch;
    bool run;
};