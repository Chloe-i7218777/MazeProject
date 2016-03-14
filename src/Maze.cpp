#include "Maze.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <ngl/ShaderLib.h>

//const static float ZOOM=0.1;

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

  /*ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  shader->createShaderProgram("colour");

  shader->attachShader("colourVertex", ngl::ShaderType::VERTEX);
  shader->attachShader("colourFragment", ngl::ShaderType::FRAGMENT);

  shader->loadShaderSource("colourVertex","shaders/ColourVertex.glsl");
  shader->loadShaderSource("colourFragment","shaders/ColourFragment.glsl");

  shader->compileShader("colourVertex");
  shader->compileShader("colourFragment");

  shader->attachShaderToProgram("colour", "colourVertex");
  shader->attachShaderToProgram("colour", "colourFragment");

  shader->linkProgramObject("colour");
  shader->use("colour");*/
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

void Maze::wheelEvent(const SDL_MouseWheelEvent &_event)
{/*
  if(_event.y>0)
  {
    m_modelPos.m_z+=ZOOM;
    //this->display3DMaze();

  }
  else if (_event.y<0)
  {
    m_modelPos.m_z-=ZOOM;
    //this->display3DMaze();
  }

  if(_event.x>0)
  {
    m_modelPos.m_z-=ZOOM;
    //this->display3DMaze();
  }
  else if (_event.x<0)
  {
    m_modelPos.m_z+=ZOOM;
   // this->display3DMaze();
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


Maze::Maze()
{

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

  m_verts.push_back(ngl::Vec3(0,0,1));
  m_verts.push_back(ngl::Vec3(0,1,0));
  m_verts.push_back(ngl::Vec3(0,0,0));

  m_verts.push_back(ngl::Vec3(0,0,1));
  m_verts.push_back(ngl::Vec3(0,1,0));
  m_verts.push_back(ngl::Vec3(0,1,1));

  m_verts.push_back(ngl::Vec3(0,1,0));
  m_verts.push_back(ngl::Vec3(0,1,1));
  m_verts.push_back(ngl::Vec3(width,1,0));

  m_verts.push_back(ngl::Vec3(0,1,1));
  m_verts.push_back(ngl::Vec3(width,1,0));
  m_verts.push_back(ngl::Vec3(width,1,1));


}

void Maze::display3DMaze()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
  m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
  m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;
  /*

  ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  ngl::Mat4 MVP =view*project;
  ngl::ShaderLib::instance()->setRegisteredUniform("MVP", MVP);*/

  m_vao.reset(ngl::VertexArrayObject::createVOA(GL_TRIANGLES));

  m_vao->bind();

  m_vao->setData((m_verts.size()-1)*sizeof(ngl::Vec3),m_verts[0].m_x);

  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);

  m_vao->setNumIndices(12);

  m_vao->draw();

  m_vao->unbind();

}