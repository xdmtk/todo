#include <todo/caller.h>
#include <todo/config.h>

Caller::Caller(Arguments *a, Printer *p, TodoList *tl, Config *c) {
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
        case Arguments::REMOVE_PRIORITY:
            todolist->remove_priority_list(arguments, printer);
            printer->print_default();
            break;
        case Arguments::ADD_ITEM:
            todolist->add_item(arguments, printer);
            printer->print_default();
            break;
        case Arguments::REMOVE_ITEM:
            todolist->remove_item(arguments, printer);
            printer->print_default();
            break;
        case Arguments::MOVE_ITEM:
            todolist->move_item(arguments, printer);
            printer->print_default();
            break;

    }
}