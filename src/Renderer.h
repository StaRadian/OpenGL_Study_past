//
// Created by Hosung on 2021-04-27.
//

#ifndef STUDY_RENDERER_H
#define STUDY_RENDERER_H

#include <gl/glew.h>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();               \
    x;                                          \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

void __debugbreak();

bool GLLogCall(const char* function, const char* file, int line);

#endif //STUDY_RENDERER_H