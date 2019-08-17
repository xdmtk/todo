#include <todo/printer.h>

Printer::Printer(TodoList *t) {
    this->target = t;
}

void Printer::print_default() {
    for (const auto & it : target->priorities) {
        std::cout << it.second.name << std::endl;
    }
}
