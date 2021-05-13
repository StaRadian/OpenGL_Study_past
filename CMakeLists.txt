cmake_minimum_required(VERSION 3.19)
project(Study)

set(CMAKE_CXX_STANDARD 20)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(GLFW glfw-3.3.4.bin.WIN32)
set(GLEW glew-2.1.0)

set(SOURCE_FILES ${SRC_DIR}/Application.cpp src/Renderer.h src/Renderer.cpp src/Renderer.h src/VertexBuffer.cpp src/VertexBuffer.h src/IndexBuffer.cpp src/IndexBuffer.h src/VertexArray.cpp src/VertexArray.h src/VertexBufferLayout.cpp src/VertexBufferLayout.h src/Shader.cpp src/Shader.h lib/vendor/stb_image/stb_image.cpp src/Texture.cpp src/Texture.h)

include_directories(${LIB_DIR}/${GLFW}/include ${LIB_DIR}/${GLEW}/include ${LIB_DIR}/vendor)

link_directories(${LIB_DIR}/${GLFW}/lib-mingw ${LIB_DIR}/${GLEW}/lib/Release/Win32)

add_compile_definitions(GLEW_STATIC)

add_executable(Study ${SOURCE_FILES})

target_link_libraries(Study glew32s glfw3 Opengl32 Gdi32 Shell32)