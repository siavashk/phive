#include "screen.h"

using namespace phive;
using namespace core;

namespace
{
    std::shared_ptr<SDL_Window> createWindow(
        const char* name,
        const int width,
        const int height
    ) {
        return std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE),
            [](SDL_Window* window){ SDL_DestroyWindow(window); });
    }

    std::shared_ptr<SDL_Renderer> createRenderer(
        std::shared_ptr<SDL_Window> windowPtr
    ) {
        return std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(windowPtr.get(), -1, SDL_RENDERER_PRESENTVSYNC),
            [](SDL_Renderer* renderer){ SDL_DestroyRenderer(renderer); }
        );
    }

    std::shared_ptr<SDL_Texture> createTexture(
        std::shared_ptr<SDL_Renderer> rendererPtr,
        const int width,
        const int height
    ) {
        return std::shared_ptr<SDL_Texture>(
            SDL_CreateTexture(rendererPtr.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height),
            [](SDL_Texture* texture){ SDL_DestroyTexture(texture); }
        );
    }
    
    bool operator!=(const SDL_Point& lhs, const SDL_Point& rhs)
    {
        return lhs.x != rhs.x || lhs.y != rhs.y;
    }
}

Screen::Screen(
    const int width,
    const int height
)
    : initFlag_(SDL_Init(SDL_INIT_VIDEO))
    , window_(createWindow("Screen", width, height))
    , renderer_(createRenderer(window_))
    , texture_(createTexture(renderer_, width, height))
{
}

Screen::~Screen()
{
}

void Screen::drawPolygon(
    const std::vector<SDL_Point> &vertexPositions
) {
    if (vertexPositions.empty())
        return;
    
    std::vector<SDL_Point> verticesToDraw(vertexPositions);
    
    if (verticesToDraw.front() != verticesToDraw.back())
        verticesToDraw.emplace_back(verticesToDraw.front());
    
    if (SDL_RenderDrawLines(renderer_.get(), verticesToDraw.data(), verticesToDraw.size()) != 0)
        std::cout << "SDL returned an error while trying to draw polygon. Error: " << SDL_GetError() << std::endl;
}
