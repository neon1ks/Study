#include <iostream>
#include <string>

#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

    for (int i = 0; i < argc; ++i) {
        std::cout << azColName[i] << " = ";
        std::cout << (argv[i] != nullptr ? argv[i] : "nullptr") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main()
{
    sqlite3 *db = nullptr;
    char *zErrMsg = nullptr;
    int rc{};
    //char *sql = nullptr;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return (0);
    }

    std::cout << "Opened database successfully\n";

    /* Create SQL statement */
    std::string sql = "CREATE TABLE words("
                      "id INTEGER PRIMARY KEY NOT NULL AUTOINCREMENT,"
                      "english TEXT NOT NULL,"
                      "russian TEXT NOT NULL,"
                      "comment TEXT,"
                      "repeat INTEGER );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }
    sqlite3_close(db);
    return 0;
}
