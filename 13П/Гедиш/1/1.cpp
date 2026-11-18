#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

std::string program_name = "Task Checker";
std::string ver="1.0";

std::vector<std::string> loadTasks(const std::string& filename) {
    std::vector<std::string> tasks;
    std::ifstream inFile(filename);
    std::string line;

    while(std::getline(inFile, line)) {
        if(!line.empty()) {
            tasks.push_back(line);
        }
    }

    return(tasks);
}

void saveTasks(const std::vector<std::string>& tasks, const std::string& filename) {
    std::ofstream outFile(filename);
    for (const auto& task : tasks) {
        outFile << task << "\n";
    }
}

int main() {
    const std::string filename = "tasks.txt";
    std::vector<std::string> tasks = loadTasks(filename);
    int choice = 0;

    while(true) {
        std::cout << program_name << "\n";
        std::cout << "Version: " << ver << "\n\n";
        std::cout << "Select a task: \n";
        std::cout << "1. Add a task\n";
        std::cout << "2. Output all tasks\n";
        std::cout << "0. Exit (default)\n\n";

        if (!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice.\n\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1: {
                std::cout << "Enter the task description\n";
                std::string newTask;
                std::getline(std::cin, newTask);

                if (!newTask.empty()) {
                    tasks.push_back(newTask);
                    saveTasks(tasks, filename);
                    std::cout << "Task saved.\n\n";
                }
                else { std::cout << "Task can't be empty!\n"; }
                break;
            }
            case 2: {
                if(tasks.empty()) {
                    std::cout << "No tasks scheduled.\n\n";
                } else {
                    std::cout << "Your tasks:\n";
                    for(size_t i = 0; i < tasks.size(); i++) {
                        std::cout << i + 1 << ". " << tasks[i] << "\n";
                    }
                }
                break;
            }
            case 0: {
                std::cout << "Have a good day.\n";
                return 0;
            }
            default: {
                std::cout << "Invalid input.\n";
                continue;
            }
        }
    }
}
