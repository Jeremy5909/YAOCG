#include <iostream>
#include <string>
#include <sstream>
#include "Object.h"
#include "Room.h"
#include "Toggleable.h"

namespace Player {
    float health = 100;
    std::string name;
    Room* currentRoom;
}

void ProcessInput() {
    std::string input;

    std::cout << "> "; std::getline(std::cin, input);

    std::istringstream iss(input);

    std::string command;
    iss >> command; // Extract command from input stream

    if (command == "inspect" || command == "examine") {
        std::string targetName;
        iss >> targetName; // Extract target from input stream

        if (targetName.empty()) {
            std::cout << "Please specify what you want to inspect." << std::endl;
        } else {
            Object* targetObject = Player::currentRoom -> FindObjectByName(targetName);
            if (targetObject != nullptr) {
                std::cout << "You are inspecting '" << targetObject->getName() << "'" << std::endl;
            } else {
                std::cout << "There is no '" << targetName << "' in the room." << std::endl;
            }
        }
    } else if (command == "look" || command == "see" || command == "c") {
        std::vector<Object> roomObjects = Player::currentRoom->getObjects();

        std::cout << "You are in " << Player::currentRoom->getName() << std::endl;
        std::cout << "Objects in the room: " << std::endl;
        for (const auto& obj : roomObjects) {
            std::cout << "- " << obj.getName() << std::endl;
        }
    } else if (command == "help") {
        std::cout << "Your available commands are:\nlook/see/c\ninspect/examine\nuse\nhelp" << std::endl;
    } else if (command == "use") {
        std::string targetName;
        iss >> targetName;
        if (targetName.empty()) {
            std::cout << "Please specify what you want to inspect." << std::endl;
        } else {
            Object* targetObject = Player::currentRoom->FindObjectByName(targetName);
            if (targetObject != nullptr) {
                targetObject->Use();
            } else {
                std::cout << "There is no '" << targetName << "' in the room." << std::endl;
            }
        }
    }
    else {
        std::cout << "Invalid command. You can use 'help' to view a list of commands." << std::endl;
    }

    ProcessInput();
}

int main() {
    Player::currentRoom = new Room("LivingRoom");
    Player::currentRoom->AddObject(*(new Toggleable("Light")));

    std::cout << "You wake up. You don't know who or where you are but you have a sudden craving for brains." << std::endl
              << "You notice a nametag on your shirt that says: ";
    std::cin >> Player::name;

    ProcessInput();

    return 0;
}
