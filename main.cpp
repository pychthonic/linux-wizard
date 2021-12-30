/*
This is a small project that brings together a few different tools I've
been working with recently. I'm reading a book on C++, a book on Linux,
and am using postgres with C++ at work, so I decided to put the three
together: It's a quiz game that uses a postgres database to randomly
pick questions and answers. The questions are how to do things at the
Linux command line. The answers are the commands. 


*/

#include <iostream>
#include <pqxx/pqxx>
#include "wizard.h"

int main () {
    Wizard wizardClient;
    
    std::string sql_statement;
    unsigned choice;
    
    
    try {
        wizardClient.postgresConnect();
        wizardClient.postgresSetupDB();

        wizardClient.printMainMenu();
        while (std::cin >> choice) {
            if (choice == 1) {
                std::string newCommandDescription, newCommand;
                while (1) {
                    std::cout << "Enter command description (Example: 'List all files in current working directory'):\n";
                    std::cin >> newCommandDescription;
                    std::cout << "Enter command (Example: ls):\n";
                    std::cin >> newCommand;
                }
            } else if (choice == 2) {
                // Enter game code here..
            } else {
                break;
            }
            wizardClient.printMainMenu();

        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n";

}