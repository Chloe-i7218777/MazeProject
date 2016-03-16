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
  Grid mazeGrid = test.generateGrowingTree(15,15,2);

  test.generate3DMaze(mazeGrid);

  bool quit=false;
  while(!quit)
  {
    SDL_Event event;
    window.pollEvent(event);
    switch(event.type)
    {
      case SDL_QUIT : quit=true; break;
      //case SDL_KEYDOWN : test.keyDownEvent(event.key); break;
      //case SDL_KEYUP : test.keyUpEvent(event.key; break;)
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

  ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  shader->createShaderProgram("diffuse");

  shader->attachShader("diffuseVertex", ngl::ShaderType::VERTEX);
  shader->attachShader("diffuseFragment", ngl::ShaderType::FRAGMENT);

  shader->loadShaderSource("diffuseVertex","shaders/DiffuseVertex.glsl");
  shader->loadShaderSource("diffuseFragment","shaders/DiffuseFragment.glsl");

  shader->compileShader("diffuseVertex");
  shader->compileShader("diffuseFragment");

  shader->attachShaderToProgram("diffuse", "diffuseVertex");
  shader->attachShaderToProgram("diffuse", "diffuseFragment");

  shader->linkProgramObject("diffuse");
  shader->use("diffuse");
  shader->setRegisteredUniform("colour",1.0f,0.0f,1.0f,1.0f);
  shader->setRegisteredUniform("lightPos",5.0f,11.0f,5.0f);
  shader->setRegisteredUniform("lightDiffuse",1.0f,1.0f,1.0f,1.0f);
}


