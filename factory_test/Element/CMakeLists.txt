add_library(Element)

target_sources(Element 
PRIVATE
    ElementAPI.h
    ElementFactory.cpp ElementFactory.h
    ElementFactoryContainer.cpp ElementFactoryContainer.h
    Element.cpp Element.h
    Beam.cpp Beam.h
    Pipe.cpp Pipe.h
)