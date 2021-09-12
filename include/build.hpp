#include "data.hpp"

namespace utility {
    // UTILITY FUNCTIONS
    bool check_map(ArrayXY&);
    bool check_path(const Point&, ArrayXY&);

    // CREATING MAZE FUNCTIONS
    VectorPT get_path(const Point&, ArrayXY&);
    VectorPT find_path(std::vector<VectorPT>&, ArrayXY&);
    ArrayXY create_map();

    // TEMPLATE FUNCTIONS
    template<State T, State U>
    void filler(ArrayXY&);

    template<State T>
    bool connection_check(const Point&, ArrayXY&);
}