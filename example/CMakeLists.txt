add_executable(indev indev.cpp)
target_compile_features(indev PUBLIC cxx_std_23)
target_link_libraries(indev PRIVATE belphegor)
