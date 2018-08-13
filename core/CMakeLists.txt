file(GLOB SRCS "**.cpp")
file(GLOB HDRS "**.h")

include_directories(${SDL2_INCLUDE_DIR})

add_library(core ${SRCS} ${HDRS})
target_link_libraries(core SDL2main SDL2-static)
add_precompiled_header(core pch.h)
