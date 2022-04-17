#include <pybind11/pybind11.h>
#include "ops.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(sample_package, m) {
    m.doc() = R"pbdoc(
        Basic operations in C++
    )pbdoc";

    m.def("add", &add<int>, R"pbdoc(
        Add two integer numbers
    )pbdoc");

    m.def("add", &add<float>, R"pbdoc(
        Add two float numbers
    )pbdoc");

    m.def("add", &add<double>, R"pbdoc(
        Add two double numbers
    )pbdoc");

    m.def("substract", &substract<int>, R"pbdoc(
        Substract two integer numbers
    )pbdoc");

    m.def("substract", &substract<float>, R"pbdoc(
        Substract two float numbers
    )pbdoc");

    m.def("substract", &substract<double>, R"pbdoc(
        Substract two double numbers
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
