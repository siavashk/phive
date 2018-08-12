file(GLOB targets "**/CMakeLists.txt")

# for each sub-folder that contains a CMakeLists.txt file, add it as a sub-project
foreach(target ${targets})
    get_filename_component(target ${target} DIRECTORY)
    get_filename_component(target ${target} NAME)
    add_subdirectory(${target})
endforeach()
