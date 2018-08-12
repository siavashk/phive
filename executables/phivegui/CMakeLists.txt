include_directories(${SDL2_INCLUDE_DIR})
add_executable(phivegui main.cpp)
target_link_libraries(phivegui SDL2main SDL2-static)
