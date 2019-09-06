#include <hayai.hpp>
#include <vector>

#include "Matrix.hpp"
#include "Routine.hpp"



class MatrixFixture : public ::hayai::Fixture
{
    public:
        MatrixFixture ()
        {
        }

        void SetUp () override
        {
        }
};



BENCHMARK_F (MatrixFixture, Routine, 500, 10)
{
    Routine <int, 100> ();
}



int main (int, char **)
{
    hayai::ConsoleOutputter consoleOutputter;
    hayai::Benchmarker::AddOutputter (consoleOutputter);
    hayai::Benchmarker::RunAllTests ();
}
