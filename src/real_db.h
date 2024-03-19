#ifndef REAL_DB_H
#define REAL_DB_H

#include <sqlite3.h>

void menu(sqlite3* db);

sqlite3* open_db();

void close_db(sqlite3* db);

void real_db_show(sqlite3* db);

void real_db_showall(sqlite3* db);

void real_db_add(sqlite3* db);

void real_db_remove(sqlite3* db);

void reverse_string(char* input_string);

#endif