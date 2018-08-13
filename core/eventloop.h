
#pragma once

namespace phive
{
    namespace core
    {
        class EventLoop
        {
        public:
            explicit EventLoop();
            ~EventLoop();
        
        
        private:
            void listen();
            bool quit_;
        };
    }
}
