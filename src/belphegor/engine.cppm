module;

#include "SDL3/SDL.h"
#include "belphegor/log.hpp"

export module gor.engine;

namespace gor {
export class engine {
public:
    engine();
    ~engine();
};

engine::engine() {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        auto version = SDL_GetVersion();
        GOR_DEBUG("Initialized SDL v{}.{}.{}",
            SDL_VERSIONNUM_MAJOR(version),
            SDL_VERSIONNUM_MINOR(version),
            SDL_VERSIONNUM_MICRO(version));
    } else {
        GOR_CRITICAL("Failed to initialize SDL: {}", SDL_GetError());
        std::exit(1);
    }
}

engine::~engine() {
    SDL_Quit();
    GOR_DEBUG("Quit SDL");
}
} // namespace gor
