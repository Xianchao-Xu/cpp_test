#ifndef MODEL_H_
#define MODEL_H_

class Element;
class Solver;

#include <vector>

class Model
{
private:
    Model();
    virtual ~Model();

public:
    static Model& instance();

    void init();

    void create_objects();

private:
    static Model* m_model;

    std::vector<Element*> m_elements;
    std::vector<Solver*> m_solvers;
};

#endif  // MODEL_H_
