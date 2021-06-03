cmake_minimum_required(VERSION 3.19) #cmake verison
project(Study)  #project name

set(CMAKE_CXX_STANDARD 20) #C++ version 20

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)  #Source file dir
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)  #Library file dir
set(VENDOR ${LIB_DIR}/vendor) #Vendor file dir
set(TEST ${SRC_DIR}/tests) #Tests file dir

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) #set working directory

# set GLFW file name
if(WIN32)   #if Win
    set(GLFW glfw-3.3.4.bin.WIN32)
elseif(UNIX)    #if UNIX
    set(GLFW glfw)
endif()

# set GLEW file name
set(GLEW glew-2.1.0)

set(SOURCE_FILES
        ${SRC_DIR}/Application.cpp
        ${SRC_DIR}/Renderer.cpp
        ${SRC_DIR}/VertexBuffer.cpp
        ${SRC_DIR}/IndexBuffer.cpp
        ${SRC_DIR}/VertexArray.cpp
        ${SRC_DIR}/VertexBufferLayout.cpp
        ${SRC_DIR}/Shader.cpp
        ${SRC_DIR}/Texture.cpp

        ${VENDOR}/stb_image/stb_image.cpp

        ${VENDOR}/imgui/imgui.cpp
        ${VENDOR}/imgui/imgui_demo.cpp
        ${VENDOR}/imgui/imgui_draw.cpp
        ${VENDOR}/imgui/imgui_tables.cpp
        ${VENDOR}/imgui/imgui_widgets.cpp

        ${VENDOR}/imgui/imgui_impl_glfw.cpp
        ${VENDOR}/imgui/imgui_impl_opengl3.cpp

        ${TEST}/Test.cpp
        ${TEST}/Test.h
        ${TEST}/TestClearColor.cpp
        ${TEST}/TestClearColor.h)


include_directories(
        ${LIB_DIR}/${GLFW}/include
        ${LIB_DIR}/${GLEW}/include
        ${VENDOR}
        ${SRC_DIR})

if(WIN32)
    link_directories(
            ${LIB_DIR}/${GLFW}/lib-mingw
            ${LIB_DIR}/${GLEW}/lib/Release/Win32)
    add_compile_definitions(GLEW_STATIC)
    add_executable(Study ${SOURCE_FILES})
    target_link_libraries(Study glew32s glfw3 Opengl32 Gdi32 Shell32)

elseif(UNIX)
    add_executable(Study ${SOURCE_FILES})
    target_link_libraries(Study GL glfw GLEW)

endif()