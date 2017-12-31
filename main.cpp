#include <iostream>
#include "cmodel.h"
#include "cfileio.h"
#include "cnlp.h"
#include<ctime>


//from Ipopt library
#include "IpIpoptApplication.hpp"
#include "IpSolveStatistics.hpp"



int main()
{
    clock_t t1;
    t1 =clock();
    t1 =clock() - t1;

    //creating instance of model before reading the input file.
    CModel model;


    //reading the input file.
    {
        CFileio read("input.in",&model);
    }

    //create an instance of N.L.P
    SmartPtr<TNLP> problem = new CNlp(&model);

    // Create an instance of the IpoptApplication
    // We are using the factory, since this allows us to compile this
    // example with an Ipopt Windows DLL
    SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

    //set options.
    app->Options()->SetNumericValue("tol", 1e-9);

    // Intialize the IpoptApplication and process the options
    ApplicationReturnStatus status;
    status = app->Initialize();
    if (status != Solve_Succeeded) {
      printf("\n\n*** Error during initialization!\n");
      return (int) status;
    }

    // Ask Ipopt to solve the problem
      status = app->OptimizeTNLP(problem);

      if (status == Solve_Succeeded) {
        printf("\n\n*** The problem solved!\n");
      }
      else {
        printf("\n\n*** The problem FAILED!\n");
      }

      // As the SmartPtrs go out of scope, the reference count
      // will be decremented and the objects will automatically
      // be deleted.

      return (int) status;
}
