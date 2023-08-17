#ifndef ELEMENT_ELEMENTAPI_H_
#define ELEMENT_ELEMENTAPI_H_

#ifdef WIN32
    #ifdef WIN32DLL
        #ifdef Element_EXPORTS
            #define ElementAPI __declspec(dllexport)
        #else
            #define ElementAPI __declspec(dllimport)
        #endif  // Element_EXPORTS
    #else
        #define ElementAPI
    #endif  // WIN32DLL
#else
    #define ElementAPI
#endif  // WIN32

#endif  // ELEMENT_ELEMENTAPI_H_
