#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cassert>
#include <boost/algorithm/string/trim.hpp>
/**
 * This class will manage the data structure of elements in the todolist.
 * A TodoList will map out several Priority objects, with each priority object
 * containing:
 *
 *      Priority Name
 *      Priority Level [ 0, inf )
 *      Priority Color ( For terminal output )
 *      Todo strings
 *
 */

class Priority {
    public:
        enum Color {RED, GREEN, YELLOW, MAGENTA, BLUE};
        const std::string delimiter = "<><><>";
        const std::string begin_str = "><><><";
        int pri_level{};

        Priority(std::string name, int pri_level, Color color, std::vector<std::string> items);
        Priority(std::vector<std::string> data);
        Priority();

        std::string get_raw();
        std::string get_color_code(bool closing);

    private:
        friend class Printer;
        friend class TodoList;
    void parse_header(std::string header);
        void set_properties(std::string n, int l, Priority::Color c, std::vector<std::string> i,
                std::string r);
        std::string name;
        Color color;
        std::vector<std::string> items;
        std::string raw;
};
