#include "belphegor/log.hpp"

namespace gor {
auto initialize_logger() -> void {
    quill::BackendOptions backend_options;
    quill::Backend::start(backend_options);

    auto console_sink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>(
            LOGGER_NAME + "_console");

    auto logger = quill::Frontend::create_or_get_logger(LOGGER_NAME, std::move(console_sink));
    logger->set_log_level(quill::LogLevel::TraceL3);
}

auto logger() -> quill::Logger * {
    static std::once_flag initialized_quill;
    std::call_once(initialized_quill, initialize_logger);

    return quill::Frontend::get_logger(LOGGER_NAME);
}
} // namespace gor
