#include <todo/args.h>
#include <todo/config.h>
#include <todo/todolist.h>
#include <todo/printer.h>
#include <todo/caller.h>

int main(int argc, char **argv) {

    auto a = Arguments(argv, argc);
    auto tl = TodoList(Config::check_config());
    auto p = Printer(&tl);
    auto c = Caller(&a, &p, &tl);

    c.call_function();

}

