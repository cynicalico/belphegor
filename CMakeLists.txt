cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
project(belphegor
        VERSION 0.0.1
        DESCRIPTION "Simple graphics engine"
        HOMEPAGE_URL "https://github.com/cynicalico/belphegor"
        LANGUAGES C CXX)

set(CMAKE_CXX_EXTENSIONS OFF)

add_library(belphegor STATIC)

target_sources(belphegor PUBLIC
        FILE_SET HEADERS FILES
        #[=[ [[[cog
        import cog, os
        for root, _, files in os.walk("include", topdown=False):
            for f in files:
                if not any(f.endswith(e) for e in [".h", ".hpp"]): continue
                cog.outl(os.path.join(root, f).replace('\\', '/'))
        ]]] ]=]
        include/belphegor/log.hpp
        #[=[ [[[end]]] ]=])

target_sources(belphegor PUBLIC
        FILE_SET CXX_MODULES FILES
        #[=[ [[[cog
        import cog, os
        for root, _, files in os.walk("src", topdown=False):
            for f in files:
                if not any(f.endswith(e) for e in [".cppm"]): continue
                cog.outl(os.path.join(root, f).replace('\\', '/'))
        ]]] ]=]
        src/belphegor/log.cppm
        src/belphegor/engine.cppm
        #[=[ [[[end]]] ]=])

target_compile_features(belphegor PUBLIC cxx_std_23)

target_include_directories(belphegor PUBLIC include)

target_compile_definitions(belphegor PUBLIC
        QUILL_COMPILE_ACTIVE_LOG_LEVEL=QUILL_COMPILE_ACTIVE_LOG_LEVEL_$<IF:$<CONFIG:Debug>,DEBUG,INFO>)

include(cmake/get_cpm.cmake)
include(cmake/get_thirdparty.cmake)
target_link_libraries(belphegor PUBLIC belphegor_thirdparty)

add_library(belphegor::belphegor ALIAS belphegor)

add_subdirectory(example)
