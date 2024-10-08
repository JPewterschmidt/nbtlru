#ifndef NBTLRU_BENCHMARK_WORKERS_H
#define NBTLRU_BENCHMARK_WORKERS_H

#include <latch>
#include <chrono>
#include <cstddef>
#include <utility>

#include "distributions.h"
#include "benchmark_cases.h"
#include "keys_generator.h"

namespace nbtlru
{

::std::pair<::std::chrono::nanoseconds, double> naive_lru_profiling_worker(::std::latch&, size_t, bool);
::std::pair<::std::chrono::nanoseconds, double> fifo_hybrid_lru_profiling_worker(::std::latch&, size_t, bool);
::std::pair<::std::chrono::nanoseconds, double> sampling_lru_profiling_worker(::std::latch&, size_t, bool);

} // namespace nbtlru

#endif
