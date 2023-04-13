/**************
 * 
 *  file pcg.h
 *  Created on Wed Mar 15 2023 by
 *  Xiaodong LIU (xiaodong.liu@cnrs.fr)
 * 
 * 
 * 
 * Copyright (c) 2023 Xiaodong LIU GeM, CNRS UMR6183
 **************/
#include "pcg.h"
#include <cmath>
#include "cg.h"
#include <cassert>




vector<double> PCG(vector<vector<double>>& A, vector<double>& b, vector<double>& x0, int maxIter, double tol) {
    int n = b.size();
    std::vector<std::vector<double>> M = icPreconditioner(A);
    vector<double> x = x0;
    vector<double> r = b - matVec(A, x);
    vector<double> z = precond(M,r);
    vector<double> p = z;
    double alpha, beta, rz_new, rz_old = dotProduct(r, z);
    for (int iter = 0; iter < maxIter; iter++) {
        vector<double> Ap = matVec(A, p);
        alpha = rz_old / dotProduct(p, Ap);
        for (int i = 0; i < n; i++) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }
         double residualError = sqrt(dotProduct(r, r));
        if (residualError < tol) 
        {
    //        cout << "Preconditioned Conjugate Gradient converged in " << iter+1 << " iterations." << " with a residual "<<residualError <<endl;
            break;
        }
        z = precond(M,r); // Preconditioning step (z = M^-1 * r)
        rz_new = dotProduct(r, z);

        beta = rz_new / rz_old;
        for (int i = 0; i < n; i++) {
            p[i] = z[i] + beta * p[i];
        }
        rz_old = rz_new;
        if(iter == maxIter - 1) {
    //        cout << "Conjugate Gradient did not converge within " << maxIter << " iterations." << " with a residual "<<sqrt(dotProduct(r, r)) << endl;
        }
    }
    return x;
}







std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b) {
    assert(a.size() == b.size());  // Ensure vectors are of the same size
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] - b[i];
    }
    return result;
}

vector<double> matVec(vector<vector<double>>& A, vector<double>& x) {
    int n = A.size();
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    return y;
}

#include <vector>
#include <cmath>

// Compute the IC (incomplete Cholesky ) preconditioner matrix P
std::vector<std::vector<double>> icPreconditioner(const std::vector<std::vector<double>>& A) {
    size_t n = A.size();
    std::vector<std::vector<double>> P(n, std::vector<double>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        P[i][i] = 1 / A[i][i];
        for (size_t j = i+1; j < n; ++j) {
            double sum = 0;
            for (size_t k = i; k < j; ++k) {
                sum += P[j][k] * A[k][i];
            }
            P[j][i] = -sum / A[j][j];
        }
    }
    return P;
}

// Define the preconditioner function
std::vector<double> precond(const std::vector<std::vector<double>>& M, const std::vector<double>& r) {
    assert(M.size() == r.size());
    std::vector<double> z(r.size());
    for (size_t i = 0; i < M.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < M.size(); ++j) {
            sum += M[i][j] * r[j];
        }
        z[i] = sum;
    }
    return z;
}



