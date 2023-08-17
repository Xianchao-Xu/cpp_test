#include "SolverFactoryContainer.h"

#include "SolverFactory.h"
#include "StaticSolver.h"
#include "ModalSolver.h"

using std::string;
using std::vector;

SolverFactoryContainer* SolverFactoryContainer::m_container = 0;

SolverFactoryContainer& SolverFactoryContainer::instance()
{
    if (m_container == 0) m_container = new SolverFactoryContainer;

    return *m_container;
}

SolverFactoryContainer::SolverFactoryContainer()
{
}

SolverFactoryContainer::~SolverFactoryContainer()
{
    for (string name : m_names) delete m_solver_factories[name];
    m_names.clear();
    m_solver_factories.clear();
}

void SolverFactoryContainer::init()
{
    REGISTER_SOLVER(StaticSolver, "Static");
    REGISTER_SOLVER(ModalSolver, "Modal");
}

vector<string> SolverFactoryContainer::names() const
{
    return m_names;
}

SolverFactory* SolverFactoryContainer::get_factory(const string& name) const
{
    auto it = m_solver_factories.find(name);
    if (it == m_solver_factories.end()) return nullptr;

    return it->second;
}

bool SolverFactoryContainer::register_solver(SolverFactory* fac)
{
    string name = fac->get_alias_name();
    auto it = m_solver_factories.find(name);
    if (it == m_solver_factories.end())
    {
        m_solver_factories[name] = fac;
        m_names.push_back(name);
        return true;
    }

    return false;
}
