#include <vector>
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
        print_items(&it.second.items);
    }
}


void Printer::print_header(Priority * p) {

    int title_placement = int (header_width/2 - (p->name.size()/2));

    std::string color_code_open = p->get_color_code(false);
    std::string color_code_close = p->get_color_code(true);

    for (auto x : boost::irange(0, header_width)) {
        print_color(color_code_open, "=", color_code_close);
    }
    std::cout << std::endl;
    for (auto x : boost::irange(0, int(header_width + 1 - p->name.size()))) {
        if (!x || x == header_width-p->name.size()) {
            print_color(color_code_open, "!", color_code_close);
        }
        else if (x == title_placement) {
            print_color(color_code_open, p->name, color_code_close);
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (auto x : boost::irange(0, header_width)) {
        print_color(color_code_open, "=", color_code_close);
    }
    std::cout << std::endl;
}


void Printer::print_items(std::vector<std::string> *v) {

    for (auto s : *v) {
        std::cout << " * ";
        int col_count = 3;
        std::vector<std::string> tokens = tokenize_item(s);
        for (auto c : tokens) {
            if (col_count + c.size() > header_width) {
                std::cout << std::endl << "   ";
                col_count = 3;
            }
            std::cout << c << " ";
            col_count += c.size() + 1;
        }
    }

}


void Printer::print_color(const std::string& open, std::string ch, const std::string& close) {

    std::cout << open << ch << close;
}


std::vector<std::string> Printer::tokenize_item(std::string i) {
    std::vector<std::string> tokens;
    std::string token = "";

    for (auto c : i) {
        if (c == ' '){
            tokens.emplace_back(token);
            token.clear();
            continue;
        }
        token += c;
    }
    return tokens;
}