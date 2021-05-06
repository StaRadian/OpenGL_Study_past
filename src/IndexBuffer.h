//
// Created by Hosung on 2021-04-27.
//

#ifndef STUDY_INDEXBUFFER_H
#define STUDY_INDEXBUFFER_H


class IndexBuffer {
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }
};


#endif //STUDY_INDEXBUFFER_H
