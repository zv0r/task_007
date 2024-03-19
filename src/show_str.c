#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    sqlite3* db = NULL;
    sqlite3_stmt* stmt = NULL;

    sqlite3_open("./data-samples/task007.db", &db);
    sqlite3_prepare_v2(db, "SELECT id, Name, Age, email FROM Students WHERE id = 7;", -1, &stmt, 0);
    sqlite3_step(stmt);
    printf("%d %s %d %s\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1),
           sqlite3_column_int(stmt, 2), sqlite3_column_text(stmt, 3));
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return EXIT_SUCCESS;
}