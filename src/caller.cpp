#include <todo/caller.h>

Caller::Caller(Arguments *a, Printer *p, TodoList *tl) {
    arguments = a;
    printer = p;
    todolist = tl;
}

void Caller::call_function() {
    switch (arguments->mode) {
        case Arguments::DEFAULT:
            printer->print_default();
            break;
        case Arguments::HELP:
        case Arguments::INVALID:
            printer->print_help(arguments->mode == Arguments::INVALID);
            break;
        case Arguments::ADD_PRIORITY:
            todolist->add_priority_list(arguments, printer);
            printer->print_default();
            break;



    }
}