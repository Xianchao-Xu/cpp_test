#ifndef ELEMENT_ELEMENTFACTORYCONTAINER_H_
#define ELEMENT_ELEMENTFACTORYCONTAINER_H_

#include "ElementAPI.h"

#include <map>
#include <string>
#include <vector>

class ElementFactory;

class ElementAPI ElementFactoryContainer
{
private:
    ElementFactoryContainer();

    virtual ~ElementFactoryContainer();

public:
    static ElementFactoryContainer& instance();

    void init();

    std::vector<std::string> names() const;

    ElementFactory* get_factory(const std::string& name) const;

    bool register_element(ElementFactory* fac);

private:
    static ElementFactoryContainer* m_container;

    std::vector<std::string> m_names;
    std::map<std::string, ElementFactory*> m_element_factories;
};

#endif  // ELEMENT_ELEMENTFACTORYCONTAINER_H_
