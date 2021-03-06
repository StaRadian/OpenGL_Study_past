//
// Created by Hosung on 2021-05-09.
//

#ifndef STUDY_TEXTURE_H
#define STUDY_TEXTURE_H

#include "Renderer.h"

class Texture {
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;
public:
    Texture(const std::string& path);
    ~Texture();

    void Bind(unsigned  int slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const {return m_Width;};
    inline int GetHeight() const {return  m_Height;};

};


#endif //STUDY_TEXTURE_H
