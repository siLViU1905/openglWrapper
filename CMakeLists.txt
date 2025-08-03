cmake_minimum_required(VERSION 3.31)
project(openglWrapper)

set(CMAKE_CXX_STANDARD 20)

set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")

find_package(OpenGL REQUIRED)

link_directories(${LIB_DIR})

add_executable(openglWrapper
        main.cpp
        include/GL/glad.cpp
        include/SGL/System/Window.cpp
        include/SGL/Logger/Logger.cpp
        include/SGL/Wrapper/Context.cpp
        include/SGL/System/Keyboard.cpp
        include/SGL/Wrapper/VertexArray.cpp
        include/SGL/Wrapper/Shader.cpp
        include/SGL/System/Event.cpp
        include/SGL/System/Mouse.cpp
)

if (WIN32)
    target_link_libraries(openglWrapper
            ${OPENGL_LIBRARIES}
            glfw3
    )
endif ()

