#ifndef SHADER_H__
#define SHADER_H__

#include <ngl/Types.h>
#include <string>

class Shader
{
  public:
    Shader(const std::string &_vert,
           const std::string &_frag);
    ~Shader();
    GLuint getID() const {return m_id;}

  private:
    GLuint m_id;
    enum class DebugMode{COMPILE, LINK};
    void printInfoLog(GLuint _id, DebugMode _mode);

};

#endif
