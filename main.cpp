#include "pcg.h"
#include "cg.h"

int main() 
{
            
    // stiffness matrix
    vector<vector<double>> A =
        {
            {  1, -1,  0, -1,  0,  0 },
            { -1,  2, -1,  0, -1,  0 },
            {  0, -1,  3,  0,  0, -1 },
            { -1,  0,  0,  4, -1,  0 },
            {  0, -1,  0, -1,  5, -1 },
            {  0,  0, -1,  0, -1,  6 }
        };
    // right hand vector
    vector<double> b = { 1, 0, 0, 0, 0, 0 };
    // max iteration 
    int maxiter = 1000;
    // convergence tolerence
    double tol = 1e-1;

    // Define the initial guess
    vector<double> x0 = { 0.5, 0.5, 0.5, 0.5, 0.5, 0.5 };

    // Call the PCG solver function with a maximum of 1000 iterations and a tolerance of 1e-6
    vector<double> x = PCG(A, b, x0, maxiter, tol);
     // Call the CG solver function with a maximum of 1000 iterations and a tolerance of 1e-6
//    vector<double> x = conjugateGradient(A,b,x0,maxiter, tol);
    // output in the solution in screen 
    for (int i = 0; i < x.size(); ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
    return 0;
}
