cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(wase-ecs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

file(GLOB_RECURSE sources
    "src/*.h"
	"src/*.inl"
    "src/*.cpp"
)

add_library(wase-ecs ${sources})

target_include_directories(wase-ecs PUBLIC 
    ${PROJECT_SOURCE_DIR}/src
)

foreach(source IN LISTS sources)
    get_filename_component(source_path "${source}" PATH ABSOLUTE)

    file(RELATIVE_PATH
        item_path_rel
        ${PROJECT_SOURCE_DIR}
        ${source_path})

    source_group("${item_path_rel}" FILES "${source}")
endforeach()

# Tests
if(DEFINED enable_test)
  add_subdirectory(tests)
endif()