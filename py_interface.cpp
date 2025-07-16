#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <board.h>
#include <move.h>
#include <rule.h>

namespace py = pybind11;

PYBIND11_MODULE(chinese_chess_lib, m) {
    m.doc() = R"pbdoc(
        Chinese Chess Library
        -----------------------

        .. currentmodule:: chinese_chess_lib

        .. autosummary::
           :toctree: _generate

           get_legal_moves
           warn
    )pbdoc";

    py::class_<Chess>(m, "Chess")
        .def(py::init<>())  // Ĭ�Ϲ��캯��
        .def_readwrite("x", &Chess::x)
        .def_readwrite("y", &Chess::y)
        .def_readwrite("color", &Chess::color)
        .def_readwrite("name", &Chess::name);


    m.def("get_legal_moves", &get_legal_moves, R"pbdoc(
            Get all legal moves for a piece on the board
    )pbdoc");

    m.def("warn", &warn, R"pbdoc(
            Get warnings for the current board state
    )pbdoc");

    m.def("dead", &dead, R"pbdoc(
            Check if a player is dead (i.e., their king is captured)
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}