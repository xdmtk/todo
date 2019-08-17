#include <todo/config.h>
#include <todo/todolist.h>

int main(int argc, char **argv) {

    TodoList tl = TodoList(Config::check_config());
    if (argc < 2) {

    }


}
