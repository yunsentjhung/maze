COMPILING THE PROGRAM

Required: 
~ ncurses

To compile:
~ make a build folder
~ Go to build folder in the project folder in terminal
~ type cmake ..
~ type make

To run:
~ type ./maze in the build folder


INSTALLING NCURSES

Window:
~ Install MinGW
    ~ Installing MinGW process is present in this website, https://www.rose-hulman.edu/class/csse/resources/MinGW/installation.htm
~ Open MinGW Installation Manager
~ Look for these packages and mark them:
    ~ mingw32-libncurses (dll)
    ~ mingw32-libcurses (dev)
    ~ mingw32-libpdcurses (dll)
    ~ mingw32-libpdcurses (dev)
~ In the context menu, click Installation and then Apply Changes

Ubuntu Linux:
~ Open terminal and run the following command
    ~ sudo apt-get install libncurses5-dev libncursesw5-dev

MacOS:
~ Install brew
    ~ To install brew, run the following command in the terminal
        ~ /usr/bin/ruby -e "$(curl -fsSL ​https://raw.githubusercontent.com/Homebrew/install/master/install​)"
~ Type this in the terminal
    ~ brew install ncurses


WHAT IS THIS?

This project is a maze game project. It is a 2d maze which has simple GUI. However, I feel the star of this project is at the back end. The maze is equipped with my own random maze generator. 

The project consists of 4 cpp files and 4 hpp files. There are 2 main classes in the project, Player and Curses class. They are stored in player.hpp and curses.hpp respectively (Along with player.cpp and curses.cpp for its member functions code). Player class is responsible for storing player coordinates, restarting player position and checking if player reaches the finish line or has a collision. 

The Curses class is mainly responsible for displaying the maze itself, the player and get user input. The game loop is in the public member function Display(). The Curses class is also responsible for getting and displaying a new random maze after player reaches the finish line. The next cpp file is the main.cpp. This is where the program starts. The main.cpp file is kept simple and short.

The data.hpp is where I put all the include files, macros, enums and typedef. There is also a struct Point which is used in the build.hpp and build.cpp. Point is a simple struct that holds x and y coordinate. It is included with operator overloaded function for easy usage. It has a public member function direction(const Direction&) const. This function will return a point at the chosen side (Left, right, up or down).

Lastly, the build.hpp and build.cpp does not contain any class at all. These are utility files. The build.hpp contains a namespace utility which holds functions that are responsible for generating random maze. The build.cpp contains those functions' code. 

One last note, the hpp files are stored in the include folder and the cpp files are stored in the src folder.
