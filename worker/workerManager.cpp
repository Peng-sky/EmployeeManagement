//
// Created by Peng on 2022-12-13.
//

#include "workerManager.h"


WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open()) {
        cout << "�ļ�������" << endl;
        this->number = 0;
        this->emptyFile = true;
        this->workers = NULL;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "file is null" << endl;
        this->number = 0;
        this->emptyFile = true;
        this->workers = NULL;
        ifs.close();
        return;
    }

    int num = this->getWorkerNumbers();
    cout << "ְ��������" << num << endl;
    this->number = num;
    this->workers = new Worker *[this->number];
    initWorker();
    for (int i = 0; i < num; i++) {
        cout << "ְ���ţ� " << this->workers[i]->id
             << " ְ�������� " << this->workers[i]->name
             << " ���ű�ţ� " << this->workers[i]->deptId << endl;
    }
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
            //�� �� *worker ��ָ���newspace[] �ĵ� i ��Ԫ��
            newspace[this->number + i] = worker;
        }
        //ɾ��ԭ����worker
        delete[] this->workers;
        this->workers = newspace;
        this->number = newSize;
        this->emptyFile = false;
        this->save();
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

int WorkerManager::getWorkerNumbers() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> did) {
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager::initWorker() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did) {
        Worker *worker = NULL;
        switch (did) {
            case 1:
                worker = new Employee(id, name, did);
                break;
            case 2:
                worker = new Manager(id, name, did);
                break;
            case 3:
                worker = new Boss(id, name, did);
                break;
        }
        this->workers[index] = worker;
        index++;
    }
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

void WorkerManager::showWorker() {
    //
    if (this->emptyFile) {
        cout << "file is not exist" << endl;
    } else {
        for (int i = 0; i < number; i++) {
            this->workers[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::isExist(int id) {
    int index = -1;

    for (int i = 0; i <= number; i++) {
        if (id == workers[i]->id) {
            index = id;
            break;
        }
    }
    return index;
}


void WorkerManager::delWorker() {
    if (this->emptyFile) {
        cout << "file not exist" << endl;
    } else {
        cout << "please int number you want to delete" << endl;
        int id = 0;
        cin >> id;

        int index = this->isExist(id);
        if (index != -1) {
            for (int i = 0; i < this->number - 1; i++) {
                this->workers[i] = this->workers[i + 1];
            }
            this->workers--;
            this->save();
            cout << "delete success" << endl;
        } else {
            cout << "delete failed, cannot found" << endl;
        }
        system("pause");
        system("cls");
    }
}

void WorkerManager::modifyWorker() {
    if (this->emptyFile) {
        cout << "file not exist" << endl;
    } else {
        cout << "please input number you want to modify" << endl;

        int id;
        cin >> id;
        int ret = this->isExist(id);
        if (ret != -1) {
            //find
            delete this->workers[ret];
            int newid = 0;
            string name = "";
            int select = 0;
            cout << "find " << newid << "please input new number" << endl;
            cin >> newid;
            cout << "new name please input " << endl;
            cin >> name;
            cout << "please select job title" << endl;
            cout << "1. Ա�� " << endl;
            cout << "2. ���� " << endl;
            cout << "3. �ϰ� " << endl;
            cin >> select;

            Worker *worker = NULL;
            switch (select) {
                case 1:
                    worker = new Employee(newid, name, 1);
                    break;
                case 2:
                    worker = new Manager(newid, name, 2);
                    break;
                case 3:
                    worker = new Boss(newid, name, 3);
                    break;
            }
            this->workers[ret] = worker;
            cout << "modify success" << endl;
            this->save();
        } else {
            cout << "modify failed, can not found" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::findWorker() {
    if (this->emptyFile) {
        cout << "file not exist" << endl;
    } else {
        cout << "which way you want to find��" << endl;
        cout << "1��find by id" << endl;
        cout << "2��find by name" << endl;
        int select = 0;
        cin >> select;

        if (select == 1) {
            int id;
            cin >> id;

            int ret = isExist(id);
            if (ret != -1) {
                cout << "find succrss" << endl;
                this->workers[ret]->showInfo();
            } else {
                cout << "find failed" << endl;
            }
        } else if (select == 2) {
            string name;
            cout << "please input name" << endl;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < number; i++) {
                if (workers[i]->name == name) {
                    cout << "find success" << endl;
                    workers[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "can not found " << endl;
            }
        } else {
            cout << "input failed" << endl;
        }
    }
    system("pause");
    system("cls");
}


void WorkerManager::sortWorkers() {
    if (this->emptyFile) {
        cout << "file not exist" << endl;
    } else {
        cout << "please input sort method�� " << endl;
        cout << "1��up" << endl;
        cout << "2��down" << endl;
        int select = 0;
        cin >> select;

        for (int i = 0; i < number; i++) {
            int minOrMax = i;
            for (int j = 0; j < j + 1; j++) {
                if (select == 1) {
                    if (workers[minOrMax]->id > workers[j]->id) {
                        minOrMax = j;
                    }
                } else {
                    if (workers[minOrMax]->id < workers[j]->id) {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax) {
                Worker *temp = workers[i];
                workers[i] = workers[minOrMax];
                workers[minOrMax] = temp;
            }
        }
        cout << "sort success" << endl;
        this->save();
        this->showWorker();
    }
    system("pause");
    system("cls");
}

void WorkerManager::clearFile() {

    cout << "clear all" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;

    int select = 0;
    cin >> select;
    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->workers != NULL) {
            for (int i = 0; i < number; i++) {
                if (this->workers[i] != NULL) {
                    delete this->workers[i];
                }
            }
            this->number = 0;
            delete[] this->workers;
            this->workers = NULL;
            this->emptyFile = true;
        }
        cout << "delete success" << endl;
        system("pause");
        system("cls");
    }
}