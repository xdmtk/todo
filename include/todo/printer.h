#pragma once
#include <iostream>


class TodoList;
class Printer {
    public:
        explicit Printer(TodoList * t);
        void print_default();

private:
    TodoList * target;

};