#ifndef __Display__
#define __Display__
#include<string>
#include<SDL2/SDL.h>

class Display
{
    public:

        Display(  int width, int weight, const std::string& title);
        virtual ~Display();
        void clear(float r, float g, float b, float a);
void update();

bool IsClosed();



    private:
   //operator=(const Display& other){}
     SDL_Window* m_window;
     SDL_Renderer* m_render;

     SDL_GLContext m_glcontext;

        bool is_closed;


};
#endif // __Display__
