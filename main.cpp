
#include "ttl/colls/c_string.hpp"
#include "ttl/conv/convert.hpp"
#include "ttl/numbers.hpp"
#include "ttl/result.hpp"
#include "ttl/sys/io.hpp"
namespace {

enum class Errors : u8 { Overflow };

auto getValue(i32 number) -> Result<u32, Errors> {
    if (number >= 0) {
        return Result<u32, Errors>{10};
    }
    return Result<u32, Errors>{Errors::Overflow};
}
}  // namespace
extern "C" auto main() -> void {
    ttl::sys::putStrLn(0x01, "Hello from main!");
    auto res = getValue(10);
    if (res.hasValue()) {
        ttl::sys::putStrLn(0x01, "1");
    }
    res.value();

    auto res1 = getValue(-10);
    if (not res1.hasValue()) {
        ttl::sys::putStrLn(0x01, "2");
    }
    res1.error();
    res1.value();
}
