module;

#include "fmt/base.h"

export module gor.engine;

export auto say_hello() -> void {
    fmt::println("Hello, belphegor!");
}