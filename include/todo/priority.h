#pragma once
#include <iostream>
#include <cstdlib>

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
        enum Color {RED, GREEN, YELLOW, ORANGE, BLUE};

        Priority(std::string name, int pri_level, Color color, std::string description);
        explicit Priority(std::string data);

        std::string get_raw();

    private:
        const std::string delimiter = "<><><>";
        std::string name;
        int pri_level;
        Color color;
        std::string description;
        std::string raw;
};
