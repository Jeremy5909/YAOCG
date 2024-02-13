#include <iostream>
#include <string>
#include <sstream>
#include "Object.h"
#include "Room.h"
#include "Toggleable.h"
#include "Chest.h"

namespace Player {
    float health = 100;
    std::string name;
    Room* currentRoom;
    std::vector<Item*> inventory;
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
                targetObject->Inspect();
            } else {
                std::cout << "There is no '" << targetName << "' in the room." << std::endl;
            }
        }
    } else if (command == "look" || command == "see" || command == "c") {
        std::vector<Object*> roomObjects = Player::currentRoom->getObjects();

        std::cout << "You are in " << Player::currentRoom->getName() << std::endl;
        std::cout << "Objects in the room: " << std::endl;
        for (const auto& obj : roomObjects) {
            std::cout << "- " << obj->getName() << std::endl;
        }
    } else if (command == "help") {
        std::cout << "Your available commands are:\nlook/see/c\ninspect/examine\nuse\nhelp" << std::endl;
    } else if (command == "use" || command == "open") {
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
    } else if (command == "take") {
        std::string targetObjectName;
        iss >> targetObjectName;

        Object* targetObject = Player::currentRoom->FindObjectByName(targetObjectName);
        if (targetObject != nullptr) {
            if (true /*TODO: if object is chest*/) {
                // They are trying to take from chest
                auto* targetChest = dynamic_cast<Chest*>(targetObject);

                std::string targetItemName;
                iss >> targetItemName;

                if (targetItemName == "all" || targetItemName == "everything") {
                    for (auto& targetItem : targetChest->getInventory()) {
                        targetChest->Remove(targetItem);
                        Player::inventory.push_back(targetItem);

                    }
                } else {
                    Item* targetItem = targetChest->FindItemByName(targetItemName);
                    targetChest->Remove(targetItem);
                    Player::inventory.push_back(targetItem);
                }
            } else {
                std::cout << "That does not have an inventory." << std::endl;
            }
        } else {
            std::cout << "There is no '" << targetObjectName << "' in the room." << std::endl;
        }
    } else if (command == "inventory" || command == "inv") {
        std::cout << "Inventory: " << std::endl;
        for (auto item : Player::inventory) {
            std::cout << "\t-" << item->getName() << std::endl;
        }
    } else {
        std::cout << "Invalid command. You can use 'help' to view a list of commands." << std::endl;
    }

    ProcessInput();
}

int main() {
    Player::currentRoom = new Room("LivingRoom");


    std::cout << "You wake up. You don't know who or where you are but you have a sudden craving for brains." << std::endl
              << "You notice a pName tag on your shirt that says: ";
    std::cin >> Player::name;

    // Ignore input     length max stream size                         up to \n
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto* StarterChest = new Chest("StarterChest");
    StarterChest->AddTo(new Item("Sword"));
    StarterChest->AddTo(new Item("Map"));
    StarterChest->AddTo(new Item("Brain"));

    Player::currentRoom->AddObject( StarterChest);

    ProcessInput();

    delete Player::currentRoom;

    return 0;
}
