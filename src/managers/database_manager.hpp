#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>

class Database_manager {
public:
    static Database_manager &get_instance();

    void start_up();
    void shut_down();

    void open_database(const std::string &path);
    void initialize_database();
    void close_database();

    bool execute_query(const std::string &query);
    std::vector<std::vector<std::string>> fetch_query(const std::string &query, int column_count);

private:
    sqlite3 *db = nullptr;
};