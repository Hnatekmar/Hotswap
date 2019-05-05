#include <iostream>
#include <boost/dll.hpp>
#include <boost/process.hpp>
#include "lib/Runnable.h"
#include <sys/inotify.h>

namespace dll = boost::dll;
namespace process = boost::process;
boost::shared_ptr<Runnable> load() {
    boost::filesystem::path make = process::search_path("make");
    process::system(make, "-C", "./lib/build");
    return dll::import<Runnable>(
        "lib/build/libtest.so",
        "plugin",
        dll::load_mode::append_decorations
    );
}
int main() {
    boost::filesystem::path inotifywait = process::search_path("inotifywait");
    while (true) {
        boost::shared_ptr<Runnable> runnable = load();
        runnable->run();
        process::system(inotifywait, "./lib");
    }
    return 0;
}