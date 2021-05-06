//
// Created by Hosung on 2021-04-27.
//

#ifndef STUDY_VERTEXBUFFER_H
#define STUDY_VERTEXBUFFER_H


class VertexBuffer {
private:
    unsigned int m_RendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};


#endif //STUDY_VERTEXBUFFER_H
