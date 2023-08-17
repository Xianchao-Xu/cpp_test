#include "Model.h"

int main(int argc, char* argv[])
{
    Model& model = Model::instance();
    model.init();
    model.create_objects();

    return 0;
}