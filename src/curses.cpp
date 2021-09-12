#include "curses.hpp"

// CONSTRUCTOR AND DESTRUCTOR
Curses::Curses()
: ch(' '), run(true) {
    this->player = std::make_unique<Player>(START_X, START_Y);
    this->set_map();
    initscr();
    raw();
}

Curses::~Curses() {
    endwin();
}

// PUBLIC FUNCTIONS
void Curses::Display() {
    while(this->run) {
        this->display_instruction();
        this->display_map();
        this->get_input();
        this->display_player();
    }
}

// PRIVATE FUNCTIONS
void Curses::get_input() {
    this->ch = getch();
    this->player->move(this->ch);
}

void Curses::set_map() {
    this->map = utility::create_map();
    while(utility::check_map(this->map)) {
        this->map = utility::create_map();
    }
}

void Curses::display_map() {
    for(int y = 0; y < WINDOW_Y; ++y) {
        for(int x = 0; x < WINDOW_X; ++x) {
            mvaddch(y, x, this->map[y][x] ? '0' : ' ');
        }
    }
    mvaddch(START_Y, START_X, 'S');
    mvaddch(END_Y, END_X, 'F');
    move(this->player->Y(), this->player->X());
}

void Curses::display_player() {
    this->run = this->player->R();
    if(this->player->collision(this->map)) {
        this->player->move_back();
    } 
    else if(this->player->finish()) {
        this->player->restart();
        this->set_map();
    }
}

void Curses::display_instruction() {
    mvprintw(WINDOW_Y, 0, "A -> Left, ");
    printw("W -> Up, ");
    printw("D -> Right, ");
    printw("S -> Down, ");
    printw("Q -> Quit\n");
    printw("Maze (ver 1.0) created by Yunsen Tjhung\n");
}