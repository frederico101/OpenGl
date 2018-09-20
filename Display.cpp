#include "Display.h"
#include<GL/glew.h>
#include<iostream>
Display::Display( int width, int height, const std::string& title )
{
      SDL_Init(SDL_INIT_EVERYTHING);

 m_window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
 m_glcontext = SDL_GL_CreateContext(m_window);
     // this content must stay after the window render app
     SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 32);
     SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
      GLenum status = glewInit();

      if(status != GLEW_OK)
      {
            fprintf(stderr, "Error: %s\n", glewGetErrorString(status));
            //fprintf(stderr, "Error: %s\n", glewGetErrorString( )

      }
     is_closed=false;
}

void Display::update()
{
       SDL_GL_SwapWindow(m_window);
        SDL_Event e;

         while(SDL_PollEvent(&e))
         {
             if(e.type == SDL_QUIT)
              {
                   is_closed=true;
               }
         }

}

void Display::clear(float r, float g, float b, float a )
{
        glClearColor(r, g, b, a);
        glClear( GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed()
{
    return is_closed;
}

Display::~Display()
{
    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

/*if(1000/30 > (SDL_GetTicks() - start))
         SDL_Delay(1000/30 - (SDL_GetTicks()-start));


         */
