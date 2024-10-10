module;

#include "fmt/base.h"

export module gor.engine;

namespace gor {
export auto say_hello() -> void {
    fmt::println("Hello, belphegor!");
}
} // namespace gor