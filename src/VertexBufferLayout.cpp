//
// Created by Hosung on 2021-04-30.
//

#include "VertexBufferLayout.h"
#include <vector>
#include "Renderer.h"

template<typename T> void VertexBufferLayout::Push(unsigned int count) {
    //static_assert(false);
}

template<> void VertexBufferLayout::Push<float>(unsigned int count)  {
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template<> void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<> void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}