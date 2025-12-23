#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Delivery {
    int id;
    string destination;
    string status;

public:
    Delivery(int i, string d) {
        id = i;
        destination = d;
        status = "Pending";
    }

    void display() {
        cout << "ID: " << id
             << " | Destination: " << destination
             << " | Status: " << status << endl;
    }

    void saveToFile() {
        ofstream file("deliveries.txt", ios::app);
        file << id << " " << destination << " " << status << endl;
        file.close();
    }
};

int main() {
    vector<Delivery> deliveries;
    int choice;

    do {
        cout << "\n== DELIVERY MANAGEMENT SYSTEM ==\n";
        cout << "1. Add Delivery\n";
        cout << "2. View Deliveries\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string dest;

            cout << "Enter Delivery ID: ";
            cin >> id;
            cout << "Enter Destination: ";
            cin >> dest;

            Delivery d(id, dest);
            deliveries.push_back(d);
            d.saveToFile();

            cout << "Delivery added successfully!\n";
        }
        else if (choice == 2) {
            if (deliveries.size() == 0) {
                cout << "No deliveries found.\n";
            } else {
                for (int i = 0; i < deliveries.size(); i++) {
                    deliveries[i].display();
                }
            }
        }

    } while (choice != 0);

    cout << "Program exited.\n";
    return 0;
}

