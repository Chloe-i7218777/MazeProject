#include <iostream>
#include "Maze.h"
#include <ngl/Camera.h>
#include <ngl/Transformation.h>
#include "Shader.h"
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>

void initialiseGL();

int main(int argc, char *argv[])
{
  std::cout << "hello" << std::endl;


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
  //ngl::Camera cam;

  ngl::NGLInit::instance();

  glClearColor(0.0,0.7,0.8,1.0);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);

  // Now we will create a basic Camera from the graphics library
  // This is a static camera so it only needs to be set once
  // First create Values for the camera position
 // ngl::Vec3 from(0,5,6);
  //ngl::Vec3 to(0,0,0);
  //ngl::Vec3 up(0,1,0);

  //cam.set(from,to,up);
  // set the shape using FOV 45 Aspect Ratio based on Width and Height
  // The final two are near and far clipping planes of 0.5 and 10
  //cam.setShape(45,(float)720.0/576.0,0.001,150);

  Shader color("shaders/ColourVertex.glsl",
               "shaders/ColourFragment.glsl");
  //cam.update();
}


