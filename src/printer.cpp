#include <todo/printer.h>
#include <todo/todolist.h>
#include <todo/priority.h>
#include <sys/ioctl.h>
#include <boost/range/irange.hpp>


Printer::Printer(TodoList *t) {
    this->target = t;
    set_win_size();
}


void Printer::set_win_size() {
    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    rows = w.ws_row ? w.ws_row : 100;
    columns = w.ws_col ? w.ws_col : 100;
    header_width = (columns * .5);
}


void Printer::print_default() {
    set_win_size();
    for (auto & it : target->priorities) {
        print_header(&it.second);
    }
}


void Printer::print_header(Priority * p) {

    int title_placement = int (header_width/2 - (p->name.size()/2));
    std::string color_code = p->get_color_code();

    for (auto x : boost::irange(0, header_width)) {
        print_color(color_code, "=");
    }
    std::cout << std::endl;
    for (auto x : boost::irange(0, int(header_width + 1 - p->name.size()))) {
        if (!x || x == header_width-p->name.size()) {
            print_color(color_code, "!");
        }
        else if (x == title_placement) {
            print_color(color_code, p->name);
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (auto x : boost::irange(0, header_width)) {
        print_color(color_code, "=");
    }
    std::cout << std::endl;



}

void Printer::print_color(const std::string& color_code, std::string ch) {
    std::cout << color_code << ch << color_code;
}
