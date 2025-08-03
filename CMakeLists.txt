cmake_minimum_required(VERSION 3.10)
project(university-db)

set(SRC
	../src/Database.cpp
	../src/FileUtils.cpp
    ../src/Student.cpp
    ../src/StudentUtils.cpp
    ../src/Tests.cpp)

set(FLAGS -Wall -Wextra -Werror -Wpedantic -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME}-lib PRIVATE cxx_std_17)

add_executable(${PROJECT_NAME} ../src/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)