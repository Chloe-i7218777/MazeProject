#ifndef MAZE_H__
#define MAZE_H__

#include <vector>
#include <ngl/Vec3.h>
#include <memory>
#include <ngl/Camera.h>

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

class Maze
{
private:
  std::vector<std::vector<int>> m_cells;
  std::vector<ngl::Vec3> m_verts;
  std::unique_ptr<ngl::VertexArrayObject> m_vao;

public:
  Maze();
  int indexSelect(int index); // Move to private?
  void display2DMaze(Grid plan);
  Grid generateGrowingTree(int width, int height, int selMethod);
  void generate3DMaze(Grid plan);

};


#endif

