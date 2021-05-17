//
// Created by Hosung on 2021-04-27.
//

#ifndef STUDY_RENDERER_H
#define STUDY_RENDERER_H

#include <GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();               \
    x;                                          \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

void __debugbreak();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif //STUDY_RENDERER_H