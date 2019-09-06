#include <celero/Celero.h>

#include "Matrix.hpp"
#include "Routine.hpp"



class MatrixFixture : public celero::TestFixture
{
    public:
        MatrixFixture ()
        {
        }

        void setUp (int64_t) override
        {
        }
};



BASELINE_F (Matrix, Routine, MatrixFixture, 500, 10)
{
    Routine <int, 100> ();
}



int main (int argc, char * argv [])
{
    celero::Run (argc, argv);
}
