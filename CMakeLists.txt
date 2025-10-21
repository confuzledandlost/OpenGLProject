cmake_minimum_required(VERSION 3.20)
project(OpenGLProject LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# FetchContent will download deps at configure time into the build tree
include(FetchContent)

# ---- GLFW --------------------------------------------------------------
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# ---- Our executable ----------------------------------------------------
file(GLOB SRC CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link libs (glfw only, we'll use system OpenGL)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# Find OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

# macOS: request a modern GL context and link frameworks via GLFW's props
if(APPLE)
  target_compile_definitions(${PROJECT_NAME} PRIVATE "GL_SILENCE_DEPRECATION")
endif()

# Windows: make console visible even in Release (handy for logs)
if(WIN32 AND MSVC)
  target_link_options(${PROJECT_NAME} PRIVATE /SUBSYSTEM:CONSOLE)
endif()

