#pragma once

#include "gui/button.hpp"
#include "gui/container.hpp"

Ui_element *create_main_view(float w, float h) {
    Container *view = new Vertical_container;
    view->size = {w, h};

    // Menu bar
    Container *menu_bar = new Horizontal_container;
    view->add_element(menu_bar);
    view->expand_x = false;
    view->min_size.y = 32;

    Button *new_invoice_button = new Button;
    menu_bar->add_element(new_invoice_button);

    Button *invoices_button = new Button;
    menu_bar->add_element(invoices_button);

    Button *customers_button = new Button;
    menu_bar->add_element(customers_button);

    Button *shortcuts_button = new Button;
    menu_bar->add_element(shortcuts_button);

    Button *settings_button = new Button;
    menu_bar->add_element(settings_button);

    // Content
    Container *content = new Container;
    view->add_element(content);
    content->proportion = 8;

    // Footer
    Container *footer = new Horizontal_container;
    view->add_element(footer);

    return view;
}