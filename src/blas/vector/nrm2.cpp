#include<iostream>
#include<typeinfo>

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include "../../../include/monolish_blas.hpp"

#ifdef USE_GPU
	#include<cublas.h>
#else
	#include<cblas.h>
#endif

namespace monolish{

	// double ///////////////////
	double blas::nrm2(const vector<double> &x){
		Logger& logger = Logger::get_instance();
		logger.func_in(monolish_func);

		double ans = 0;
		const double* xd = x.data();
		size_t size = x.size();
	
#if USE_GPU
		#pragma acc data pcopyin(xd[0:size])
		#pragma acc host_data use_device(xd)
		{
			ans = cublasDnrm2(size, xd, 1);
		}
#else
		ans = cblas_dnrm2(size, xd, 1);
#endif
		logger.func_out();
		return ans;
	}

	// void ///////////////////
	void blas::nrm2(const vector<double> &x, double& ans){
		ans = nrm2(x);
	}

}
