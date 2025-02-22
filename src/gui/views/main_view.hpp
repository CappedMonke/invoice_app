#pragma once

#include "gui/containers.hpp"
#include "gui/panel.hpp"

Ui_element *create_menu_bar() {
    Ui_element *menu_bar = new Horizontal_container;
    menu_bar->expand_x = true;
    menu_bar->min_size.y = 24;

    return menu_bar;
}

Ui_element *create_content() {
    Ui_element *content = new Horizontal_container;
    content->expand_x = true;
    content->expand_y = true;

    return content;
}

Ui_element *create_footer() {
    Ui_element *footer = new Horizontal_container;
    footer->expand_x = true;
    footer->min_size.y = 24;

    return footer;
}

Ui_element *create_main_view() {
    Ui_element *root = new Vertical_container;
    root->expand_x = false;

    root->add_child(create_menu_bar());
    root->add_child(create_content());
    root->add_child(create_footer());

    return root;
}