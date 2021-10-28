#include <pybind11/pybind11.h>

#include "maze_generator.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(dmlab_maze_generator_cpp, m) {
    m.def("create_random_maze", &createRandomMaze);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}