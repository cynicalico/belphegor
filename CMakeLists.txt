cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
project(belphegor
        VERSION 0.0.1
        DESCRIPTION "Simple graphics engine"
        HOMEPAGE_URL "https://github.com/cynicalico/belphegor"
        LANGUAGES C CXX)

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif (MSVC)

add_library(belphegor STATIC)

# cmake/file_lists.cmake contains lists of headers, sources, and modules
# these are populated with a python module called "cog", which allows for
# doing a true file glob so we don't have to list sources explicitly
find_package(Python3 REQUIRED COMPONENTS Interpreter)
execute_process(
        COMMAND ${Python3_EXECUTABLE} tools/cog_files.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE EXIT_CODE
        OUTPUT_QUIET
        ERROR_QUIET)
include(cmake/file_lists.cmake)
target_sources(belphegor PUBLIC FILE_SET HEADERS FILES ${belphegor_headers})
target_sources(belphegor PUBLIC ${belphegor_sources})
target_sources(belphegor PUBLIC FILE_SET CXX_MODULES FILES ${belphegor_modules})

target_include_directories(belphegor PUBLIC include)

target_compile_features(belphegor PUBLIC cxx_std_23)

target_compile_definitions(belphegor PUBLIC
        QUILL_COMPILE_ACTIVE_LOG_LEVEL=QUILL_COMPILE_ACTIVE_LOG_LEVEL_$<IF:$<CONFIG:Debug>,DEBUG,INFO>)
if (MSVC)
    target_compile_definitions(belphegor PRIVATE STRICT WIN32_LEAN_AND_MEAN NOMINMAX)
endif (MSVC)

if (MSVC)
    target_compile_options(belphegor PUBLIC /Zc:preprocessor /utf-8 /W4)
endif (MSVC)

include(cmake/get_cpm.cmake)
include(cmake/get_thirdparty.cmake)
target_link_libraries(belphegor PUBLIC belphegor_thirdparty)

add_library(belphegor::belphegor ALIAS belphegor)

add_subdirectory(example)
