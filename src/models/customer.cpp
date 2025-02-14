#include "customer.hpp"

#include "core/database_manager.hpp"

Customer::Customer(int id, const std::string &name, const std::string &street_name, const std::string &house_number,
                   const std::string &city, const std::string &zip_code, const std::string &phone_number,
                   const std::string &email)
    : id(id), name(name), street_name(street_name), house_number(house_number), city(city), zip_code(zip_code),
      phone_number(phone_number), email(email) {}

bool Customer::save() {
    Database_manager &db = Database_manager::get_instance();
    std::string query;
    if (id == 0) {
        query =
            "INSERT INTO customers (name, street_name, house_number, city, zip_code, phone_number, email) VALUES ('" +
            name + "', '" + street_name + "', '" + house_number + "', '" + city + "', '" + zip_code + "', '" +
            phone_number + "', '" + email + "');";
    } else {
        query = "UPDATE customers SET name = '" + name + "', street_name = '" + street_name + "', house_number = '" +
                house_number + "', city = '" + city + "', zip_code = '" + zip_code + "', phone_number = '" +
                phone_number + "', email = '" + email + "' WHERE id = " + std::to_string(id) + ";";
    }
    return db.execute_query(query.c_str());
}

std::vector<Customer> Customer::load_all() {
    Database_manager &db = Database_manager::get_instance();
    std::string query =
        "SELECT id, name, street_name, house_number, city, zip_code, phone_number, email FROM customers;";
    auto results = db.fetch_query(query.c_str(), 8);

    std::vector<Customer> customers;
    for (const auto &row : results) {
        customers.emplace_back(std::stoi(row[0]), row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
    }
    return customers;
}

Customer Customer::find_by_id(int id) {
    Database_manager &db = Database_manager::get_instance();
    std::string query =
        "SELECT id, name, street_name, house_number, city, zip_code, phone_number, email FROM customers WHERE id = " +
        std::to_string(id) + " LIMIT 1;";
    auto results = db.fetch_query(query.c_str(), 8);

    if (!results.empty()) {
        const auto &row = results[0];
        return Customer(std::stoi(row[0]), row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
    }
    return Customer();
}
