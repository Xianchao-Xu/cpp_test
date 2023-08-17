#include "ElementFactory.h"

using std::string;

ElementFactory::ElementFactory(string name, string alias)
    : m_class_name(name), m_alias(alias)
{
}

ElementFactory::~ElementFactory()
{
}

string ElementFactory::get_alias_name()
{
    return m_alias;
}
