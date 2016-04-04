#ifndef SDLOPENGL_H__
#define SDLOPENGL_H__

#include <SDL.h>
#include <string>
#include <vector>
#include <map>
#include <ngl/Vec3.h>
#include <memory>
#include <ngl/Camera.h>
#include <ngl/BBox.h>

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
  ~Grid()=default;
  void setVal(int row, int column, int value);
  int getVal(int row, int column);
  int getWidth();
  int getHeight();
  void print();
};

class Model
{
private:
  std::vector<ngl::Vec3> m_verts;
  std::vector<ngl::Vec3> m_vertNormals;
  std::vector<ngl::Vec2> m_UVs;
  std::unique_ptr<ngl::VertexArrayObject> m_vao;
 // ngl::Vec3 m_modelPos; Unnecessary?
  //ngl::Mat4 m_mouseGlobalTX;
  //ngl::Camera *m_camera;
  std::string m_shader;

  void loadMatricesToShader(ngl::Camera *cam);
  //void partitionSpace(ngl::Vec3 minCorner, ngl::Vec3 maxCorner);

public:
  std::vector<ngl::BBox> m_BBoxes;

  Model();
  Model(std::vector<ngl::Vec3> vertList, std::vector<ngl::Vec3> vertNormals, std::string shader);
  Model(std::vector<ngl::Vec3> vertList, std::vector<ngl::Vec3> vertNormals, std::vector<ngl::Vec2> UVs, std::vector<ngl::BBox> BBoxes, std::string shader);
  ~Model()=default;
  void addVert(ngl::Vec3 point);
  void addNormal(ngl::Vec3 normal);
  void addBBox(ngl::BBox BBox);
  void assignShader(std::string shader);
  void buildVAO();
  void drawVAO(ngl::Camera *cam);
};

class Control
{
private:
  float checkDistance(ngl::Vec3 pointA, ngl::Vec3 pointB);
  bool collisionDetect(ngl::BBox A, ngl::BBox B);
  bool checkCollisions(std::vector<ngl::BBox> objList, ngl::BBox otherObj);

public:
  Control();
  ~Control()=default;
  void keyDownEvent(Model *maze, const SDL_KeyboardEvent &event, ngl::Camera *camera);
};

class GameObject
{
private:
  float m_posX;
  float m_posY;
  float m_posZ;

public:
  GameObject();
  ~GameObject()=default;
  GameObject(float x, float y, float z);
  void setPos(float x, float y, float z);
  ngl::Vec3 getPos();
  float getPosX();
  float getPosY();
  float getPosZ();
};

class Character: public GameObject
{
private:
 // float m_speed; //necessary?
  float m_health;

public:
  Character();
  ~Character()=default;
  void setHealth(float health);
  void changeHealth(float health);
  float getHealth();
};

class Player: public Character
{
private:
  void setDefaultShape();

public:
  ngl::Camera m_cam;

  Player();
  Player(ngl::Vec3 pos);
  Player(ngl::Vec3 pos, ngl::Vec3 look, ngl::Vec3 up);
  ~Player()=default;
  void move();
  void shoot();
  void die();
};

class Enemy: public Character
{
private:
  Model m_enemy;

public:
  void spawn();
  void die();
  void move();
  void follow(ngl::Vec3 playerPos);
  void hit();
};

class Maze
{
private:
  std::vector<std::vector<int>> m_cells;
  int m_width;
  int m_height;

  int indexSelect(int index);
  void drawHorizontalWall(int width, int xCount, int zCount);

public:
  Maze();
  Maze(int width, int height);
  Model m_maze;

  int Width();
  int Height();
  Grid generateGrowingTree(int selMethod);
  void generateMaze(Grid plan);
  void displayMaze(ngl::Camera *camera);
};

#endif
