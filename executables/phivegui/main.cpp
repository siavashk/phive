#include <screen.h>
#include <eventloop.h>

using namespace phive;
using namespace core;

int main(int argc, char* argv[])
{
    Screen screen(640, 480);
    
    std::vector<SDL_Point> triangle{ {0, 240}, {320, 0}, {640, 240}, {0, 240} };
    screen.drawPolygon(triangle);
    
    EventLoop eventLoop;
    
    return EXIT_SUCCESS;
}
