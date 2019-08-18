#include <todo/caller.h>

Caller::Caller(Arguments *a, Printer *p, TodoList *tl) {
    switch (a->mode) {
        case Arguments::DEFAULT:
            p->print_default();
            break;



    }



}