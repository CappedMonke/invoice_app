#pragma once

#include "gui/containers.hpp"
#include "gui/panel.hpp"

Container *create_main_view() {
    Container *root = new Vertical_container;

    Horizontal_container *menu_bar = new Horizontal_container;
    menu_bar->min_size = {100, 100};
    menu_bar->expand_y = false;
    root->add_child(menu_bar);

    Panel *panel = new Panel;
    panel->min_size = {100, 100};
    panel->color = Color::purple_4;
    menu_bar->add_child(panel);

    Panel *panel_2 = new Panel;
    panel_2->min_size = {100, 100};
    panel_2->color = Color::blue_4;
    menu_bar->add_child(panel_2);

    Panel *panel_3 = new Panel;
    panel_3->min_size = {100, 100};
    panel_3->color = Color::orange_4;
    menu_bar->add_child(panel_3);

    Vertical_container *content = new Vertical_container;
    content->min_size = {100, 100};
    root->add_child(content);

    Panel *panel_4 = new Panel;
    panel_4->min_size = {100, 100};
    panel_4->color = Color::purple_4;
    content->add_child(panel_4);

    Panel *panel_5 = new Panel;
    panel_5->min_size = {100, 100};
    panel_5->color = Color::blue_4;
    content->add_child(panel_5);

    Panel *panel_6 = new Panel;
    panel_6->min_size = {100, 100};
    panel_6->color = Color::orange_4;
    content->add_child(panel_6);

    Horizontal_container *footer = new Horizontal_container;
    footer->min_size = {100, 100};
    menu_bar->expand_y = false;
    root->add_child(footer);

    Panel *panel_7 = new Panel;
    panel_7->min_size = {100, 100};
    panel_7->color = Color::purple_4;
    footer->add_child(panel_7);

    Panel *panel_8 = new Panel;
    panel_8->min_size = {100, 100};
    panel_8->color = Color::blue_4;
    footer->add_child(panel_8);

    Panel *panel_9 = new Panel;
    panel_9->min_size = {100, 100};
    panel_9->color = Color::orange_4;
    footer->add_child(panel_9);

    return root;
}