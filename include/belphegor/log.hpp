#ifndef BELPHEGOR_LOG_HPP
#define BELPHEGOR_LOG_HPP

/* quill uses logging macros, so it's not very applicable to the c++
 * module system. To avoid having to do an import + several includes
 * to do much with the logging system, this single header is a compromise.
 */

#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/Logger.h"
#include "quill/LogMacros.h"
#include "quill/sinks/ConsoleSink.h"

namespace gor {
const std::string LOGGER_NAME = "belphegor";

auto initialize_logger() -> void;

auto logger() -> quill::Logger *;
} // namespace gor

#define GOR_TRACE_L3(...) LOG_TRACE_L3(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_TRACE_L2(...) LOG_TRACE_L2(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_TRACE_L1(...) LOG_TRACE_L3(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_DEBUG(...)    LOG_DEBUG(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_INFO(...)     LOG_INFO(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_WARNING(...)  LOG_WARNING(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_ERROR(...)    LOG_ERROR(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_CRITICAL(...) LOG_CRITICAL(gor::logger() __VA_OPT__(,) __VA_ARGS__)

#define GOR_VTRACE_L3(...) LOGV_TRACE_L3(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VTRACE_L2(...) LOGV_TRACE_L2(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VTRACE_L1(...) LOGV_TRACE_L3(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VDEBUG(...)    LOGV_DEBUG(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VINFO(...)     LOGV_INFO(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VWARNING(...)  LOGV_WARNING(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VERROR(...)    LOGV_ERROR(gor::logger() __VA_OPT__(,) __VA_ARGS__)
#define GOR_VCRITICAL(...) LOGV_CRITICAL(gor::logger() __VA_OPT__(,) __VA_ARGS__)

#endif//BELPHEGOR_LOG_HPP
