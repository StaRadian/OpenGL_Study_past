cmake_minimum_required(VERSION 3.19)
project(Study)

set(CMAKE_CXX_STANDARD 20)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)  #Source file dir
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)  #Library file dir

if(WIN)
    set(GLFW glfw-3.3.4.bin.WIN32)
    set(GLEW glew-2.1.0)
elseif(UNIX)
    set(GLFW glfw)
    set(GLEW glew)
endif()

set(VENDOR vendor)
set(SOURCE_FILES
        ${SRC_DIR}/Application.cpp
        ${SRC_DIR}/Renderer.cpp
        ${SRC_DIR}/VertexBuffer.cpp
        ${SRC_DIR}/IndexBuffer.cpp
        ${SRC_DIR}/VertexArray.cpp
        ${SRC_DIR}/VertexBufferLayout.cpp
        ${SRC_DIR}/Shader.cpp
        ${SRC_DIR}/Texture.cpp

        ${SRC_DIR}/Renderer.h
        ${SRC_DIR}/VertexBuffer.h
        ${SRC_DIR}/IndexBuffer.h
        ${SRC_DIR}/VertexArray.h
        ${SRC_DIR}/VertexBufferLayout.h
        ${SRC_DIR}/Shader.h
        ${SRC_DIR}/Texture.h

        ${LIB_DIR}/${VENDOR}/stb_image/stb_image.cpp)

if(WIN)
    include_directories(
            ${LIB_DIR}/${GLFW}/include
            ${LIB_DIR}/${GLEW}/include
            ${LIB_DIR}/${VENDOR})
    link_directories(${LIB_DIR}/${GLFW}/lib-mingw ${LIB_DIR}/${GLEW}/lib/Release/Win32)
    add_compile_definitions(GLEW_STATIC)
    add_executable(Study ${SOURCE_FILES})
    target_link_libraries(Study glew32s glfw3 Opengl32 Gdi32 Shell32)

elseif(UNIX)
    include_directories(${LIB_DIR}/${GLFW}/include ${LIB_DIR}/${GLEW}/include ${LIB_DIR}/${VENDOR})
    add_executable(Study ${SOURCE_FILES})
    target_link_libraries(Study GL glfw GLEW)

endif()