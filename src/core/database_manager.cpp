#include "database_manager.hpp"

#include <SDL3/SDL_log.h>

#include "utils/config.hpp"

Database_manager &Database_manager::get_instance() {
    static Database_manager instance;
    return instance;
}

void Database_manager::start_up() {
    if (!open_database(DATABASE_PATH)) {
        initialize_database(DATABASE_PATH);
    }
}

void Database_manager::shut_down() {
    close_database();
}

void Database_manager::initialize_database(const char *path) {
    const char *create_customers_table = "CREATE TABLE IF NOT EXISTS customers (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, street_name TEXT NOT NULL, house_number TEXT NOT NULL, city TEXT NOT NULL, zip_code TEXT NOT NULL, phone_number TEXT, email TEXT);";
    const char *create_invoices_table = "CREATE TABLE IF NOT EXISTS invoices (id INTEGER PRIMARY KEY AUTOINCREMENT, customer_id INTEGER NOT NULL, date TEXT NOT NULL, total REAL NOT NULL, FOREIGN KEY (customer_id) REFERENCES customers(id));";
    const char *create_invoice_items_table = "CREATE TABLE IF NOT EXISTS invoice_items (id INTEGER PRIMARY KEY AUTOINCREMENT, invoice_id INTEGER NOT NULL, description TEXT NOT NULL, quantity INTEGER NOT NULL, price REAL NOT NULL, FOREIGN KEY (invoice_id) REFERENCES invoices(id));";
    bool success = execute_query(create_customers_table) && execute_query(create_invoices_table) && execute_query(create_invoice_items_table);
    if (success) {
        SDL_Log("Database initialized: %s", path);
        open_database(path);
    } else {
        SDL_Log("Failed to initialize database: %s", path);
    }
}

bool Database_manager::open_database(const char *path) {
    if (sqlite3_open(path, &db) == SQLITE_OK) {
        SDL_Log("Database opened: %s", path);
        return true;
    }
    SDL_Log("Failed to open database: %s", sqlite3_errmsg(db));
    return false;
}

void Database_manager::close_database() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
        SDL_Log("Database closed");
    }
}

bool Database_manager::execute_query(const char *query) {
    char *error_message = nullptr;
    if (sqlite3_exec(db, query, nullptr, nullptr, &error_message) != SQLITE_OK) {
        SDL_Log("Failed to execute query: %s", error_message);
        sqlite3_free(error_message);
        return false;
    }
    return true;
}

std::vector<std::vector<const char *>> Database_manager::fetch_query(const char *query, int column_count) {
    std::vector<std::vector<const char *>> results;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<const char *> row;
            for (int i = 0; i < column_count; i++) {
                row.push_back(reinterpret_cast<const char *>(sqlite3_column_text(stmt, i)));
            }
            results.push_back(row);
        }
    } else {
        SDL_Log("Failed to execute query: %s", query);
    }
    sqlite3_finalize(stmt);
    return results;
}