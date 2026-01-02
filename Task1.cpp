#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Task {
public:
    string name;
    bool done;

    Task(string n, bool d = false) {
        name = n;
        done = d;
    }
};

vector<Task> tasks;

void save() {
    ofstream file("tasks.txt");
    for (int i = 0; i < tasks.size(); i++) {
        file << tasks[i].name << " " << tasks[i].done << endl;
    }
    file.close();
}

void load() {
    ifstream file("tasks.txt");
    string name;
    bool done;

    while (file >> name >> done) {
        tasks.push_back(Task(name, done));
    }
    file.close();
}

void addTask() {
    string name;
    cout << "Enter task: ";
    cin >> name;

    tasks.push_back(Task(name));
    save();
}

void showTasks() {
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;
        if (tasks[i].done)
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}

void completeTask() {
    int n;
    showTasks();
    cout << "Enter task number: ";
    cin >> n;

    if (n > 0 && n <= tasks.size()) {
        tasks[n - 1].done = true;
        save();
    }
}

int main() {
    load();
    int choice;

    do {
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Complete Task";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) addTask();
        else if (choice == 2) showTasks();
        else if (choice == 3) completeTask();

    } while (choice != 4);

    return 0;
}
