#pragma once

#include <string>
#include <vector>

class Invoice_item {
public:
    int id = 0;
    int invoice_id = 0;
    std::string date;
    std::string service;
    double price = 0.0;

    Invoice_item() = default;
    Invoice_item(int id, int invoice_id, const std::string &date, const std::string &service, double price);

    bool save();
    std::vector<Invoice_item> find_by_invoice_id(int invoice_id);
    bool delete_by_invoice_id(int invoice_id);
};