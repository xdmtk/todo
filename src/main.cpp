#include <todo/config.h>
#include <todo/todolist.h>
#include <todo/printer.h>

int main(int argc, char **argv) {

    TodoList tl = TodoList(Config::check_config());
    if (argc < 2) {

        // TODO: Something strange with Printer constructor happening.. investigate

    }


}
