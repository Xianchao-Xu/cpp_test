#ifndef SOLVER_SOLVERFACTORY_H_

#include "SolverAPI.h"

#include <string>

#include "SolverFactoryContainer.h"

class Solver;

// 必须先实现一个基类，再用模板类继承。只有这样，才能通过基类将模板类的实例存储到容器中
class SolverAPI SolverFactory
{
public:
    SolverFactory(std::string name, std::string alias);

    virtual ~SolverFactory();

    std::string get_alias_name();

public:
    virtual Solver* create() const = 0;

    std::string m_class_name;
    std::string m_alias;
};

template<typename T>
class SolverAPI SolverFactoryClass : public SolverFactory
{
public:
    SolverFactoryClass(std::string name, std::string alias)
        : SolverFactory(name, alias)
    {
        SolverFactoryContainer& container = SolverFactoryContainer::instance();
        container.register_solver(this);
    }

    ~SolverFactoryClass() {}

    Solver* create() const { return new T(); }
};

#define REGISTER_SOLVER(the_class, alias) \
    static SolverFactoryClass<the_class> _##the_class##_rc(#the_class, alias);

#endif // !SOLVER_SOLVERFACTORY_H_
