#pragma once

#include <string>
#include <vector>

#include "customer.hpp"

class Invoice {
public:
    int id = 0;
    int customer_id = 0;
    std::string date;
    double total_amount = 0.0;

    Invoice() = default;
    Invoice(int id, int customer_id, const std::string &date, double total_amount);

    bool save();
    static std::vector<Invoice> load_all();
    static std::vector<Invoice> find_by_customer_id(int customer_id);
};