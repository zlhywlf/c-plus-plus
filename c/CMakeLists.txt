project(c)
set(CMAKE_C_STANDARD 99)
add_executable(${PROJECT_NAME} main.c src/hello.c include/hello.h include/JsonUtil.h)
include_directories(include)
aux_source_directory(src DIR_SRC)