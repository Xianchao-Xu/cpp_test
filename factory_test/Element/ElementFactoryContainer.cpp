#include "ElementFactoryContainer.h"
#include "ElementFactory.h"
#include "Pipe.h"
#include "Beam.h"

using std::string;
using std::vector;

ElementFactoryContainer* ElementFactoryContainer::m_container = 0;

ElementFactoryContainer& ElementFactoryContainer::instance()
{
    if (m_container == 0) m_container = new ElementFactoryContainer;

    return *m_container;
}

ElementFactoryContainer::ElementFactoryContainer()
{
}

ElementFactoryContainer::~ElementFactoryContainer()
{
    for (string name : m_names) delete m_element_factories[name];
    m_names.clear();
    m_element_factories.clear();
}

void ElementFactoryContainer::init()
{
    REGISTER_ELEMENT(Beam, "Beam");
    REGISTER_ELEMENT(Pipe, "Pipe");
}

vector<string> ElementFactoryContainer::names() const
{
    return m_names;
}

ElementFactory* ElementFactoryContainer::get_factory(const string& name) const
{
    auto it = m_element_factories.find(name);
    if (it == m_element_factories.end()) return nullptr;

    return it->second;
}

bool ElementFactoryContainer::register_element(ElementFactory* fac)
{
    string name = fac->get_alias_name();
    auto it = m_element_factories.find(name);
    if (it == m_element_factories.end())
    {
        m_element_factories[name] = fac;
        m_names.push_back(name);
        return true;
    }

    return false;
}
