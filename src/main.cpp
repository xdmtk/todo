#include <todo/args.h>
#include <todo/config.h>
#include <todo/todolist.h>
#include <todo/printer.h>
#include <todo/caller.h>

int main(int argc, char **argv) {

    // Collect and parse arguments
    auto a = Arguments(argv, argc);

    // Parse TodoList data from config
    auto tl = TodoList(Config::check_config());

    // Setup Printer object to display TodoList data
    auto p = Printer(&tl);

    // Setup Caller object to direct control flow based
    // on given arguments
    auto c = Caller(&a, &p, &tl);

    c.call_function();
}

