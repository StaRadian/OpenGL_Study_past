//
// Created by Hosung on 2021-04-30.
//

#ifndef STUDY_VERTEXBUFFERLAYOUT_H
#define STUDY_VERTEXBUFFERLAYOUT_H

#include <vector>
#include <GL/glew.h>
#include "Renderer.h"

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned  int GetSizeOfType(unsigned int type){
        switch (type) {
            case GL_FLOAT:              return 4;
            case GL_UNSIGNED_INT:       return 4;
            case GL_UNSIGNED_BYTE:      return 1;
        }
        ASSERT(false)
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
public:
    VertexBufferLayout()
        : m_Stride(0) {}

    template<typename T>
    void Push(unsigned int count);

    inline const std::vector<VertexBufferElement> GetElements() const {return m_Elements;}
    inline unsigned int GetStride() const { return m_Stride; }

};


#endif //STUDY_VERTEXBUFFERLAYOUT_H
