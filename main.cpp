
#include "ttl/conv/convert.hpp"
#include "ttl/io/output.hpp"
#include "ttl/numbers.hpp"
#include "ttl/sys/io.hpp"

extern "C" auto main() -> void {
    ttl::printLn("Hello, boss");
    ttl::Sarray<3, i32> arr = {1, 2, 3};

    for (i32 val : arr) {
        ttl::sys::putChar(0x01, ttl::conv::numberToChar(val));
    }
    ttl::printLn();

    u64 size = arr.size();
    ttl::sys::putChar(0x01, ttl::conv::numberToChar(size));

    i32 pid = ttl::sys::getpid();
}
