file(GLOB _targets "**/CMakeLists.txt")

# for each sub-folder that contains a CMakeLists.txt file, add it as a sub-project
foreach(_target ${_targets})
    get_filename_component(_target ${_target} DIRECTORY)
    get_filename_component(_target ${_target} NAME)
    add_subdirectory(${_target})
endforeach()
