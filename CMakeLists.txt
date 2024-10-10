cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
project(belphegor
        VERSION 0.0.1
        DESCRIPTION "Simple graphics engine"
        HOMEPAGE_URL "https://github.com/cynicalico/belphegor"
        LANGUAGES C CXX)

add_library(belphegor STATIC)

target_sources(belphegor PUBLIC
        FILE_SET CXX_MODULES FILES
        src/belphegor/engine.cppm
)

target_compile_features(belphegor PUBLIC cxx_std_23)

include(cmake/get_cpm.cmake)
include(cmake/get_thirdparty.cmake)
target_link_libraries(belphegor PUBLIC belphegor_thirdparty)

add_subdirectory(example)
