#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Patient {
public:
    int age;
    Patient(int a) : age(a) {}
};

class CompareAge {
public:
    bool operator()(Patient const& p1, Patient const& p2) {
        return p1.age < p2.age;
    }
};

class Hospital {
private:
    priority_queue<Patient, vector<Patient>, CompareAge> pq;

public:
    void insertPatient(int age) {
        pq.push(Patient(age));
        cout << "Patient with age " << age << " added to the queue." << endl;
    }

    void deletePatient() {
        if (!pq.empty()) {
            cout << "Patient with age " << pq.top().age << " treated and removed from the queue." << endl;
            pq.pop();
        } else {
            cout << "No patients in the queue." << endl;
        }
    }

    void displayPatients() {
        if (pq.empty()) {
            cout << "No patients in the queue." << endl;
            return;
        }

        priority_queue<Patient, vector<Patient>, CompareAge> temp = pq;
        cout << "Patients in the queue (by priority):" << endl;
        while (!temp.empty()) {
            cout << "Age: " << temp.top().age << endl;
            temp.pop();
        }
    }
};

int main() {
    Hospital hospital;
    int choice, age;

    while (true) {
        cout << "Enter your choice of the activity:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Input the age value to be added in the queue: ";
                cin >> age;
                hospital.insertPatient(age);
                break;
            case 2:
                hospital.deletePatient();
                break;
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

