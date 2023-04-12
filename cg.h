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

#ifndef _cg_h
#define _cg_h
#include <iostream>
#include <vector>
using namespace std;
/// @brief cg solvor 
/// @param A stiffness matrix
/// @param b right hand vector
/// @param x0 initial geuss 
/// @param maxIterations NB of max iterations
/// @param tolerance convergence criteria 
vector<double> conjugateGradient(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x0, int maxIterations, double tolerance);
double dotProduct(const vector<double>& a, const vector<double>& b) ;



#endif