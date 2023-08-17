#ifndef SOLVER_SOLVERAPI_H_
#define SOLVER_SOLVERAPI_H_

#ifdef WIN32
    #ifdef WIN32DLL
        #ifdef Solver_EXPORTS
            #define SolverAPI __declspec(dllexport)
        #else
            #define SolverAPI __declspec(dllimport)
        #endif  // Solver_EXPORTS
    #else
        #define SolverAPI
    #endif  // WIN32DLL
#else
    #define SolverAPI
#endif  // WIN32

#endif  // SOLVER_SOLVERAPI_H_
