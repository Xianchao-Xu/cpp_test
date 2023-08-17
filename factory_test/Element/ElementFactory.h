#ifndef ELEMENT_ELEMENTFACTORY_H_
#define ELEMENT_ELEMENTFACTORY_H_

#include "ElementAPI.h"

#include <string>

#include "ElementFactoryContainer.h"

class Element;

class ElementAPI ElementFactory
{
public:
    ElementFactory(std::string name, std::string alias);

    virtual ~ElementFactory();

    std::string get_alias_name();

public:
    virtual Element* create() const = 0;

    std::string m_class_name;
    std::string m_alias;
};

template<typename T>
class ElementAPI ElementFactoryClass : public ElementFactory
{
public:
    ElementFactoryClass(std::string name, std::string alias)
        : ElementFactory(name, alias)
    {
        ElementFactoryContainer& container = ElementFactoryContainer::instance();
        container.register_element(this);
    }

    ~ElementFactoryClass() {}

    Element* create() const { return new T(); }
};

#define REGISTER_ELEMENT(the_class, alias) \
    static ElementFactoryClass<the_class> _##the_class##_rc(#the_class, alias);

#endif  // ELEMENT_ELEMENTFACTORY_H_
