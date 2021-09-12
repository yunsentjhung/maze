#include "build.hpp"

// UTILITY FUNCTIONS
bool utility::check_map(ArrayXY& map) {
    // Check finish point
    if(map[END_Y][END_X] == W) {
        return true;
    }

    // Check bottom left corner
    if(map[END_Y - 1][START_X] == W && map[END_Y][START_X + 1] == W) {
        return true;
    }

    // Check bottom right corner
    if(map[END_Y - 1][END_X] == W && map[END_Y][END_X - 1] == W) {
        return true;
    }

    // Check top left corner
    if(map[START_Y][END_X - 1] && map[START_Y + 1][END_X] == W) {
        return true;
    }
    return false;
}

bool utility::check_path(const Point& point, ArrayXY& map) {
    // Check if point is the finish point
    if(point.x == END_X && point.y == END_Y) { return false; }

    // Variables
    Point left, up, right, down;
    bool check[4];

    // Get surrounding point
    left = point.direction(Left);
    up = point.direction(Up);
    right = point.direction(Right);
    down = point.direction(Down);

    // Individual check
    check[0] = utility::connection_check<E>(left, map) && map[left.y][left.x] != W && map[left.y][left.x] != E;
    check[1] = utility::connection_check<E>(up, map) && map[up.y][up.x] != W && map[up.y][up.x] != E;
    check[2] = utility::connection_check<E>(right, map) && map[right.y][right.x] != W && map[right.y][right.x] != E;
    check[3] = utility::connection_check<E>(down, map) && map[down.y][down.x] != W && map[down.y][down.x] != E;
    return std::any_of(check, check + 4, [](bool state) {
        return state;
    });
}

// CREATING MAZE FUNCTIONS
VectorPT utility::get_path(const Point& start, ArrayXY& map) {
    // Variables
    std::vector<Direction> vec{Left, Up, Right, Down};
    VectorPT res{start};
    Point current = res.back();
    Point next;
    int r;

    // Create path
    while(true) {
        r = rand() % vec.size();
        map[current.y][current.x] = E;
        next = current.direction(vec[r]);
        if(current.x == END_X && current.y == END_Y) { return res; }
        if(utility::connection_check<E>(next, map) && map[next.y][next.x] != W) {
            if(vec[r] == Left) { --current.x; }
            else if(vec[r] == Up) { --current.y; }
            else if(vec[r] == Right) { ++current.x; }
            else { ++current.y; }
            res.emplace_back(current);
            vec.clear();
            vec = {Left, Up, Right, Down};
        }
        else {
            vec.erase(vec.begin() + r);
            if(vec.empty()) {
                return res;
            }
        }
    }
}

VectorPT utility::find_path(std::vector<VectorPT>& path, ArrayXY& map) {
    // Variables
    int r1, r2;

    // Remove blocked path
    path.erase(std::remove_if(path.begin(), path.end(), [&](VectorPT& vec) {
        vec.erase(std::remove_if(vec.begin(), vec.end(), [&](Point& pt) {
            return !utility::check_path(pt, map);
        }), vec.end());
        return vec.empty();
    }), path.end());

    // Find path
    while(!path.empty()) {
        r1 = rand() % path.size();
        r2 = rand() % (path[r1].size());
        return utility::get_path(Point(path[r1][r2].x, path[r1][r2].y), map);
    }

    // Finish
    VectorPT res;
    res.emplace_back(Point(0, 0));
    return res;
}

ArrayXY utility::create_map() {
    // Variables
    srand(time(NULL));
    ArrayXY maze;
    std::vector<VectorPT> path;
    Point start(START_X, START_Y);
    Point point;

    // Create border
    for(int y = 0; y < WINDOW_Y; ++y) {
        if(y > 0 && y < WINDOW_Y - 1) {
            maze[y][0] = W;
            std::fill(maze[y].begin() + 1, maze[y].end() - 1, N);
            maze[y][WINDOW_X - 1] = W;
        }
        else {
            std::fill(maze[y].begin(), maze[y].end(), W);
        }
    }

    // Create map
    path.emplace_back(utility::get_path(start, maze));
    while(!(path.back().back().x == 0 && path.back().back().y == 0)) {
        // Creating path
        path.emplace_back(utility::find_path(path, maze));
    }
    utility::filler<N, W>(maze);
    return maze;
}

// TEMPLATE FUNCTIONS
template<State T, State U>
void utility::filler(ArrayXY& map) {
    for(auto itrY = map.begin(); itrY != map.end(); ++itrY) {
        for(auto itrX = itrY->begin(); itrX != itrY->end(); ++itrX) {
            if(*itrX == T) { 
                *itrX = U;
            }
        }
    }
}

template<State T>
bool utility::connection_check(const Point& point, ArrayXY& map) {
    // Variables
    bool check[4];
    int num;

    // Individual check
    check[0] = (map[point.y][point.x - 1] == T);
    check[1] = (map[point.y - 1][point.x] == T);
    check[2] = (map[point.y][point.x + 1] == T);
    check[3] = (map[point.y + 1][point.x] == T);
    num = std::count_if(check, check + 4, [](bool state)   {
        return state;
    }); 
    return num < 2;
}