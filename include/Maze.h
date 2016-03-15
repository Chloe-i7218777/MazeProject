#ifndef SDLOPENGL_H__
#define SDLOPENGL_H__

#include <SDL.h>
#include <string>
#include <vector>
#include <ngl/Vec3.h>
#include <memory>
#include <ngl/Camera.h>

class SDLOpenGL
{
  private:
    int m_width;
    int m_height;
    int m_x;
    int m_y;

    std::string m_name;
    SDL_GLContext m_glContext;
    SDL_Window *m_window;

    void init();
    void createGLContext();
    void errorExit(const std::string &_msg) const;


  public:
    SDLOpenGL(const std::string &_name,
              int _x,
              int _y,
              int _width,
              int _height);
    void makeCurrent() const {SDL_GL_MakeCurrent(m_window, m_glContext); }
    void swapWindow() const { SDL_GL_SwapWindow(m_window); }
    void pollEvent(SDL_Event &_event);

};


class Grid
{
private:

  int m_width;
  int m_height;
  std::vector<std::vector<int>> m_grid;

public:
  Grid(int width, int height);
  void setVal(int row, int column, int value);
  int getVal(int row, int column);
  int getWidth();
  int getHeight();
  void print();

};

class Model
{
protected:
  std::vector<ngl::Vec3> m_verts;
  std::unique_ptr<ngl::VertexArrayObject> m_vao;
  void wheelEvent(const SDL_MouseWheelEvent &_event);
  ngl::Vec3 m_modelPos;
  ngl::Mat4 m_mouseGlobalTX;
  ngl::Camera *m_camera;

public:
  Model();
  void buildVAO();
  void drawVAO(ngl::Camera *cam);
};


class Maze: public Model
{
private:
  std::vector<std::vector<int>> m_cells;

  int indexSelect(int index);
  void drawHorizontalWall(int width, int xCount, int zCount);

public:
  Maze();
  void display2DMaze(Grid plan);
  Grid generateGrowingTree(int width, int height, int selMethod);
  void generate3DMaze(Grid plan);
  void display3DMaze();

};

#endif
