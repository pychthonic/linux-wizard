#ifndef WIZARD_H
#define WIZARD_H

#include <pqxx/pqxx>

class Wizard {
public:
    void printMainMenu() {
        std::cout << mainMenu;
    }
    int Wizard::postgresConnect() {

        std::cout << "Enter postgres username: ";
        std::cin >> postgresUser;
        std::cout << "Enter postgres password: ";
        std::cin >> postgresPassword;

        std::string connectionString = "postgresql://" + postgresUser + ":" +           postgresPassword + "@localhost/wizard";

        std::cout << "Connecting to postgres...\n";

        pqxx::connection c{connectionString};
        pqxx::work txn{c};
        
        if (c.is_open()) {
            std::cout << "Opened database successfully: " << c.dbname() << std::endl;
        } else {
            std::cout << "Couldn't open database :(" << std::endl;
            return 1;
        }
        
        
    }
    int Wizard::postgresSetupDB() {
        txn.exec("CREATE TABLE IF NOT EXISTS linux_wizard(id SERIAL PRIMARY KEY, command_description TEXT NOT NULL, command TEXT NOT NULL)");
        txn.commit();
    }
private:
    std::string mainMenu = "\n\t\tMENU\n\n1/Add commands to database\n2/Start game\n3/Quit\n";
    
    std::string postgresUser, postgresPassword, postgresDatabase;
    
};

#endif