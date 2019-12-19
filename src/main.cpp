#include <todo/args.h>
#include <todo/config.h>
#include <todo/todolist.h>
#include <todo/printer.h>
#include <todo/caller.h>

int main(int argc, char **argv) {

    // Collect and parse arguments
    auto a = Arguments(argv, argc);
    auto c = Config();

    // Parse TodoList data from config
    auto tl = TodoList(c.check_todo_data(), &c);

    // Setup Printer object to display TodoList data
    auto p = Printer(&tl, &c);

    // Setup Caller object to direct control flow based
    // on given arguments
    auto ca = Caller(&a, &p, &tl, &c);

    ca.call_function();
}

