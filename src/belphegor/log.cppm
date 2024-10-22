module;

#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/Logger.h"
#include "quill/sinks/ConsoleSink.h"

export module gor.log;

namespace gor {
export const std::string LOGGER_NAME = "belphegor";

auto initialize_logger() {
    quill::BackendOptions backend_options;
    quill::Backend::start(backend_options);

    auto console_sink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>(
        LOGGER_NAME + "_console");

    auto logger = quill::Frontend::create_or_get_logger(LOGGER_NAME, std::move(console_sink));
    logger->set_log_level(quill::LogLevel::TraceL3);
}

export auto logger() -> quill::Logger * {
    static std::once_flag initialized_quill;
    std::call_once(initialized_quill, initialize_logger);

    return quill::Frontend::get_logger(LOGGER_NAME);
}
} // namespace gor
