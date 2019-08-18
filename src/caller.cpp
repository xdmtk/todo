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



    }
}