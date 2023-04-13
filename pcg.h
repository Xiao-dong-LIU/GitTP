/**************
 * 
 *  file pcg.h
 *  Created on Wed Mar 15 2023 by
 *  Xiaodong LIU (xiaodong.liu@cnrs.fr)
 * 
 * 
 * 
 *  Copyright (c) 2023 Xiaodong LIU GeM, CNRS UMR6183
 * 
 **************/

#ifndef _pcg_h
#define _pcg_h
#include <iostream>
#include <vector>
using namespace std;
/// @brief pcg solvor 
/// @param A stiffness matrix
/// @param b right hand vector
/// @param x0 initial geuss 
/// @param maxIter NB of max iterations
/// @param tol convergence criteria 
/// @return result
vector<double> PCG(vector<vector<double>>& A, vector<double>& b, vector<double>& x0, int maxIter, double tol);
vector<double> matVec(vector<vector<double>>& A, vector<double>& x) ;
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> precond(const std::vector<std::vector<double>>& M, const std::vector<double>& r);
std::vector<std::vector<double>> icPreconditioner(const std::vector<std::vector<double>>& A) ;
#endif