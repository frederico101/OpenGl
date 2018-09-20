#include<SDL2/SDL.h>
#include"Display.h"
int main()
{

    Display display(400, 400, "Hello World");

    while(!display.IsClosed())
    {

        display.clear(0.0f, 0.1f, 0.15f, 0.3f);
        display.update();

    }



    return 0;
}
