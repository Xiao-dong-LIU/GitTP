/**************
 * 
 *  file cg.cpp
 *  Created on Wed Apr 12 2023 
 *  Xiaodong LIU (xiaodong.liu@cnrs.fr)
 * 
 * 
 * 
 *  Copyright (c) 2023 Xiaodong LIU GeM, CNRS UMR6183
 * 
 **************/


#include "cg.h"
#include <cmath>


vector<double> conjugateGradient(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x0, int maxIterations, double tolerance) {
    int n = A.size();
    vector<double> r(n), p(n), Ap(n);
    vector<double> x=x0;
    // Compute initial residual r = b - Ax
    r = b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            r[i] -= A[i][j] * x[j];
        }
    }
    // Use r as initial search direction
    p = r;
    double rr_old, rr_new;
    rr_old = dotProduct(r, r);
    for(int k = 0; k < maxIterations; k++) {
       
        // Compute Ap = A*p
        for(int i = 0; i < n; i++) {
            Ap[i] = 0.0;
            for(int j = 0; j < n; j++) {
                Ap[i] += A[i][j] * p[j];
            }
        }       

        double alpha = rr_old / dotProduct(p, Ap);

        for(int i = 0; i < n; i++) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }

        rr_new =  dotProduct(r, r);
        double residualError = sqrt(rr_new);
        if(residualError < tolerance) {
      //      cout << "Conjugate Gradient converged in " << k+1 << " iterations"  << " with a residual "<<residualError << endl;
            break;
        }
        double beta = rr_new / rr_old;
        rr_old = rr_new;
        for(int i = 0; i < n; i++) {
            p[i] = r[i] + beta * p[i];
        }
 
        if(k == maxIterations - 1) {
      //      cout << "Conjugate Gradient did not converge within " << maxIterations << " iterations." << endl;
        }
    }
    return x;
}




double dotProduct(const vector<double>& a, const vector<double>& b) {
    double result = 0.0;
    for(int i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}

