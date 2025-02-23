#pragma once

#include "gui/button.hpp"
#include "gui/containers.hpp"
#include "gui/panel.hpp"

Ui_element *create_menu_bar() {
    Horizontal_container *menu_bar = new Horizontal_container;
    menu_bar->expand_y = false;
    menu_bar->expand_x = false;
    menu_bar->min_size.y = 24;
    menu_bar->padding[3] = 8;
    menu_bar->spacing = 8;

    Button *new_invoice_button = new Button;
    menu_bar->add_child(new_invoice_button);
    new_invoice_button->min_size.x = 50;

    Button *customers_button = new Button;
    menu_bar->add_child(customers_button);
    customers_button->min_size.x = 50;

    Button *shortcuts_button = new Button;
    menu_bar->add_child(shortcuts_button);
    shortcuts_button->min_size.x = 50;

    Button *settings_button = new Button;
    menu_bar->add_child(settings_button);
    settings_button->min_size.x = 50;

    return menu_bar;
}

Ui_element *create_content() {
    Container *content = new Container;
    content->padding = {24, 24, 24, 24};

    Panel *panel = new Panel;
    content->add_child(panel);

    Panel *panel_2 = new Panel;
    panel_2->expand_x = false;
    panel_2->expand_y = false;
    panel_2->min_size.x = 500;
    panel_2->min_size.y = 500;
    panel_2->color = Color::blue_4;
    content->add_child(panel_2);

    return content;
}

Ui_element *create_footer() {
    Horizontal_container *footer = new Horizontal_container;
    footer->expand_y = false;
    footer->min_size.y = 24;

    return footer;
}

Ui_element *create_main_view() {
    Vertical_container *root = new Vertical_container;

    root->add_child(create_menu_bar());
    root->add_child(create_content());
    root->add_child(create_footer());

    return root;
}