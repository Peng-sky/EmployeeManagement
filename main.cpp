#include <iostream>

#include "worker/workerManager.h"

int main() {


    WorkerManager workerManager;

    int choice = 0;
    while (true) {
        workerManager.showMenu();
        cout << " please intput " << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                workerManager.exitSystem();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                break;
        }
    }


    return 0;
}
