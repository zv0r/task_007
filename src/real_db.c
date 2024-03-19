#define _POSIX_C_SOURCE 200809L

#include "real_db.h"

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    sqlite3* db = open_db();

    while (1) {
        menu(db);
    }
    close_db(db);
    return EXIT_SUCCESS;
}

void menu(sqlite3* db) {
    char* menu_choice;
    scanf("%ms", &menu_choice);
    if (strcmp(menu_choice, "SHOW") == 0) {
        real_db_show(db);
    } else if (strcmp(menu_choice, "SHOWALL") == 0) {
        real_db_showall(db);
    } else if (strcmp(menu_choice, "ADD") == 0) {
        real_db_add(db);
    } else if (strcmp(menu_choice, "REMOVE") == 0) {
        real_db_remove(db);
    } else if (strcmp(menu_choice, "EXIT") == 0) {
        free(menu_choice);
        close_db(db);
        exit(EXIT_SUCCESS);
    } else {
        fprintf(stderr, "WRONG MENU. TYPE SHOW, SHOWALL, ADD, REMOVE OR EXIT\n");
    }
    free(menu_choice);
}

sqlite3* open_db() {
    sqlite3* tmp_db = NULL;
    if (sqlite3_open("./data-samples/task007.db", &tmp_db) != SQLITE_OK) {
        fprintf(stderr, "CAN'T OPEN DB FILE. EXIT\n");
        exit(EXIT_FAILURE);
    }
    return tmp_db;
}

void close_db(sqlite3* db) { sqlite3_close(db); }

void real_db_show(sqlite3* db) {
    int record_id;
    sqlite3_stmt* query = NULL;

    scanf("%d", &record_id);

    int rc =
        sqlite3_prepare_v2(db, "SELECT id, Name, Age, email FROM Students WHERE id = ?1;", -1, &query, 0);
    sqlite3_bind_int(query, 1, record_id);
    if (rc == SQLITE_OK) {
        rc = sqlite3_step(query);
        if (rc == SQLITE_ROW) {
            printf("%d %s %d %s\n", sqlite3_column_int(query, 0), sqlite3_column_text(query, 1),
                   sqlite3_column_int(query, 2), sqlite3_column_text(query, 3));
        } else {
            printf("NO DATA\n");
        }
    }

    sqlite3_finalize(query);
}

void real_db_showall(sqlite3* db) {
    sqlite3_stmt* query = NULL;

    int rc =
        sqlite3_prepare_v2(db, "SELECT id, Name, Age, email FROM Students ORDER BY id ASC;", -1, &query, 0);
    if (rc == SQLITE_OK) {
        while ((rc = sqlite3_step(query)) == SQLITE_ROW) {
            printf("%d %s %d %s\n", sqlite3_column_int(query, 0), sqlite3_column_text(query, 1),
                   sqlite3_column_int(query, 2), sqlite3_column_text(query, 3));
        }
    }

    sqlite3_finalize(query);
}

void real_db_remove(sqlite3* db) {
    int record_id;
    sqlite3_stmt* query = NULL;

    scanf("%d", &record_id);

    sqlite3_prepare_v2(db, "DELETE FROM Students WHERE id = ?1;", -1, &query, 0);
    sqlite3_bind_int(query, 1, record_id);
    sqlite3_step(query);

    sqlite3_finalize(query);
}

void real_db_add(sqlite3* db) {
    getchar();
    char* input_string = NULL;
    char* email = NULL;
    char* age_string = NULL;
    int age = 0;
    size_t input_string_length = 0;
    sqlite3_stmt* query = NULL;

    getline(&input_string, &input_string_length, stdin);
    reverse_string(input_string);
    sscanf(input_string, "%ms", &email);
    reverse_string(email);
    sscanf(input_string + strlen(email) + 1, "%ms", &age_string);
    reverse_string(age_string);
    age = atoi(age_string);
    reverse_string(input_string);
    input_string[strlen(input_string) - strlen(email) - strlen(age_string) - 3] = 0;

    sqlite3_prepare_v2(db, "INSERT INTO Students (Name, Age, email) VALUES (?1, ?2, ?3);", -1, &query, 0);
    sqlite3_bind_text(query, 1, input_string, -1, SQLITE_STATIC);
    sqlite3_bind_int(query, 2, age);
    sqlite3_bind_text(query, 3, email, -1, SQLITE_STATIC);
    sqlite3_step(query);

    sqlite3_finalize(query);
    free(email);
    free(age_string);
    free(input_string);
}

void reverse_string(char* input_string) {
    int input_string_length = strlen(input_string);
    for (int i = 0; input_string_length > 1 && i < input_string_length / 2; i++) {
        char tmp = input_string[i];
        input_string[i] = input_string[input_string_length - 1 - i];
        input_string[input_string_length - 1 - i] = tmp;
    }
}