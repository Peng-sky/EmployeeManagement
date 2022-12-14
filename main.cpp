#include <iostream>

#include "worker/workerManager.h"
#include "worker/worker.h"
#include "worker/employee.h"
#include "worker/manager.h"
#include "worker/Boss.h"

int main() {

    Worker *worker = NULL;
    worker = new Employee(1, "jack", 1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2, "??˹", 2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3, "wangwu", 3);
    worker->showInfo();
    delete worker;

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
                workerManager.addWorker();
                break;
            case 2:
                workerManager.showWorker();
                break;
            case 3:
                workerManager.delWorker();
                break;
            case 4:
                workerManager.modifyWorker();
                break;
            case 5:
                workerManager.findWorker();
                break;
            case 6:
                workerManager.sortWorkers();
                break;
            case 7:
                workerManager.clearFile();
                break;
            default:
                break;
        }
    }
    return 0;
}
