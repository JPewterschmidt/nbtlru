#include "benchmark_workers.h"
#include "sampling_lru.h"

#include <ranges>

namespace t = ::std::chrono;
namespace r = ::std::ranges;
namespace rv = ::std::ranges::views;

namespace nbtlru
{

static sampling_lru<key_t, value_t> cache(benchmark_cache_size(), 0.99);

::std::pair<t::nanoseconds, double> sampling_worker(::std::latch& l, size_t thrnum)
{
    cache.reset();
    l.arrive_and_wait();
    const auto tp = tic();
    [[maybe_unused]] size_t hits{}, misses{};

    for (auto k : gen<zipf, key_t>(benchmark_scale(), true) | rv::take(benchmark_scale() / thrnum))
    {
        benchmark_loop_body(cache, k, hits, misses);
    }
    auto time_elapsed = toc(tp);
    
    return { time_elapsed, (hits / double(hits + misses)) };
}

} // namespace nbtlru
