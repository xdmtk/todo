#pragma once
#include <iostream>
#include "priority.h"


class TodoList;
class Priority;
class Config;
class Printer {
    public:
        explicit Printer(TodoList * t, Config *c);
        void print_default();
        void print_help(bool invalid = false);
        void print_success(std::string msg);
        void print_error(std::string err);
        Priority::Color get_color_from_str(const std::string& color_arg);

    private:
        TodoList * target;
        Config * config;
        void print_header(Priority * p);
        void print_items(std::vector<std::string> * v);
        void set_win_size();
        void print_last_updated();
        void print_color(const std::string& open, std::string ch, const std::string& close);
        std::vector<std::string> tokenize_item(std::string i);

        int rows, columns, header_width;
};