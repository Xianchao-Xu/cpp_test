#include "SolverFactory.h"

using std::string;

SolverFactory::SolverFactory(string name, string alias)
    : m_class_name(name), m_alias(alias)
{
}

SolverFactory::~SolverFactory()
{
}

string SolverFactory::get_alias_name()
{
    return m_alias;
}
