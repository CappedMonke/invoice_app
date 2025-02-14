#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>

class Database_manager {
public:
    static Database_manager &get_instance();

    void start_up();
    void shut_down();

    void initialize_database(const char *path);
    bool open_database(const char *path);
    void close_database();
    bool execute_query(const char *query);
    std::vector<std::vector<const char *>> fetch_query(const char *query, int column_count);

private:
    sqlite3 *db = nullptr;
};