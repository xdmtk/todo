#include <todo/config.h>
#include <todo/todolist.h>
#include <todo/printer.h>

int main(int argc, char **argv) {

    TodoList tl = TodoList(Config::check_config());
    if (argc < 2) {
        Printer p = Printer(&tl);
        p.print_default();
        exit(0);
    }


}
