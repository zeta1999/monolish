#include "../../../include/monolish_blas.hpp"
#include "../../internal/monolish_internal.hpp"

namespace monolish {

namespace {
template <typename F1, typename F2, typename F3>
void Dxpay_core(const F1 alpha, const F2 &x, F3 &y) {
  Logger &logger = Logger::get_instance();
  logger.func_in(monolish_func);

  // err
  assert(util::is_same_size(x, y));
  assert(util::is_same_device_mem_stat(x, y));

  const double *xd = x.data();
  double *yd = y.data();
  size_t size = x.size();

  if (x.get_device_mem_stat() == true) {
#if MONOLISH_USE_GPU
#pragma omp target teams distribute parallel for
    for (size_t i = 0; i < size; i++) {
      yd[i] = xd[i] + alpha * yd[i];
    }
#else
    throw std::runtime_error(
        "error USE_GPU is false, but get_device_mem_stat() == true");
#endif
  } else {
#pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
      yd[i] = xd[i] + alpha * yd[i];
    }
  }
  logger.func_out();
}

template <typename F1, typename F2, typename F3>
void Sxpay_core(const F1 alpha, const F2 &x, F3 &y) {
  Logger &logger = Logger::get_instance();
  logger.func_in(monolish_func);

  // err
  assert(util::is_same_size(x, y));
  assert(util::is_same_device_mem_stat(x, y));

  const float *xd = x.data();
  float *yd = y.data();
  size_t size = x.size();

  if (x.get_device_mem_stat() == true) {
#if MONOLISH_USE_GPU
#pragma omp target teams distribute parallel for
    for (size_t i = 0; i < size; i++) {
      yd[i] = xd[i] + alpha * yd[i];
    }
#else
    throw std::runtime_error(
        "error USE_GPU is false, but get_device_mem_stat() == true");
#endif
  } else {
#pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
      yd[i] = xd[i] + alpha * yd[i];
    }
  }
  logger.func_out();
}

} // namespace

namespace blas {
void xpay(const double alpha, const vector<double> &x, vector<double> &y) {
  Dxpay_core(alpha, x, y);
}

void xpay(const float alpha, const vector<float> &x, vector<float> &y) {
  Sxpay_core(alpha, x, y);
}

} // namespace blas

} // namespace monolish