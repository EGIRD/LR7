cmake_minimum_required(VERSION 3.28.3)
project(LR7)

set(CMAKE_CXX_STANDARD 20)

add_library(Task1 STATIC Task_1.cpp)
add_library(Task2 STATIC Task_2.cpp)
add_library(Task3 STATIC Task_3.cpp)
add_library(Task4 STATIC Task_4.cpp)
add_library(Task5 STATIC Task_5.cpp)

add_executable(main main.cpp)
target_link_libraries(main Task1 Task2 Task3 Task4 Task5)

add_executable(main_address main.cpp)
target_compile_options(main_address PRIVATE -fsanitize=address)
target_link_libraries(main_address PRIVATE Task1 Task2 Task3 Task4 Task5 -fsanitize=address)

add_executable(main_leak main.cpp)
target_compile_options(main_leak PRIVATE -fsanitize=leak)
target_link_libraries(main_leak PRIVATE Task1 Task2 Task3 Task4 Task5  -fsanitize=leak)

#add_executable(main_undefined main.cpp)
#target_compile_options(main_undefined PRIVATE -fsanitize=undefined)
#target_link_libraries(main_undefined PRIVATE Task1 Task2 Task3 -fsanitize=undefined)

#cmake --build . --target main_address
#./main_address

#add_executable(LR7 main.cpp
#        Task_1.cpp
#        Task_1.h
#        Task_2.cpp
#        Task_2.h
#        Task_3.cpp
#        Task_3.h
#        Task_4.cpp
#        Task_4.h
#        Task_5.cpp
#        Task_5.h)
