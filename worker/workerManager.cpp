//
// Created by Peng on 2022-12-13.
//

#include "workerManager.h"


WorkerManager::WorkerManager() {
    this->number = 0;
    this->workers = NULL;
}

void WorkerManager::addWorker() {
    cout << "how many you want to add in" << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0) {
        int newSize = this->number + addNum;
        Worker **newspace = new Worker *[newSize];
        if (this->workers != NULL) {
            for (int i = 0; i < this->number; i++) {
                newspace[i] = this->workers[i];
            }
        }

        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << "个新员工编号" << endl;
            cin >> id;
            cout << "请输入第 " << i + 1 << "个新员工姓名" << endl;
            cin >> name;
            cout << "选择岗位 " << endl;
            cout << "1. 员工 " << endl;
            cout << "2. 经理 " << endl;
            cout << "3. 老板 " << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
            }
            newspace[this->number + i] = worker;
            delete worker;
        }
        delete[] this->workers;
        this->workers = newspace;
        this->number = newSize;

        cout << "成功添加 " << addNum << "员工" << endl;
    } else {
        cout << "num invalid" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->number; i++) {
        ofs << this->workers[i]->id << " "
            << this->workers[i]->name << " "
            << this->workers[i]->deptId << endl;
    }
    ofs.close();
}

WorkerManager::~WorkerManager() {
    if (this->workers != NULL) {
        delete[] this->workers;
    }
}

void WorkerManager::exitSystem() {
    cout << "exit success" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}