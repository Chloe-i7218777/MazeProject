#include <iostream>
#include "Maze.h"
#include <ngl/Camera.h>
#include <ngl/Transformation.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>

void initialiseGL();

int main()
{
  SDLOpenGL window("MAGICAL PLACE WHERE MAZES APPEAR (In construction)",0,0,1024,720);

  window.makeCurrent();
  initialiseGL();

  Maze test;
  Grid mazeGrid = test.generateGrowingTree(7,7,2);

  test.generate3DMaze(mazeGrid);

  bool quit=false;
  while(!quit)
  {
    SDL_Event event;
    window.pollEvent(event);
    switch(event.type)
    {
      case SDL_QUIT : quit=true; break;
      case SDL_KEYDOWN :
        {
          switch (event.key.keysym.sym)
          {
            case SDLK_ESCAPE : quit=true; break;
            case SDLK_w : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
            case SDLK_s : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
          }
        }
    }
    test.display3DMaze();
    window.swapWindow();
    SDL_Delay(10);
  }
}

void initialiseGL()
{
  ngl::NGLInit::instance();

  glClearColor(0.0,0.7,0.8,1.0);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);

  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  shader->use("nglColourShader");
  shader->setRegisteredUniform4f("Colour",0.0,0.3,0.0,1);
}


