#include "pcg.h"
#include "cg.h"

int main() 
{
            
    // stiffness matrix
    vector<vector<double>> A =
        {
            {  4, -1,  0, -1,  0,  0 },
            { -1,  4, -1,  0, -1,  0 },
            {  0, -1,  4,  0,  0, -1 },
            { -1,  0,  0,  4, -1,  0 },
            {  0, -1,  0, -1,  4, -1 },
            {  0,  0, -1,  0, -1,  4 }
        };
    // right hand vector
    vector<double> b = { 1, 0, 0, 0, 0, 0 };

    // Define the initial guess
    vector<double> x0 = { 0.5, 0.5, 0.5, 0.5, 0.5, 0.5 };

    // Call the PCG solver function with a maximum of 1000 iterations and a tolerance of 1e-6
    vector<double> x = pcg_solver(A, b, x0, 1000, 1e-6);
 //   conjugateGradient(A,b,x0,1000, 1e-6);
    // output in the solution in screen 
    for (int i = 0; i < x.size(); ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
    
    return 0;
}
