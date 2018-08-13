
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

        private:
            std::shared_ptr<SDL_Window> window_;
            std::shared_ptr<SDL_Renderer> renderer_;
            std::shared_ptr<SDL_Texture> texture_;
        };
    }
}
