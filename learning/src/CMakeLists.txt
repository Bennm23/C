add_subdirectory(structures)
add_subdirectory(myio)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

add_executable(main main.c)

target_link_libraries(main structures myio)