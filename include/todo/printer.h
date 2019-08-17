#pragma once
#include <todo/todolist.h>
#include <iostream>

class Printer {


    public:
        Printer(TodoList *t);
    private:
        TodoList * target;
        void print_default();

};