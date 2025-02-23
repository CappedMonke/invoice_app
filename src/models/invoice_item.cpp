#include "invoice_item.hpp"

#include "managers/database_manager.hpp"

Invoice_item::Invoice_item(int id, int invoice_id, const std::string &date, const std::string &service, double price)
    : id(id), invoice_id(invoice_id), date(date), service(service), price(price) {}

bool Invoice_item::save() {
    Database_manager &db = Database_manager::get_instance();
    std::string query;
    if (id == 0) {
        query = "INSERT INTO invoice_items (invoice_id, date, service, price) VALUES (" + std::to_string(invoice_id) + ", '" + date + "', '" + service + "', " + std::to_string(price) + ");";
    } else {
        query = "UPDATE invoice_items SET invoice_id = " + std::to_string(invoice_id) + ", date = '" + date + "', service = '" + service + "', price = " + std::to_string(price) + " WHERE id = " + std::to_string(id) + ";";
    }
    return db.execute_query(query.c_str());
}

std::vector<Invoice_item> Invoice_item::find_by_invoice_id(int invoice_id) {
    Database_manager &db = Database_manager::get_instance();
    std::string query = "SELECT id, invoice_id, date, service, price FROM invoice_items WHERE invoice_id = " + std::to_string(invoice_id) + ";";
    auto results = db.fetch_query(query.c_str(), 5);

    std::vector<Invoice_item> invoice_items;
    for (const auto &row : results) {
        invoice_items.emplace_back(std::stoi(row[0]), std::stoi(row[1]), row[2], row[3], std::stod(row[4]));
    }
    return invoice_items;
}

bool Invoice_item::delete_by_invoice_id(int invoice_id) {
    Database_manager &db = Database_manager::get_instance();
    std::string query = "DELETE FROM invoice_items WHERE invoice_id = " + std::to_string(invoice_id) + ";";
    return db.execute_query(query.c_str());
}
