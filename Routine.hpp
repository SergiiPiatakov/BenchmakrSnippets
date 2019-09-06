#include <algorithm>
#include "Matrix.hpp"



template <typename T, int N>
void Routine ()
{
    // Create dummy matrix.
    Matrix <T, N, N> * m = new Matrix <T, N, N> ();

    // Emulate work.
    std::generate   (m->begin (), m->end (), [m](){static size_t i = 0; return i++;});
    std::replace_if (m->begin (), m->end (), [](const int & v){return v & 1;}, 42);
    std::transform  (m->begin (), m->end (), m->begin (), std::negate<int> () );

    // Remove the matrix
    delete m;
}
