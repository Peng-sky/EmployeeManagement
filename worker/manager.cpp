//
// Created by Peng on 2022-12-14.
//

#include "manager.h"

Manager::Manager(int id, std::string name, int did) {

    this->id = id;
    this->name = name;
    this->deptId = did;
}

void Manager::showInfo() {

    cout << "ְ����ţ� " << this->id
         << "\t name " << this->name
         << "\t depart name " << this->getDeptName()
         << "\t ����ϰ�������·������Ա��" << endl;
}


string Manager::getDeptName() {
    return string("����");
}
