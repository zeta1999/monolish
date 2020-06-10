#include "../../include/monolish_equation.hpp"
#include "../../include/monolish_blas.hpp"
#include "../monolish_internal.hpp"

namespace monolish{

    ////////////////////////////
    // precondition
    ////////////////////////////
    template<typename T>
        void equation::Jacobi<T>::precond_create(matrix::CRS<T>& A){
            Logger& logger = Logger::get_instance();
            logger.solver_in(monolish_func);

            this->precond.M.resize(A.size());
            //send M
            if(this->precond.M.get_device_mem_stat() == false){
                this->precond.M.send();
            }

            A.get_diag(this->precond.M);

            logger.solver_out();
        }
    template void equation::Jacobi<float>::precond_create(matrix::CRS<float>& A);
    template void equation::Jacobi<double>::precond_create(matrix::CRS<double>& A);

    /////

    template<typename T>
    void equation::Jacobi<T>::precond_apply(const vector<T>& r, vector<T>& z){
        Logger& logger = Logger::get_instance();
        logger.solver_in(monolish_func);

        z = this->precond.M * r; // x = Ab

        logger.solver_out();
    }
    template void equation::Jacobi<float>::precond_apply(const vector<float>& r, vector<float>& z);
    template void equation::Jacobi<double>::precond_apply(const vector<double>& r, vector<double>& z);

    ////////////////////////////
    // solver
    ////////////////////////////


    /////
    template<typename T>
    int equation::Jacobi<T>::monolish_Jacobi(matrix::CRS<T> &A, vector<T> &x, vector<T> &b){
        Logger& logger = Logger::get_instance();
        logger.solver_in(monolish_func);
        logger.solver_out();
        return MONOLISH_SOLVER_NOT_IMPL;
    }
    template int equation::Jacobi<double>::monolish_Jacobi(matrix::CRS<double> &A, vector<double> &x, vector<double> &b);
    template int equation::Jacobi<float>::monolish_Jacobi(matrix::CRS<float> &A, vector<float> &x, vector<float> &b);

    template<typename T>
        int equation::Jacobi<T>::solve(matrix::CRS<T> &A, vector<T> &x, vector<T> &b){
            Logger& logger = Logger::get_instance();
            logger.solver_in(monolish_func);

            int ret = 0;
            if(this->lib == 0){
                ret = monolish_Jacobi(A, x, b);
            }

            logger.solver_out();
		    return ret; // err code
        }

    template int equation::Jacobi<float>::solve(matrix::CRS<float> &A, vector<float> &x, vector<float> &b);
    template int equation::Jacobi<double>::solve(matrix::CRS<double> &A, vector<double> &x, vector<double> &b);
}
