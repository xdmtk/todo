#pragma once
#include <todo/args.h>
#include <todo/printer.h>
#include <todo/todolist.h>
class Config;
class Caller {

    public:
        Caller(Arguments *a, Printer *p, TodoList *tl, Config *c);
        void call_function();

    private:
        Arguments * arguments;
        Printer * printer;
        TodoList * todolist;




};