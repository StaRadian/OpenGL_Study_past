//
// Created by Hosung on 2021-04-27.
//

#include "Renderer.h"

#include <iostream>

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

void __debugbreak() {
    std::cout << std::endl;
}

bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()){
        std::cout << "[OpenGL Error] ( 0x" << error << std::hex << " )" << function <<
            "" << file << ":" << line;
        return false;
    }
    return true;
}

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}