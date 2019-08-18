#pragma once
#include <iostream>


class TodoList;
class Priority;
class Printer {
    public:
        explicit Printer(TodoList * t);
        void print_default();

    private:
        TodoList * target;
        void print_header(Priority * p);
        void set_win_size();
        void print_color(const std::string& color_code, std::string ch);

        int rows, columns, header_width;


};