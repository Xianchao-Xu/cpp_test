#ifndef SOLVER_SOLVERFACTORYCONTAINER_H_
#define SOLVER_SOLVERFACTORYCONTAINER_H_

#include "SolverAPI.h"

#include <map>
#include <string>
#include <vector>

class SolverFactory;

class SolverAPI SolverFactoryContainer
{
private:
    SolverFactoryContainer();

    virtual ~SolverFactoryContainer();

public:
    static SolverFactoryContainer& instance();

    void init();

    std::vector<std::string> names() const;

    SolverFactory* get_factory(const std::string& name) const;

    bool register_solver(SolverFactory* fac);

private:
    static SolverFactoryContainer* m_container;

    std::vector<std::string> m_names;
    std::map<std::string, SolverFactory*> m_solver_factories;
};

#endif  // SOLVER_SOLVERFACTORYCONTAINER_H_