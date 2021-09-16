#ifndef MATERIAL_H
#define MATERIAL_H
#include "typedefs.h"

const Material MAT_WHITE = {
    {0.1, 0.1, 0.1, 1.0}, 
    {1.0, 1.0, 1.0, 1.0}, 
    {1.0, 1.0, 1.0, 1.0}, 
    100.0f                
};
const Material MAT_RED = {
    {0.1, 0.1, 0.1, 1.0}, 
    {1.0, 0.0, 0.0, 1.0}, 
    {1.0, 1.0, 1.0, 1.0}, 
    100.0f                
};
const Material MAT_GREEN = {
    {0.1, 0.1, 0.1, 1.0}, 
    {0.0, 1.0, 0.0, 1.0}, 
    {1.0, 1.0, 1.0, 1.0}, 
    100.0f                
};
const Material MAT_BLUE = {
    {0.1, 0.1, 0.1, 1.0}, 
    {0.0, 0.0, 1.0, 1.0}, 
    {1.0, 1.0, 1.0, 1.0}, 
    100.0f                
};

#endif