
#pragma once

namespace phive
{
    namespace core
    {
        class Screen
        {
        public:
            explicit Screen(
                const int width,
                const int height
            );

            ~Screen();
            
            void drawPolygon(
                const std::vector<SDL_Point>& vertexPositions
            );

        private:
            int initFlag_;
            std::shared_ptr<SDL_Window> window_;
            std::shared_ptr<SDL_Renderer> renderer_;
            std::shared_ptr<SDL_Texture> texture_;
        };
    }
}
