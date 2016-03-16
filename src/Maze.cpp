#include "Maze.h"
#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <ngl/ShaderLib.h>
#include <ngl/Transformation.h>

const static float ZOOM=0.1;

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

void Model::wheelEvent(const SDL_MouseWheelEvent &_event)
{/*
  if(_event.y>0)
  {
    m_modelPos.m_z+=ZOOM;
    this->drawVAO(m_camera);

  }
  else if (_event.y<0)
  {
    m_modelPos.m_z-=ZOOM;
    this->drawVAO(m_camera);
  }

  if(_event.x>0)
  {
    m_modelPos.m_z-=ZOOM;
    this->drawVAO(m_camera);
  }
  else if (_event.x<0)
  {
    m_modelPos.m_z+=ZOOM;
    this->drawVAO(m_camera);
  }*/
}


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

Model::Model()
{

}

void Model::buildVAO()
{
  m_vao.reset(ngl::VertexArrayObject::createVOA(GL_TRIANGLES));

  m_vao->bind();

  m_vao->setData((m_verts.size())*sizeof(ngl::Vec3),m_verts[0].m_x);

  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);

  m_vao->setNumIndices(m_verts.size());

  m_vao->setData((m_vertNormals.size())*sizeof(ngl::Vec3),m_vertNormals[0].m_x);

  m_vao->setVertexAttributePointer(2,3,GL_FLOAT,0,0);

  m_vao->setNumIndices(m_vertNormals.size());

  m_vao->unbind();
}

void Model::drawVAO(ngl::Camera *cam)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
  m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
  m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;

  loadMatricesToShader(cam);

  m_vao->bind();
  m_vao->draw();
  m_vao->unbind();
}

void Model::loadMatricesToShader(ngl::Camera *cam)
{
  ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  ngl::Mat4 MVP =m_mouseGlobalTX*cam->getVPMatrix();
  ngl::ShaderLib::instance()->setRegisteredUniform("MVP", MVP);
}

Maze::Maze()
{

}

void Maze::drawHorizontalWall(int width, int xCount, int zCount)
{
  //Back face
  m_verts.push_back(ngl::Vec3(xCount,0,zCount));
  m_verts.push_back(ngl::Vec3(xCount,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount));

  m_verts.push_back(ngl::Vec3(xCount,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount));

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,0,-1));
  }

  //Front face
  m_verts.push_back(ngl::Vec3(xCount,0,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount+1));

  m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,0,1));
  }

  //Left face
  m_verts.push_back(ngl::Vec3(xCount,0,zCount));
  m_verts.push_back(ngl::Vec3(xCount,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount,0,zCount+1));

  m_verts.push_back(ngl::Vec3(xCount,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount,0,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(-1,0,0));
  }

  //Right face
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount+1));

  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount+width,0,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(1,0,0));
  }

  //Top face
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount+1));

  m_verts.push_back(ngl::Vec3(xCount,1,zCount));
  m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
  m_verts.push_back(ngl::Vec3(xCount+width,1,zCount+1));

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,1,0));
  }

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

void Maze::display2DMaze(Grid plan)
{

}

Grid Maze::generateGrowingTree(int width, int height, int selMethod)
{
  Grid mazePlan(width,height);
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

void Maze::generate3DMaze(Grid plan)
{
  int width = plan.getWidth()*3+1;
  int height = plan.getHeight()*3+1;


  m_verts={//Top wall of the maze

           //Left face
           {0,0,1}, {0,1,0}, {0,0,0},
           {0,0,1}, {0,1,0}, {0,1,1},

           //Top face
           {0,1,0}, {0,1,1}, {float(width),1,0},
           {0,1,1}, {float(width),1,0}, {float(width),1,1},

           //Right face
           {float(width),1,0},{float(width),1,1}, {float(width),0,1},
           {float(width),1,0},{float(width),0,0}, {float(width),0,1},

           //Back face
           {0,0,0},{0,1,0}, {float(width),0,0},
           {0,1,0},{float(width),1,0}, {float(width),0,0},

           //Front face
           {0,0,1}, {0,1,1}, {float(width),0,1},
           {0,1,1}, {float(width),1,1}, {float(width),0,1},


           //Left wall of the maze

           //Left face
           {0,0,1}, {0,1,1}, {0,0,float(height)},
           {0,0,float(height)}, {0,1,0}, {0,1,float(height)},

           //Top face
           {0,1,1}, {1,1,1}, {0,1,float(height)},
           {0,1,float(height)}, {1,1,float(height)}, {1,1,1},

           //Front face
           {0,0,float(height)}, {1,0,float(height)}, {0,1,float(height)},
           {1,1,float(height)}, {1,0,float(height)}, {0,1,float(height)},

           //Right face
           {1,1,1}, {1,0,1}, {1,1,float(height)},
           {1,1,float(height)}, {1,0,1}, {1,0,float(height)},
          };

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(-1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,1,0));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,0,-1));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,0,1));
  }


  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(-1,0,0));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,1,0));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(0,0,1));
  }

  for (int i=0;i<6;i++)
  {
    m_vertNormals.push_back(ngl::Vec3(1,0,0));
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
        //Back face
        m_verts.push_back(ngl::Vec3(xCount,0,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount-2));

        m_verts.push_back(ngl::Vec3(xCount,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount-2));

        for (int i=0;i<6;i++)
        {
          m_vertNormals.push_back(ngl::Vec3(0,0,-1));
        }

        //Front face
        m_verts.push_back(ngl::Vec3(xCount,0,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount+1));

        m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_vertNormals.push_back(ngl::Vec3(0,0,1));
        }

        //Left face
        m_verts.push_back(ngl::Vec3(xCount,0,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount,0,zCount+1));

        m_verts.push_back(ngl::Vec3(xCount,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount,0,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_vertNormals.push_back(ngl::Vec3(-1,0,0));
        }

        //Right face
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount+1));

        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount+1,0,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_vertNormals.push_back(ngl::Vec3(1,0,0));
        }

        //Top face
        m_verts.push_back(ngl::Vec3(xCount,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));

        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount-2));
        m_verts.push_back(ngl::Vec3(xCount+1,1,zCount+1));
        m_verts.push_back(ngl::Vec3(xCount,1,zCount+1));

        for (int i=0;i<6;i++)
        {
          m_vertNormals.push_back(ngl::Vec3(0,1,0));
        }

        xCount++;
        flag=0;
      }
    }
  }
}

void Maze::display3DMaze()
{
  ngl::Camera camera;

  camera.set(ngl::Vec3(11,60,20), ngl::Vec3(20,0,20), ngl::Vec3(0,1,0));
  camera.setShape(45.0f, float(720.0/576.0), 0.5f, 100.0f);

  buildVAO();
  drawVAO(&camera);
}

Control::Control()
{

}

void Control::keyDownEvent(const SDL_KeyboardEvent &event)
{


  switch (event.keysym.sym)
  {
   /*case SDLK_ESCAPE : quit=true; break;
    case SDLK_w : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
    case SDLK_s : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;*/
  }
  /*switch(event.type)
      {
  case SDL_KEYDOWN :
    {
      switch (event.key.keysym.sym)
      {
        case SDLK_UP : camera.set(ngl::Vec3(10,10,30), ngl::Vec3(7,0,7), ngl::Vec3(0,1,0)); break;
        case SDLK_LEFT : camera.set(ngl::Vec3(10,20,30), ngl::Vec3(7,0,7), ngl::Vec3(0,1,0)); break;
        case SDLK_RIGHT : camera.set(ngl::Vec3(10,30,30), ngl::Vec3(7,0,7), ngl::Vec3(0,1,0)); break;
      }
    }
      }
 case SDL_KEYUP :
  {
    switch (event.key.keysym.sym)
    {
    case
    }
  }

}*/
}
