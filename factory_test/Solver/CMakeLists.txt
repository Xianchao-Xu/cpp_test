add_library(Solver)

target_sources(Solver 
PRIVATE
    SolverAPI.h
    SolverFactory.cpp SolverFactory.h
    SolverFactoryContainer.cpp SolverFactoryContainer.h
    Solver.cpp Solver.h
    StaticSolver.cpp StaticSolver.h
    ModalSolver.cpp ModalSolver.h
)