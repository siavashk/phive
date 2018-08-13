include_directories(${CORE_DIR} ${SDL2_INCLUDE_DIR})
add_executable(phivegui main.cpp)
target_link_libraries(phivegui core)
add_precompiled_header(phivegui pch.h)
