#include <iostream>
#include "Maze.h"
#include <ngl/Camera.h>
#include <ngl/Transformation.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <ngl/Texture.h>
#include <ngl/Material.h>

void initialiseGL();

int main()
{
  SDLOpenGL window("MAGICAL PLACE WHERE MAZES APPEAR (In construction)",0,0,1024,720);

  window.makeCurrent();
  initialiseGL();

  Maze test(5,5);
  Grid mazeGrid = test.generateGrowingTree(2);

  std::vector<ngl::Vec3> exitVerts = {//Front face
                                      {ngl::Vec3(1.75, 0.5, 1.1)}, {ngl::Vec3(2.25, 0.5, 1.1)}, {ngl::Vec3(1.75, 0.8, 1.1)},
                                      {ngl::Vec3(2.25, 0.5, 1.1)}, {ngl::Vec3(2.25, 0.8, 1.1)}, {ngl::Vec3(1.75, 0.8, 1.1)},

                                      //Top face
                                      {ngl::Vec3(1.75, 0.8, 1.1)}, {ngl::Vec3(2.25, 0.8, 1.1)}, {ngl::Vec3(1.75, 0.8, 1.0)},
                                      {ngl::Vec3(2.25, 0.8, 1.1)}, {ngl::Vec3(2.25, 0.8, 1.0)}, {ngl::Vec3(1.75, 0.8, 1.0)},

                                      //Right face
                                      {ngl::Vec3(2.25, 0.5, 1.0)}, {ngl::Vec3(2.25, 0.5, 1.1)}, {ngl::Vec3(2.25, 0.8, 1.1)},
                                      {ngl::Vec3(2.25, 0.5, 1.0)}, {ngl::Vec3(2.25, 0.8, 1.1)}, {ngl::Vec3(2.25, 0.8, 1.0)},

                                      //Left face
                                      {ngl::Vec3(1.75, 0.5, 1.0)}, {ngl::Vec3(1.75, 0.5, 1.1)}, {ngl::Vec3(1.75, 0.8, 1.1)},
                                      {ngl::Vec3(1.75, 0.5, 1.0)}, {ngl::Vec3(1.75, 0.8, 1.1)}, {ngl::Vec3(1.75, 0.8, 1.0)},

                                      //Bottom face
                                      {ngl::Vec3(1.75, 0.5, 1.1)}, {ngl::Vec3(2.25, 0.5, 1.1)}, {ngl::Vec3(1.75, 0.5, 1.0)},
                                      {ngl::Vec3(2.25, 0.5, 1.1)}, {ngl::Vec3(2.25, 0.5, 1.0)}, {ngl::Vec3(1.75, 0.5, 1.0)},
                                     };

  std::vector<ngl::Vec2> exitUVs = {{ngl::Vec2(1,0)}, {ngl::Vec2(0,0)}, {ngl::Vec2(1,1)}, {ngl::Vec2(0,0)}, {ngl::Vec2(0,1)}, {ngl::Vec2(1,1)}};

  for (int i=0; i<24; i++)
  {
    exitUVs.push_back(ngl::Vec2(0,0));
  }

  std::vector<ngl::Vec3> exitNormals;

  for (int i=0; i<6; i++)
  {
    exitNormals.push_back(ngl::Vec3(0,0,1));
  }
  for (int i=0; i<6; i++)
  {
    exitNormals.push_back(ngl::Vec3(0,1,0));
  }
  for (int i=0; i<6; i++)
  {
    exitNormals.push_back(ngl::Vec3(1,0,0));
  }
  for (int i=0; i<6; i++)
  {
    exitNormals.push_back(ngl::Vec3(-1,0,0));
  }
  for (int i=0; i<6; i++)
  {
    exitNormals.push_back(ngl::Vec3(0,-1,0));
  }

  std::vector<ngl::BBox> exitBBoxes = {ngl::BBox(1.75, 2.25, 0.5, 0.8, 1.0, 1.2)};

  std::string exitShader = "TextureShader";
  Model exit(exitVerts, exitNormals, exitUVs, exitBBoxes, exitShader);

  test.generateMaze(mazeGrid);

  //ngl::Camera camera;

  //camera.set(ngl::Vec3(test.Width()-2,0.5,test.Height()-2), ngl::Vec3(test.Width()-5.5,0.5,test.Height()-2), ngl::Vec3(0,1,0));
 // camera.setShape(30.0f, float(1024.0/720.0), 0.5f, 100.0f);

  Player player1(ngl::Vec3(test.Width()-2,0.5,test.Height()-2), ngl::Vec3(test.Width()-5.5,0.5,test.Height()-2), ngl::Vec3(0,1,0));

  for (int j=0;j<4;j++)
  {
    for (int i=0;i<4;i++){
      std::cout<<player1.m_cam.getProjectionMatrix().m_m[j][i]<<", ";
    }
    std::cout<<"\n";
  }
  std::cout<<"\n";

  Control gameControls;

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
        default : gameControls.keyDownEvent(&test.m_maze, event.key, &player1.m_cam); break;
        }
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    test.displayMaze(&player1.m_cam);
    exit.buildVAO();
    exit.drawVAO(&player1.m_cam);
    window.swapWindow();
    SDL_Delay(10);
  }
}

void initialiseGL()
{
  ngl::NGLInit::instance();

  glClearColor(0.0,0.9,1.0,1.0);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);

  ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  shader->createShaderProgram("TextureShader");

  shader->attachShader("TextureVertex",ngl::ShaderType::VERTEX);
  shader->attachShader("TextureFragment",ngl::ShaderType::FRAGMENT);
  shader->loadShaderSource("TextureVertex","shaders/TextureVertex.glsl");
  shader->loadShaderSource("TextureFragment","shaders/TextureFragment.glsl");

  shader->compileShader("TextureVertex");
  shader->compileShader("TextureFragment");
  shader->attachShaderToProgram("TextureShader","TextureVertex");
  shader->attachShaderToProgram("TextureShader","TextureFragment");

  shader->linkProgramObject("TextureShader");
  shader->use("TextureShader");

  ngl::Texture t("textures/exit.png");
  t.setTextureGL();

  ngl::ShaderLib *shader2 = ngl::ShaderLib::instance();
  shader2->createShaderProgram("diffuse");

  shader2->attachShader("diffuseVertex", ngl::ShaderType::VERTEX);
  shader2->attachShader("diffuseFragment", ngl::ShaderType::FRAGMENT);

  shader2->loadShaderSource("diffuseVertex","shaders/DiffuseVertex.glsl");
  shader2->loadShaderSource("diffuseFragment","shaders/DiffuseFragment.glsl");

  shader2->compileShader("diffuseVertex");
  shader2->compileShader("diffuseFragment");

  shader2->attachShaderToProgram("diffuse", "diffuseVertex");
  shader2->attachShaderToProgram("diffuse", "diffuseFragment");

  shader2->linkProgramObject("diffuse");
  shader2->use("diffuse");
  shader2->setRegisteredUniform("colour",0.3f,0.7f,1.0f,1.0f);
  shader2->setRegisteredUniform("lightPos",5.0f,11.0f,5.0f);
  shader2->setRegisteredUniform("lightDiffuse",1.0f,1.0f,1.0f,1.0f);

  /*ngl::ShaderLib *shader2 = ngl::ShaderLib::instance();
  shader2->createShaderProgram("diffuse2");

  shader2->attachShader("diffuseVertex", ngl::ShaderType::VERTEX);
  shader2->attachShader("diffuseFragment", ngl::ShaderType::FRAGMENT);

  shader2->loadShaderSource("diffuseVertex","shaders/DiffuseVertex.glsl");
  shader2->loadShaderSource("diffuseFragment","shaders/DiffuseFragment.glsl");

  shader2->compileShader("diffuseVertex");
  shader2->compileShader("diffuseFragment");

  shader2->attachShaderToProgram("diffuse2", "diffuseVertex");
  shader2->attachShaderToProgram("diffuse2", "diffuseFragment");

  shader2->linkProgramObject("diffuse2");
  shader2->use("diffuse2");
  shader2->setRegisteredUniform("colour",0.4f,0.0f,1.0f,1.0f);
  shader2->setRegisteredUniform("lightPos",5.0f,11.0f,5.0f);
  shader2->setRegisteredUniform("lightDiffuse",1.0f,1.0f,1.0f,1.0f);*/
}


