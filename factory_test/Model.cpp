#include "Model.h"
#include "Element/ElementFactory.h"
#include "Element/ElementFactoryContainer.h"
#include "Element/Beam.h"
#include "Element/Pipe.h"
#include "Solver/SolverFactory.h"
#include "Solver/SolverFactoryContainer.h"
#include "Solver/StaticSolver.h"
#include "Solver/ModalSolver.h"

Model* Model::m_model = 0;

Model& Model::instance()
{
    if (m_model == 0) m_model = new Model;

    return *m_model;
}

Model::Model()
{
}

Model::~Model()
{
}

void Model::init()
{
    ElementFactoryContainer::instance().init();
    SolverFactoryContainer::instance().init();
}

void Model::create_objects()
{
    ElementFactoryContainer& element_factory_container = ElementFactoryContainer::instance();
    auto pipe = element_factory_container.get_factory("Pipe")->create();
    auto beam = element_factory_container.get_factory("Beam")->create();
    m_elements.push_back(pipe);
    m_elements.push_back(beam);

    SolverFactoryContainer& solver_factory_container = SolverFactoryContainer::instance();
    auto static_solver = solver_factory_container.get_factory("Static")->create();
    auto modal_solver = solver_factory_container.get_factory("Modal")->create();
    m_solvers.push_back(static_solver);
    m_solvers.push_back(modal_solver);
}
