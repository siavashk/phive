file(GLOB SRCS "**.cpp")
file(GLOB HDRS "**.h")

include_directories(${CORE_DIR} ${SDL2_INCLUDE_DIR})
add_executable(phivegui ${SRCS} ${HDRS})
target_link_libraries(phivegui core)
add_precompiled_header(phivegui pch.h)
