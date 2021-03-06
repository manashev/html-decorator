#include "html_escaper.h"
#include <iostream>

HTMLEscaper::HTMLEscaper(IHTMLDecorator *inner) :
        wrapper(inner)
{}

std::string &HTMLEscaper::process(std::string &str)
{
    std::cout << "HTMLEscaper process" << std::endl;

    auto replace = [&](std::string from, std::string to) {
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
    };

    replace("&", "&amp");
    replace("\"", "&quot");
    replace("`", "&#x60");
    replace("<", "&lt");
    replace(">", "&gt");

    return wrapper->process(str);
}
