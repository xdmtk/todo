#pragma once
#include <iostream>

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
        Priority(std::string name, int pri_level, Color color, std::string description);
        Priority(std::string data);

        enum Color {RED, GREEN, YELLOW, ORANGE, BLUE};
        std::string get_raw();

    private:
        std::string name;
        int pri_level;
        Color color;
        std::string description;
        std::string raw;

};
