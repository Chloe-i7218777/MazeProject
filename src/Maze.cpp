#include "Maze.h"
#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <ngl/ShaderLib.h>
#include <ngl/Transformation.h>
#include <cmath>
#include <vector>
#include <ngl/Texture.h>
#include <ngl/Material.h>


SDLOpenGL::SDLOpenGL(const std::string &_name,
                     int _x,
                     int _y,
                     int _width,
                     int _height)
{
  m_name=_name;
  m_x=_x;
  m_y=_y;
  m_width=_width;
  m_height=_height;
  init();

}

void SDLOpenGL::init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) <0)
  {
    errorExit("error calling init");

  }
  m_window=SDL_CreateWindow(m_name.c_str(),m_x,m_y,m_width,m_height,SDL_WINDOW_OPENGL);

  if(!m_window)
  {
    errorExit("Could not open window");
  }
  createGLContext();
}

void SDLOpenGL::createGLContext()
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

  m_glContext=SDL_GL_CreateContext(m_window);
}

void SDLOpenGL::errorExit(const std::string &_msg) const
{
  std::cerr<< _msg<<std::endl;
  std::cerr<<SDL_GetError()<<std::endl;
  SDL_Quit();
  exit(EXIT_FAILURE);
}

void SDLOpenGL::pollEvent(SDL_Event &_event)
{
  makeCurrent();
  SDL_PollEvent(&_event);
}

/////////////////////////////////////////////////////////

Grid::Grid(int width, int height)
{
  m_width=width;
  m_height=height;
  m_grid.resize(m_height, std::vector<int>(m_width, 0));
}

void Grid::setVal(int row, int column, int value)
{
  m_grid[row][column]=value;
}

int Grid::getVal(int row, int column)
{
  return m_grid[row][column];
}

int Grid::getWidth()
{
  return m_width;
}

int Grid::getHeight()
{
  return m_height;
}

void Grid::print()
{
  std::cout<<"[";
  for (int i=0; i<m_height; i++)
  {
    std::cout<<"[";
    for (int j=0; j<m_width; j++)
    {
      std::cout<<m_grid[i][j]<<", ";
    }
    std::cout<<"],";
  }
  std::cout<<"]";
}

/////////////////////////////////////////////////////////

Control::Control()
{

}

float Control::checkDistance(ngl::Vec3 pointA, ngl::Vec3 pointB)
{
  ngl::Vec3 distVec(pointA-pointB);

  float distance= sqrt(fabs(distVec[0]*distVec[0]) + fabs(distVec[2]*distVec[2]));

  return distance;
}

bool Control::collisionDetect(ngl::BBox A, ngl::BBox B)
{
  bool collision = 0;

  if ((B.minX()>=A.minX() && B.minX()<=A.maxX()) || (B.maxX()>=A.minX() && B.maxX()<=A.maxX()))
  {
   // std::cout<<"B min and max X is "<<B.minX()<<", "<<B.maxX()<<", A min and max X is"<<A.minX()<<", "<<A.maxX()<<std::endl;
    if ((B.minZ()>=A.minZ() && B.minZ()<=A.maxZ()) || (B.maxZ()>=A.minZ() && B.maxZ()<=A.maxZ()))
    {
      collision = 1;
    }
  }
  return collision;
}

bool Control::checkCollisions(std::vector<ngl::BBox> objList, ngl::BBox otherObj)
{
  for (int i=0; i<int(objList.size()); i++)
  {
    ngl::Vec3 wallCentre(((objList[i].maxX()-objList[i].minX())/2)+objList[i].minX(), ((objList[i].maxY()-objList[i].minY())/2)+objList[i].minY(), ((objList[i].maxZ()-objList[i].minZ())/2)+objList[i].minZ());
    objList[i].setCenter(wallCentre);
    //ngl::Vec3 distVec(wallCentre-otherObj.center());

    //float distance= sqrt(fabs(distVec[0]*distVec[0]) + fabs(distVec[2]*distVec[2]));

    float distance= checkDistance(objList[i].center(), otherObj.center());

   // std::cout<<"distance: "<<distance<<"\n\n";

    if (distance<= 3 || i<=1)
    {
      if (collisionDetect(objList[i], otherObj))
      {
        //std::cout<<"collision:"<<collisionDetect(objList[i], otherObj)<<"\n";
        return i+1;
      }
    }
  }
  return 0;
}

void Control::keyDownEvent(Model *maze, const SDL_KeyboardEvent &event, ngl::Camera *camera)
{
  float forward=-0.08, right=1.5, left=-1.5;

  ngl::BBox camBBox(camera->getEye()[0]-0.65, camera->getEye()[0]+0.65, camera->getEye()[1]-0.65, camera->getEye()[1]+0.65, camera->getEye()[2]-0.65, camera->getEye()[2]+0.65);
  camBBox.setCenter(ngl::Vec3(camera->getEye()[0], camera->getEye()[1], camera->getEye()[2]), 1);

  switch (event.keysym.sym)
  {
    case SDLK_UP :
    {
      ngl::Vec3 look(camera->getEye()[0]- camera->getN()[0], 0.5,camera->getEye()[2]- camera->getN()[2]);
      if (camera->getN()[0]==1)
      {
        look[2]=camera->getEye()[2];
      }
      else if (camera->getN()[2]==-1)
      {
        look[0]= camera->getEye()[0];
      }
      ngl::BBox lookBBox(look[0]-0.3, look[0]+0.3, 0.0, 1.0, look[2]-0.3, look[2]+0.3);
      lookBBox.setCenter(look);

      int BBoxIndex= checkCollisions(maze->m_BBoxes, camBBox);

      if (!BBoxIndex)
      {
        camera->slide(0,0,forward);
      }

      else if (!checkCollisions(maze->m_BBoxes, lookBBox))
      {
        camera->slide(0,0,forward);
      }

      break;
    }
    case SDLK_LEFT : camera->yaw(left); break;
    case SDLK_RIGHT : camera->yaw(right); break;
  }
}

/////////////////////////////////////////////////////////

Model::Model()
{

}

Model::Model(std::vector<ngl::Vec3> vertList, std::vector<ngl::Vec3> vertNormals, std::string shader)
{
  m_verts = vertList;
  m_vertNormals = vertNormals;
  m_shader = shader;
}

Model::Model(std::vector<ngl::Vec3> vertList, std::vector<ngl::Vec3> vertNormals, std::vector<ngl::Vec2> UVs, std::vector<ngl::BBox> BBoxes, std::string shader)
{
  m_verts = vertList;
  m_vertNormals = vertNormals;
  m_UVs= UVs;
  m_BBoxes = BBoxes;
  m_shader = shader;
}

/*float Model::checkDistance(ngl::Vec3 pointA, ngl::Vec3 pointB)
{
  ngl::Vec3 distVec(pointA-pointB);

  float distance= sqrt(fabs(distVec[0]*distVec[0]) + fabs(distVec[2]*distVec[2]));

  return distance;
}*/

void Model::loadMatricesToShader(ngl::Camera *cam)
{
  ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  shader->use(m_shader);
  //shader->use("TextureShader");
  ngl::Mat4 MVP =/*m_mouseGlobalTX**/cam->getVPMatrix();
  //shader->setShaderParamFromMat4("MVP",MVP);
  ngl::ShaderLib::instance()->setRegisteredUniform("MVP", MVP);
}

/*bool Model::collisionDetect(ngl::BBox A, ngl::BBox B)
{
  bool collision = 0;

  if ((B.minX()>=A.minX() && B.minX()<=A.maxX()) || (B.maxX()>=A.minX() && B.maxX()<=A.maxX()))
  {
   // std::cout<<"B min and max X is "<<B.minX()<<", "<<B.maxX()<<", A min and max X is"<<A.minX()<<", "<<A.maxX()<<std::endl;
    if ((B.minZ()>=A.minZ() && B.minZ()<=A.maxZ()) || (B.maxZ()>=A.minZ() && B.maxZ()<=A.maxZ()))
    {
      collision = 1;
    }
  }
  return collision;
}

bool Model::checkCollisions(std::vector<ngl::BBox> objList, ngl::BBox otherObj)
{
  for (int i=0; i<int(objList.size()); i++)
  {
    ngl::Vec3 wallCentre(((objList[i].maxX()-objList[i].minX())/2)+objList[i].minX(), ((objList[i].maxY()-objList[i].minY())/2)+objList[i].minY(), ((objList[i].maxZ()-objList[i].minZ())/2)+objList[i].minZ());
    objList[i].setCenter(wallCentre);
    //ngl::Vec3 distVec(wallCentre-otherObj.center());

    //float distance= sqrt(fabs(distVec[0]*distVec[0]) + fabs(distVec[2]*distVec[2]));

    float distance= checkDistance(objList[i].center(), otherObj.center());

   // std::cout<<"distance: "<<distance<<"\n\n";

    if (distance<= 3 || i<=1)
    {
      if (collisionDetect(objList[i], otherObj))
      {
        //std::cout<<"collision:"<<collisionDetect(objList[i], otherObj)<<"\n";
        return i+1;
      }
    }
  }
  return 0;
}*/

void Model::addVert(ngl::Vec3 point)
{
  m_verts.push_back(point);
}

void Model::addNormal(ngl::Vec3 normal)
{
  m_vertNormals.push_back(normal);
}

void Model::addBBox(ngl::BBox BBox)
{
  m_BBoxes.push_back(BBox);
}

void Model::assignShader(std::string shader)
{
  m_shader = shader;
}

void Model::buildVAO()
{
  m_vao.reset(ngl::VertexArrayObject::createVOA(GL_TRIANGLES));

  m_vao->bind();

  //Set vertices
  m_vao->setData((m_verts.size())*sizeof(ngl::Vec3),m_verts[0].m_x);
  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);
  m_vao->setNumIndices(m_verts.size());

  //Set UVs
  m_vao->setData((m_UVs.size())*sizeof(ngl::Vec2),m_UVs[0].m_x);
  m_vao->setVertexAttributePointer(1,2,GL_FLOAT,0,0);
  m_vao->setNumIndices(m_verts.size());

  //Set normals
  m_vao->setData((m_vertNormals.size())*sizeof(ngl::Vec3),m_vertNormals[0].m_x);
  m_vao->setVertexAttributePointer(2,3,GL_FLOAT,0,0);
  m_vao->setNumIndices(m_vertNormals.size());

  m_vao->unbind();
}

void Model::drawVAO(ngl::Camera *cam)
{
 /* m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
  m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
  m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;*/

  loadMatricesToShader(cam);
  m_vao->bind();
  m_vao->draw();
  m_vao->unbind();
}

/*void Model::keyDownEvent(const SDL_KeyboardEvent &event, ngl::Camera *camera)
{
  float forward=-0.08, right=1.5, left=-1.5;

  ngl::BBox camBBox(camera->getEye()[0]-0.65, camera->getEye()[0]+0.65, camera->getEye()[1]-0.65, camera->getEye()[1]+0.65, camera->getEye()[2]-0.65, camera->getEye()[2]+0.65);
  camBBox.setCenter(ngl::Vec3(camera->getEye()[0], camera->getEye()[1], camera->getEye()[2]), 1);

 // std::cout<<"Min and max z: "<<camBBox.minZ()<<", "<<camBBox.maxZ()<<std::endl;
 // std::cout<<"width: "<<camBBox.width()<<std::endl;

  switch (event.keysym.sym)
  {
    case SDLK_UP :
    {
      ngl::Vec3 look(camera->getEye()[0]- camera->getN()[0], 0.5,camera->getEye()[2]- camera->getN()[2]);
      if (camera->getN()[0]==1)
      {
        look[2]=camera->getEye()[2];
      }
      else if (camera->getN()[2]==-1)
      {
        look[0]= camera->getEye()[0];
      }
      ngl::BBox lookBBox(look[0]-0.3, look[0]+0.3, 0.0, 1.0, look[2]-0.3, look[2]+0.3);
      lookBBox.setCenter(look);

      int BBoxIndex= checkCollisions(m_BBoxes, camBBox);*/

     /* std::cout<<"Eye: "<<"\n";
      for (int i=0; i<4; i++)
      {
        std::cout<<camera->getEye()[i]<<", "<<"\n";
      }
      std::cout<<"\n";

      std::cout<<"Look: "<<"\n";
      for (int i=0; i<4; i++)
      {
        std::cout<<look[i]<<", "<<"\n";
      }
      std::cout<<"\n";*/
/*
      if (!BBoxIndex)
      {
        camera->slide(0,0,forward);
      }

      else if (!checkCollisions(m_BBoxes, lookBBox))
      {
        camera->slide(0,0,forward);
      }*/


/*
      else if (fabs(camera->getN()[0])<fabs(camera->getN()[2]))
      {
        camera->slide(0,0,-forward);

        if (camera->getN()[0]<camera->getN()[2])
        {
          camera->move(0,0,forward);
        }
        else
        {
          camera->move(0,0, -forward);
        }

        ngl::Vec3 closestPoint;

        if (checkDistance(m_BBoxes[BBoxIndex-1].minX(), look) <= checkDistance(m_BBoxes[BBoxIndex-1].maxX(), look))
        {
          closestPoint = m_BBoxes[BBoxIndex-1].minX();
        }
        else if (checkDistance(m_BBoxes[BBoxIndex-1].minX(), look) >= checkDistance(m_BBoxes[BBoxIndex-1].maxX(), look))
        {
          closestPoint = m_BBoxes[BBoxIndex-1].maxX();
        }
        else if (checkDistance(m_BBoxes[BBoxIndex-1].minZ(), look) <= checkDistance(m_BBoxes[BBoxIndex-1].maxZ(), look))
        {
          closestPoint = m_BBoxes[BBoxIndex-1].minZ();
        }
        else if (checkDistance(m_BBoxes[BBoxIndex-1].minZ(), look) >= checkDistance(m_BBoxes[BBoxIndex-1].maxZ(), look))
        {
          closestPoint = m_BBoxes[BBoxIndex-1].maxZ();
        }

        ngl::Vec3 aimVec(fabs(closestPoint[0]-look[0]), 0.5, fabs(closestPoint[2]-look[2]));
        float X = (aimVec*0.01)[0];
        float Y = 0.0;
        float Z = (aimVec*0.01)[2];
        //camera->slide(X,Y,Z);
        camera->moveEye(X, Y, Z);
        //ngl::Vec3 newLook(camera->getEye()[0]+aimVec[0], 0.5, camera->getEye()[2]+aimVec[2]);
        //camera->setLook(newLook);
      }


     // camera->slide(0.0,0.0,-forward*2);


      }
      else if (fabs(camera->getN()[0])>fabs(camera->getN()[2]))
      {
        camera->slide(0,0,-forward);
        if (camera->getN()[0]>camera->getN()[2])
        {
        camera->move(forward,0,0);
        }
        else
        {
          camera->move(-forward,0,0);
        }
      }*/

/*
      break;
    }
    case SDLK_LEFT : camera->yaw(left); break;
    case SDLK_RIGHT : camera->yaw(right); break;
  }
}*/

/////////////////////////////////////////////////////////

GameObject::GameObject()
{

}

GameObject::GameObject(float x, float y, float z)
{
  m_posX=x;
  m_posY=y;
  m_posZ=z;
}

void GameObject::setPos(float x, float y, float z)
{
  m_posX=x;
  m_posY=y;
  m_posZ=z;
}

ngl::Vec3 GameObject::getPos()
{
  return ngl::Vec3(m_posX, m_posY, m_posZ);
}

float GameObject::getPosX()
{
  return m_posX;
}

float GameObject::getPosY()
{
  return m_posY;
}

float GameObject::getPosZ()
{
  return m_posY;
}

/////////////////////////////////////////////////////////

Character::Character()
{

}

void Character::setHealth(float health)
{
  m_health=health;
}

void Character::changeHealth(float health)
{
  m_health+=health;
}

float Character::getHealth()
{
  return m_health;
}

/////////////////////////////////////////////////////////

Player::Player()
{

}

Player::Player(ngl::Vec3 pos)
{
  m_cam.set(pos, ngl::Vec3(0.0), ngl::Vec3(0,1,0));

  setPos(pos[0], pos[1], pos[2]);

  setDefaultShape();
}

Player::Player(ngl::Vec3 pos, ngl::Vec3 look, ngl::Vec3 up)
{
  m_cam.set(pos, look, up);

  setPos(pos[0], pos[1], pos[2]);

  setDefaultShape();
}

void Player::setDefaultShape()
{
  m_cam.setShape(30.0f, float(1024.0/720.0), 0.5f, 100.0f);
}

/////////////////////////////////////////////////////////

Maze::Maze(int width, int height)
{
  m_width= width;
  m_height= height;
}

int Maze::indexSelect(int index)
{
  static int seed = 1;
  srand (time(NULL)*seed);
  seed++;

  int Newest= 0;
  int Random= 0;

  if (m_cells.size())
  {
    Random= rand() % m_cells.size();
    Newest= m_cells.size()-1;
  }

  int newIndex= 0;

  if (index==1)
  {
    newIndex=Newest;
  }

  else if (index==2)
  {
    newIndex=Random;
  }

  return newIndex;
}

void Maze::drawHorizontalWall(int width, int xCount, int zCount)
{
  m_maze.addBBox(ngl::BBox(xCount, xCount+width, 0.0, 1.0, zCount, zCount+1));

  //Back face
  m_maze.addVert(ngl::Vec3(xCount,0,zCount));
  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount));

  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount));

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,0,-1));
  }

  //Front face
  m_maze.addVert(ngl::Vec3(xCount,0,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount+1));

  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,0,1));
  }

  //Left face
  m_maze.addVert(ngl::Vec3(xCount,0,zCount));
  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount,0,zCount+1));

  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount,0,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(-1,0,0));
  }

  //Right face
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount+1));

  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount+width,0,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(1,0,0));
  }

  //Top face
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount+1));

  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount));
  m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
  m_maze.addVert(ngl::Vec3(xCount+width,1 ,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,1,0));
  }
}

int Maze::Width()
{
  return m_width;
}

int Maze::Height()
{
  return m_height;
}

Grid Maze::generateGrowingTree(int selMethod)
{
  Grid mazePlan(m_width, m_height);
  srand (time(NULL));

  //Pick a random element
  int x = rand() % (mazePlan.getWidth()-1);
  int y = rand() % (mazePlan.getHeight()-1);

  //Add it to list of cells
  m_cells.push_back({x,y});

  int seed=1;

  while (true)
  {
    int dx=0;
    int dy=0;

    int index = indexSelect(selMethod);

    x= m_cells[index][0];
    y= m_cells[index][1];

    srand(time(NULL)*seed);
    seed++;

    /*
       * 0001 = North
       * 0010 = East
       * 0100 = South
       * 1000 = West
       */
    int directions[4] = {1,2,4,8};
    std::random_shuffle(&directions[0], &directions[4]);

    int op=0;

    //Iterate through cell's neighbours randomly until an unvisited one is found
    for (int i=0; i<4; i++)
    {

      if (directions[i] == 2)
      {
        dx=1;
        dy=0;
        op=8;
      }

      else if (directions[i] == 4)
      {
        dx=0;
        dy=1;
        op=1;
      }

      else if (directions[i] == 8)
      {
        dx=-1;
        dy=0;
        op=2;
      }

      else if (directions[i] == 1)
      {
        dx=-0;
        dy=-1;
        op=4;
      }

      int nx=x+dx;
      int ny=y+dy;

      //Carve a path between the current cell and the unvisited neighbour
      if (nx >=0 && nx < mazePlan.getWidth() && ny >=0 && ny < mazePlan.getHeight() && mazePlan.getVal(ny, nx)==0)
      {
        //Binary or operator used to add directions together
        mazePlan.setVal(y, x, (mazePlan.getVal(y,x) | directions[i]));
        mazePlan.setVal(ny, nx, (mazePlan.getVal(ny,nx) | op));

        //Add neighbour to cell list
        m_cells.push_back({nx, ny});

        index = -1;

        break;
      }
    }

    //If no unvisited neighbour is found, remove cell from list
    if (index != -1)
    {
      m_cells.erase(m_cells.begin()+index);
    }

    //End when list of cells is empty
    if (m_cells.size() == 0)
    {
      break;
    }
  }

  mazePlan.print();
  return mazePlan;
}

void Maze::generateMaze(Grid plan)
{
  m_width = plan.getWidth()*3+1;
  m_height = plan.getHeight()*3+1;

  //std::vector<ngl::BBox> mazeBBoxes = { ngl::BBox(0.0, float(width), 0.0, 1.0, 0.0, 1.0 ),
                                       // ngl::BBox(0.0, 1.0, 0.0, 1.0, 1.0, float(height))};

  m_maze.addBBox(ngl::BBox(0.0, float(m_width), 0.0, 1.0, 0.0, 1.0 ));
  m_maze.addBBox(ngl::BBox(ngl::BBox(0.0, 1.0, 0.0, 1.0, 1.0, float(m_height))));

  m_maze.assignShader(std::string("diffuse"));

  /*std::vector<ngl::Vec3> mazeVerts = { //Top wall of the maze

                                       //Left face
                                       {0,0,1}, {0,1 ,0}, {0,0,0},
                                       {0,0,1}, {0,1 ,0}, {0,1 ,1},

                                       //Top face
                                       {0,1 ,0}, {0,1 ,1}, {float(width),1 ,0},
                                       {0,1 ,1}, {float(width),1 ,0}, {float(width),1 ,1},

                                       //Right face
                                       {float(width),1 ,0},{float(width),1 ,1}, {float(width),0,1},
                                       {float(width),1 ,0},{float(width),0,0}, {float(width),0,1},

                                       //Back face
                                       {0,0,0},{0,1 ,0}, {float(width),0,0},
                                       {0,1 ,0},{float(width),1 ,0}, {float(width),0,0},

                                       //Front face
                                       {0,0,1}, {0,1 ,1}, {float(width),0,1},
                                       {0,1 ,1}, {float(width),1 ,1}, {float(width),0,1},


                                       //Left wall of the maze

                                       //Left face
                                       {0,0,1}, {0,1 ,1}, {0,0,float(height)},
                                       {0,0,float(height)}, {0,1 ,0}, {0,1 ,float(height)},

                                       //Top face
                                       {0,1 ,1}, {1,1 ,1}, {0,1 ,float(height)},
                                       {0,1 ,float(height)}, {1,1 ,float(height)}, {1,1 ,1},

                                       //Front face
                                       {0,0,float(height)}, {1,0,float(height)}, {0,1 ,float(height)},
                                       {1,1 ,float(height)}, {1,0,float(height)}, {0,1 ,float(height)},

                                       //Right face
                                       {1,1 ,1}, {1,0,1}, {1,1 ,float(height)},
                                       {1,1 ,float(height)}, {1,0,1}, {1,0,float(height)},


                                       //Ground plane

                                       {1,0,1}, {float(width)-1,0,1}, {1,0, float(height)-1},
                                       {float(width-1),0,float(height-1)}, {float(width)-1,0,1}, {1,0, float(height)-1}
                                      };*/

  //Top wall of the maze

  //Left face
  m_maze.addVert(ngl::Vec3(0,0,1));
  m_maze.addVert(ngl::Vec3(0,1,0));
  m_maze.addVert(ngl::Vec3(0,0,0));

  m_maze.addVert(ngl::Vec3(0,0,1));
  m_maze.addVert(ngl::Vec3(0,1,0));
  m_maze.addVert(ngl::Vec3(0,1,1));

  //Top face
  m_maze.addVert(ngl::Vec3(0,1,0));
  m_maze.addVert(ngl::Vec3(0,1,1));
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,0));

  m_maze.addVert(ngl::Vec3(0,1,1));
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,0));
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,1));

  //Right face
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,0));
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,1));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,1));

  m_maze.addVert(ngl::Vec3(float(m_width),1 ,0));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,0));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,1));

  //Back face
  m_maze.addVert(ngl::Vec3(0,0,0));
  m_maze.addVert(ngl::Vec3(0,1,0));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,0));

  m_maze.addVert(ngl::Vec3(0,0,1));
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,0));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,0));

  //Front face
  m_maze.addVert(ngl::Vec3(0,0,1));
  m_maze.addVert(ngl::Vec3(0,1,1));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,1));

  m_maze.addVert(ngl::Vec3(0,1,1));
  m_maze.addVert(ngl::Vec3(float(m_width),1 ,1));
  m_maze.addVert(ngl::Vec3(float(m_width),0 ,1));

  //Left wall of the maze

  //Left face
  m_maze.addVert(ngl::Vec3(0,0,1));
  m_maze.addVert(ngl::Vec3(0,1,1));
  m_maze.addVert(ngl::Vec3(0,0,float(m_height)));

  m_maze.addVert(ngl::Vec3(0,0,float(m_height)));
  m_maze.addVert(ngl::Vec3(0,1,0));
  m_maze.addVert(ngl::Vec3(0,1,float(m_height)));

  //Top face
  m_maze.addVert(ngl::Vec3(0,1,1));
  m_maze.addVert(ngl::Vec3(1,1,1));
  m_maze.addVert(ngl::Vec3(0,1,float(m_height)));

  m_maze.addVert(ngl::Vec3(0,1,float(m_height)));
  m_maze.addVert(ngl::Vec3(1,1,float(m_height)));
  m_maze.addVert(ngl::Vec3(1,1,1));

  //Front face
  m_maze.addVert(ngl::Vec3(0,0,float(m_height)));
  m_maze.addVert(ngl::Vec3(1,0,float(m_height)));
  m_maze.addVert(ngl::Vec3(0,1,float(m_height)));

  m_maze.addVert(ngl::Vec3(1,1,float(m_height)));
  m_maze.addVert(ngl::Vec3(1,0,float(m_height)));
  m_maze.addVert(ngl::Vec3(0,1,float(m_height)));

  //Right face
  m_maze.addVert(ngl::Vec3(1,1,1));
  m_maze.addVert(ngl::Vec3(1,0,1));
  m_maze.addVert(ngl::Vec3(1,1,float(m_height)));

  m_maze.addVert(ngl::Vec3(1,1,float(m_height)));
  m_maze.addVert(ngl::Vec3(1,0,1));
  m_maze.addVert(ngl::Vec3(1,0,float(m_height)));

  //Ground plane

  m_maze.addVert(ngl::Vec3(1,0,1));
  m_maze.addVert(ngl::Vec3(float(m_width)-1,0,1));
  m_maze.addVert(ngl::Vec3(1,0, float(m_height)-1));

  m_maze.addVert(ngl::Vec3(float(m_width-1),0,float(m_height-1)));
  m_maze.addVert(ngl::Vec3(float(m_width)-1,0,1));
  m_maze.addVert(ngl::Vec3(1,0, float(m_height)-1));


  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(-1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,1,0));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,0,-1));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,0,1));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(-1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,1,0));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,0,1));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_maze.addNormal(ngl::Vec3(0,1,0));
  }

  int xCount=1, zCount=0;

  for (int row=0; row<plan.getHeight(); row++)
  {
    xCount=1;
    zCount+=3;
    bool flag = 0;
    for (int col=0; col<plan.getWidth();col++)
    {
      if ((plan.getVal(row,col) & 4) !=0) //If SOUTH, increment x counter
      {
        if (flag)
        {
          xCount++;
          flag=0;
        }
        else
        {
          xCount+=2;
          flag=1;
        }
      }
      else //If not, draw horizontal wall
      {
        if (flag)
        {
          drawHorizontalWall(1, xCount, zCount);
          xCount+=1;
          flag=0;
        }
        else
        {
          drawHorizontalWall(2, xCount, zCount);
          xCount+=2;
          flag=1;
        }
      }

      if ((plan.getVal(row,col) & 2) != 0) //If EAST, draw horizontal wall
      {
        if (flag)
        {
          drawHorizontalWall(1, xCount, zCount);
          xCount+=1;
          flag=0;
        }
        else
        {
          drawHorizontalWall(2, xCount, zCount);
          xCount+=2;
          flag=1;
        }
      }
      else //If not, draw vertical wall
      {
        m_maze.addBBox(ngl::BBox(xCount, xCount+1, 0.0, 1.0, zCount-2, zCount+1));

        //Back face
        m_maze.addVert(ngl::Vec3(xCount,0,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount-2));

        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount-2));

        for (int i=0;i<6;i++)
        {
          m_maze.addNormal(ngl::Vec3(0,0,-1));
        }

        //Front face
        m_maze.addVert(ngl::Vec3(xCount,0,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount+1));

        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_maze.addNormal(ngl::Vec3(0,0,1));
        }

        //Left face
        m_maze.addVert(ngl::Vec3(xCount,0,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount,0,zCount+1));

        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount,0,zCount+1));
        //ngl::BBox vertWall(xCount, xCount+1, 0.0, 1.0, zCount-2, zCount+1);

        //m_maze.addBBox(vertWall);
        for (int i=0;i<6;i++)
        {
          m_maze.addNormal(ngl::Vec3(-1,0,0));
        }

        //Right face
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount+1));

        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount+1,0,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_maze.addNormal(ngl::Vec3(1,0,0));
        }

        //Top face
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));

        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount-2));
        m_maze.addVert(ngl::Vec3(xCount+1,1 ,zCount+1));
        m_maze.addVert(ngl::Vec3(xCount,1 ,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_maze.addNormal(ngl::Vec3(0,1,0));
        }

        xCount++;
        flag=0;
      }
    }
  }
  //partitionSpace(ngl::Vec3(0.0), ngl::Vec3(float(m_width), 0.0, float(m_height)));
}

void Maze::displayMaze(ngl::Camera *camera)
{
 /* ngl::Camera camera;

  camera.set(ngl::Vec3(11,60,20), ngl::Vec3(20,0,20), ngl::Vec3(0,1,0));
  camera.setShape(45.0f, float(720.0/576.0), 0.5f, 100.0f);*/

  m_maze.buildVAO();
  m_maze.drawVAO(camera);
}

/*void Model::partitionSpace(ngl::Vec3 minCorner, ngl::Vec3 maxCorner)
{
  for (int i=minCorner[0]; i<maxCorner[0]-6; i+=5)
  {

      std::vector<ngl::BBox> BBoxList;
      ngl::BBox gridSpace(i, i+5, 0.0, 10.0, i, i+5);

      for (int k=0; k<int(m_BBoxes.size()); k++)
      {
        if (collisionDetect(m_BBoxes[k], gridSpace))
        {
          //BBoxList.push_back(m_BBoxes[k]);
        }

      m_BBoxGrid[i*i]= BBoxList;
    }
  }

}*/




















