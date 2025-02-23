#include "invoice.hpp"

#include "managers/database_manager.hpp"

Invoice::Invoice(int id, int customer_id, const std::string &date, double total_amount)
    : id(id), customer_id(customer_id), date(date), total_amount(total_amount) {}

bool Invoice::save() {
    Database_manager &db = Database_manager::get_instance();
    std::string query;
    if (id == 0) {
        query = "INSERT INTO invoices (customer_id, date, total_amount) VALUES ('" + std::to_string(customer_id) + ", '" + date + "', " + std::to_string(total_amount) + ");";
    } else {
        query = "UPDATE invoices SET customer_id = " + std::to_string(customer_id) + ", date = '" + date + "', total_amount = " + std::to_string(total_amount) + " WHERE id = " + std::to_string(id) + ";";
    }
    return db.execute_query(query.c_str());
}

std::vector<Invoice> Invoice::load_all() {
    Database_manager &db = Database_manager::get_instance();
    std::string query = "SELECT id, customer_id, date, total_amount FROM invoices;";
    auto results = db.fetch_query(query.c_str(), 4);

    std::vector<Invoice> invoices;
    for (const auto &row : results) {
        invoices.emplace_back(std::stoi(row[0]), std::stoi(row[1]), row[2], std::stod(row[3]));
    }
    return invoices;
}

std::vector<Invoice> Invoice::find_by_customer_id(int customer_id) {
    Database_manager &db = Database_manager::get_instance();
    std::string query =
        "SELECT id, customer_id, date, total_amount FROM invoices WHERE customer_id = " + std::to_string(customer_id) + ";";
    auto results = db.fetch_query(query.c_str(), 4);

    std::vector<Invoice> invoices;
    for (const auto &row : results) {
        invoices.emplace_back(std::stoi(row[0]), std::stoi(row[1]), row[2], std::stod(row[3]));
    }
    return invoices;
}