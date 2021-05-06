//
// Created by Hosung on 2021-04-30.
//

#ifndef STUDY_VERTEXARRAY_H
#define STUDY_VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
private:
    unsigned int m_RendererID;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    void Bind() const;
    void Unbind() const;
};


#endif //STUDY_VERTEXARRAY_H
