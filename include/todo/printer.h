#pragma once
#include <iostream>


class TodoList;
class Priority;
class Printer {
    public:
        explicit Printer(TodoList * t);
        void print_default();
        void print_help(bool invalid = false);
        void print_error(std::string err);

    private:
        TodoList * target;
        void print_header(Priority * p);
        void print_items(std::vector<std::string> * v);
        void set_win_size();
        void print_color(const std::string& open, std::string ch, const std::string& close);
        std::vector<std::string> tokenize_item(std::string i);

        int rows, columns, header_width;


};