#pragma once
#include "common/monolish_common.hpp"
#include <stdio.h>
#include <vector>

#if defined USE_MPI
#include <mpi.h>
#endif

namespace monolish {
/**
 * @brief
 * Basic Linear Algebra Subprograms for Dense Matrix, Sparse Matrix, Vector and
 * Scalar
 */
namespace vml {


///////////////////////////////////

void pow(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
         matrix::Dense<double> &C);
void pow(const matrix::Dense<double> &A, const double alpha,
         matrix::Dense<double> &C);
void sqrt(const matrix::Dense<double> &A, matrix::Dense<double> &C);

void sin(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void sinh(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void asin(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void asinh(const matrix::Dense<double> &A, matrix::Dense<double> &C);

void tan(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void tanh(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void atan(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void atanh(const matrix::Dense<double> &A, matrix::Dense<double> &C);

void ceil(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void floor(const matrix::Dense<double> &A, matrix::Dense<double> &C);
void sign(const matrix::Dense<double> &A, matrix::Dense<double> &C);

///////////////////////////////////

void pow(const matrix::CRS<double> &A, const matrix::CRS<double> &B,
         matrix::CRS<double> &C);
void pow(const matrix::CRS<double> &A, const double alpha,
         matrix::CRS<double> &C);
void sqrt(const matrix::CRS<double> &A, matrix::CRS<double> &C);

void sin(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void sinh(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void asin(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void asinh(const matrix::CRS<double> &A, matrix::CRS<double> &C);

void tan(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void tanh(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void atan(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void atanh(const matrix::CRS<double> &A, matrix::CRS<double> &C);

void ceil(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void floor(const matrix::CRS<double> &A, matrix::CRS<double> &C);
void sign(const matrix::CRS<double> &A, matrix::CRS<double> &C);

//////////////////////////////////////////////////////
//  Vector
//////////////////////////////////////////////////////

/**
 * @brief double precision element by element addition of vector a and vector b.
 * @param a double precision monolish vector (size N)
 * @param b double precision monolish vector (size N)
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void add(const vector<double> &a, const vector<double> &b, vector<double> &y);

/**
 * @brief double precision element by element subtraction of vector a and vector
 * b.
 * @param a double precision monolish vector (size N)
 * @param b double precision monolish vector (size N)
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void sub(const vector<double> &a, const vector<double> &b, vector<double> &y);

/**
 * @brief double precision element by element multiplication of vector a and
 * vector b.
 * @param a double precision monolish vector (size N)
 * @param b double precision monolish vector (size N)
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void mul(const vector<double> &a, const vector<double> &b, vector<double> &y);

/**
 * @brief double precision element by element division of vector a and vector b.
 * @param a double precision monolish vector (size N)
 * @param b double precision monolish vector (size N)
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void div(const vector<double> &a, const vector<double> &b, vector<double> &y);

/**
 * @brief double precision scalar and vector addition (y[i] = a[i] + alpha)
 * @param a double precision monolish vector (size N)
 * @param alpha double precision scalar value
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void add(const vector<double> &a, const double alpha, vector<double> &y);

/**
 * @brief double precision scalar and vector subtraction (y[i] = a[i] - alpha)
 * @param a double precision monolish vector (size N)
 * @param alpha double precision scalar value
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void sub(const vector<double> &a, const double alpha, vector<double> &y);

/**
 * @brief double precision scalar and vector multiplication (y[i] = a[i] *
 * alpha)
 * @param a double precision monolish vector (size N)
 * @param alpha double precision scalar value
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void mul(const vector<double> &a, const double alpha, vector<double> &y);

/**
 * @brief double precision scalar and vector division (y[i] = a[i] / alpha)
 * @param a double precision monolish vector (size N)
 * @param alpha double precision scalar value
 * @param y double precision monolish vector (size N)
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void div(const vector<double> &a, const double alpha, vector<double> &y);

/**
 * @brief power to double precision vector elements by double precision scalar value (y[0:N] = pow(a[0:N], alpha))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void pow(const vector<double> &a, const vector<double> &b, vector<double> &y);

/**
 * @brief power to double precision vector elements by double precision vector (y[0:N] = pow(a[0:N], b[0]:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void pow(const vector<double> &a, const double alpha, vector<double> &y);

/**
 * @brief sqrt to double precision vector elements (y[0:N] = sqrt(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void sqrt(const vector<double> &a, vector<double> &y);

/**
 * @brief sin to double precision vector elements (y[0:N] = sin(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void sin(const vector<double> &a, vector<double> &y);

/**
 * @brief sinh to double precision vector elements (y[0:N] = sinh(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void sinh(const vector<double> &a, vector<double> &y);


/**
 * @brief asin to double precision vector elements (y[0:N] = asin(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void asin(const vector<double> &a, vector<double> &y);

/**
 * @brief asinh to double precision vector elements (y[0:N] = asinh(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void asinh(const vector<double> &a, vector<double> &y);

/**
 * @brief tan to double precision vector elements (y[0:N] = tan(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void tan(const vector<double> &a, vector<double> &y);

/**
 * @brief tanh to double precision vector elements (y[0:N] = tanh(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void tanh(const vector<double> &a, vector<double> &y);


/**
 * @brief atan to double precision vector elements (y[0:N] = atan(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void atan(const vector<double> &a, vector<double> &y);

/**
 * @brief atanh to double precision vector elements (y[0:N] = atanh(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void atanh(const vector<double> &a, vector<double> &y);

/**
 * @brief ceil to double precision vector elements (y[0:N] = ceil(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void ceil(const vector<double> &a, vector<double> &y);

/**
 * @brief floor to double precision vector elements (y[0:N] = floor(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void floor(const vector<double> &a, vector<double> &y);

/**
 * @brief sign inversion to double precision vector elements (y[0:N] = sign(a[0:N]))
 * @note
 * - # of computation: N
 * - Multi-threading: true
 * - GPU acceleration: true
 **/
void sign(const vector<double> &a, vector<double> &y);

//////////////////////////////////////////////////////
// Dense
//////////////////////////////////////////////////////

/**
 * @brief double precision element by element addition of Dense matrix A and
 * Dense matrix B.
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param B double precision monolish Dense Matrix (size M x N)
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void add(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
         matrix::Dense<double> &C);

/**
 * @brief double precision element by element subtraction of Dense matrix A and
 * Dense matrix B.
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param B double precision monolish Dense Matrix (size M x N)
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void sub(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
         matrix::Dense<double> &C);

/**
 * @brief double precision element by element multiplication of Dense matrix A
 * and Dense matrix B.
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param B double precision monolish Dense Matrix (size M x N)
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void mul(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
         matrix::Dense<double> &C);

/**
 * @brief double precision element by element division of Dense matrix A and
 * Dense matrix B.
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param B double precision monolish Dense Matrix (size M x N)
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void div(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
         matrix::Dense<double> &C);

/**
 * @brief double precision scalar and Dence matrix addition (C[i][j] = A[i][j] +
 * alpha)
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void add(const matrix::Dense<double> &A, const double alpha,
         matrix::Dense<double> &C);

/**
 * @brief double precision scalar and Dence matrix subtraction (C[i][j] =
 * A[i][j] + alpha)
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void sub(const matrix::Dense<double> &A, const double alpha,
         matrix::Dense<double> &C);

/**
 * @brief double precision scalar and Dence matrix multiplication (C[i][j] =
 * A[i][j] + alpha)
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void mul(const matrix::Dense<double> &A, const double alpha,
         matrix::Dense<double> &C);

/**
 * @brief double precision scalar and Dence matrix division (C[i][j] = A[i][j] +
 * alpha)
 * @param A double precision monolish Dense Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish Dense Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void div(const matrix::Dense<double> &A, const double alpha,
         matrix::Dense<double> &C);

//////////////////////////////////////////////////////
// CRS
//////////////////////////////////////////////////////

/**
 * @brief double precision element by element addition of CRS matrix A and CRS
 * matrix B.
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param B double precision monolish CRS Matrix (size M x N)
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void add(const matrix::CRS<double> &A, const matrix::CRS<double> &B,
         matrix::CRS<double> &C);

/**
 * @brief double precision element by element subtraction of CRS matrix A and
 * CRS matrix B.
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param B double precision monolish CRS Matrix (size M x N)
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void sub(const matrix::CRS<double> &A, const matrix::CRS<double> &B,
         matrix::CRS<double> &C);

/**
 * @brief double precision element by element multiplication of CRS matrix A and
 * CRS matrix B.
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param B double precision monolish CRS Matrix (size M x N)
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void mul(const matrix::CRS<double> &A, const matrix::CRS<double> &B,
         matrix::CRS<double> &C);

/**
 * @brief double precision element by element division of CRS matrix A and CRS
 * matrix B.
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param B double precision monolish CRS Matrix (size M x N)
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void div(const matrix::CRS<double> &A, const matrix::CRS<double> &B,
         matrix::CRS<double> &C);

/**
 * @brief double precision scalar and Dence matrix addition (C[i][j] = A[i][j] +
 * alpha)
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void add(const matrix::CRS<double> &A, const double alpha,
         matrix::CRS<double> &C);

/**
 * @brief double precision scalar and Dence matrix subtraction (C[i][j] =
 * A[i][j] + alpha)
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void sub(const matrix::CRS<double> &A, const double alpha,
         matrix::CRS<double> &C);

/**
 * @brief double precision scalar and Dence matrix multiplication (C[i][j] =
 * A[i][j] + alpha)
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void mul(const matrix::CRS<double> &A, const double alpha,
         matrix::CRS<double> &C);

/**
 * @brief double precision scalar and Dence matrix division (C[i][j] = A[i][j] +
 * alpha)
 * @param A double precision monolish CRS Matrix (size M x N)
 * @param alpha double precision scalar value
 * @param C double precision monolish CRS Matrix (size M x N)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void div(const matrix::CRS<double> &A, const double alpha,
         matrix::CRS<double> &C);

} // namespace vml
} // namespace monolish
