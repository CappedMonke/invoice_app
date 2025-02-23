#pragma once

#include <string>
#include <vector>

class Customer {
public:
    int id = 0;
    std::string name;
    std::string street_name;
    std::string house_number;
    std::string city;
    std::string zip_code;
    std::string phone_number;
    std::string email;

    Customer() = default;
    Customer(int id, const std::string &name, const std::string &street_name, const std::string &house_number, const std::string &city, const std::string &zip_code, const std::string &phone_number, const std::string &email);

    bool save();
    static std::vector<Customer> load_all();
    static Customer find_by_id(int id);
};
