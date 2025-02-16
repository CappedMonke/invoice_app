#include "containers.hpp"

#include <algorithm>

void Container::update(float delta_time) {
    for (Ui_element *element : elements) {
        element->pos = pos;
        if (element->expand_x) {
            element->size.x = size.x;
        } else {
            element->size.x = element->min_size.x;
        }

        if (element->expand_y) {
            element->size.y = size.y;
        } else {
            element->size.y = element->min_size.y;
        }
    }

    Ui_element::update(delta_time);
}

// void Vertical_container::update(float delta_time) {
//     float total_proportion = 0.0;
//     for (Ui_element *element : elements) {
//         if (element->expand_y) {
//             total_proportion += element->proportion;
//         }
//     }

//     float final_proportion = 0.0;
//     std::vector<Ui_element *> dynamic_elements;
//     for (Ui_element *element : elements) {
//         // If min_size is bigger than proportional size
//         if (element->min_size.y > size.y * element->proportion / total_proportion) {
//             element->size.y = element->min_size.y;
//         } else {
//             final_proportion += element->proportion;
//             dynamic_elements.push_back(element);
//         }
//     }

//     for (Ui_element *element : dynamic_elements) {
//         element->size.y = size.y * element->proportion / final_proportion;
//     }

//     float current_y = pos.y;
//     for (Ui_element *element : elements) {
//         element->pos.x = pos.x;
//         element->size.x = size.x;
//         element->pos.y = current_y;
//         current_y += element->size.y;
//     }

//     Ui_element::update(delta_time);
// }

// void Horizontal_container::update(float delta_time) {
//     float total_proportion = 0.0;
//     for (Ui_element *element : elements) {
//         total_proportion += element->proportion;
//     }

//     float final_proportion = 0.0;
//     std::vector<Ui_element *> dynamic_elements;
//     for (Ui_element *element : elements) {
//         // If min_size is bigger than proportional size
//         if (element->min_size.x > size.x * element->proportion / total_proportion) {
//             element->size.x = element->min_size.x;
//         } else {
//             final_proportion += element->proportion;
//             dynamic_elements.push_back(element);
//         }
//     }

//     for (Ui_element *element : dynamic_elements) {
//         element->size.x = size.x * element->proportion / final_proportion;
//     }

//     float current_x = pos.x;
//     for (Ui_element *element : elements) {
//         element->pos.y = pos.y;
//         element->size.y = size.y;
//         element->pos.x = current_x;
//         current_x += element->size.x;
//     }

//     Ui_element::update(delta_time);
// }

void Vertical_container::update(float delta_time) {
}

void Horizontal_container::update(float delta_time) {
}
