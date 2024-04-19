#include <stdio.h>
#include <sqlite3.h>

// Function to initialize the SQLite database
int initializeDatabase(sqlite3 **db) {
    return sqlite3_open("fleet.db", db);
}

// Function to create the database schema
int createDatabaseSchema(sqlite3 *db) {
    char *createTableSQL =
        "CREATE TABLE IF NOT EXISTS trips ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "vehicle_id INT,"
        "distance FLOAT,"
        "trip_date DATE"
        ");"
        "CREATE TABLE IF NOT EXISTS fuel_consumption ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "vehicle_id INT,"
        "fuel_liters FLOAT,"
        "fuel_date DATE"
        ");"
        "CREATE TABLE IF NOT EXISTS maintenance ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "vehicle_id INT,"
        "description TEXT,"
        "maintenance_date DATE"
        ");";

    return sqlite3_exec(db, createTableSQL, 0, 0, 0);
}

// Function to insert a record into the database
int insertRecord(sqlite3 *db, const char *table, const char *values) {
    char sql[1000];
    snprintf(sql, sizeof(sql), "INSERT INTO %s VALUES(%s);", table, values);

    return sqlite3_exec(db, sql, 0, 0, 0);
}

int main() {
    sqlite3 *db;
    if (initializeDatabase(&db) != SQLITE_OK) {
        fprintf(stderr, "Unable to open database.\n");
        return 1;
    }

    if (createDatabaseSchema(db) != SQLITE_OK) {
        fprintf(stderr, "Unable to create database schema.\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("Fleet Management Information System\n");
        printf("1. Record Trip\n");
        printf("2. Record Fuel Consumption\n");
        printf("3. Record Maintenance\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int vehicleId;
                float distance;
                char tripDate[20];
                printf("Enter vehicle ID: ");
                scanf("%d", &vehicleId);
                printf("Enter distance: ");
                scanf("%f", &distance);
                printf("Enter trip date (YYYY-MM-DD): ");
                scanf("%s", tripDate);

                char values[1000];
                snprintf(values, sizeof(values), "%d,%.2f,'%s'", vehicleId, distance, tripDate);
                if (insertRecord(db, "trips", values) != SQLITE_OK) {
                    fprintf(stderr, "Failed to record trip.\n");
                } else {
                    printf("Trip recorded successfully.\n");
                }
                break;
            }
            case 2: {
                int vehicleId;
                float fuelLiters;
                char fuelDate[20];
                printf("Enter vehicle ID: ");
                scanf("%d", &vehicleId);
                printf("Enter fuel liters: ");
                scanf("%f", &fuelLiters);
                printf("Enter fuel date (YYYY-MM-DD): ");
                scanf("%s", fuelDate);

                char values[1000];
                snprintf(values, sizeof(values), "%d,%.2f,'%s'", vehicleId, fuelLiters, fuelDate);
                if (insertRecord(db, "fuel_consumption", values) != SQLITE_OK) {
                    fprintf(stderr, "Failed to record fuel consumption.\n");
                } else {
                    printf("Fuel consumption recorded successfully.\n");
                }
                break;
            }
            case 3: {
                int vehicleId;
                char description[100];
                char maintenanceDate[20];
                printf("Enter vehicle ID: ");
                scanf("%d", &vehicleId);
                printf("Enter maintenance description: ");
                scanf("%s", description);
                printf("Enter maintenance date (YYYY-MM-DD): ");
                scanf("%s", maintenanceDate);

                char values[1000];
                snprintf(values, sizeof(values), "%d,'%s','%s'", vehicleId, description, maintenanceDate);
                if (insertRecord(db, "maintenance", values) != SQLITE_OK) {
                    fprintf(stderr, "Failed to record maintenance.\n");
                } else {
                    printf("Maintenance recorded successfully.\n");
                }
                break;
            }
            case 4:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}