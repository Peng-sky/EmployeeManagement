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

            cout << "������� " << i + 1 << "����Ա�����" << endl;
            cin >> id;
            cout << "������� " << i + 1 << "����Ա������" << endl;
            cin >> name;
            cout << "ѡ���λ " << endl;
            cout << "1. Ա�� " << endl;
            cout << "2. ���� " << endl;
            cout << "3. �ϰ� " << endl;
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

        cout << "�ɹ���� " << addNum << "Ա��" << endl;
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
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}