#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>
#include <iostream>
#include <string>

struct User {
    int id;
    std::string name;
    int age;
};

int main() {
    try {
        soci::session sql(soci::sqlite3, "test.db");

        // 创建表
        sql << "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER)";

        // 插入数据
        std::string name = "Alice";
        int age = 30;
        sql << "INSERT INTO users(name, age) VALUES(:name, :age)", soci::use(name), soci::use(age);

        // 查询数据
        soci::row row;
        sql << "SELECT id, name, age FROM users WHERE name = :name", soci::use(name), soci::into(row);

        std::cout << "User ID: " << row.get<int>(0) << ", Name: " << row.get<std::string>(1)
                  << ", Age: " << row.get<int>(2) << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
