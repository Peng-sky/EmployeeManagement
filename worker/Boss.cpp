//
// Created by Peng on 2022-12-14.
//

#include "Boss.h"
Boss::Boss(int id, std::string name, int did) {

    this->id = id;
    this->name = name;
    this->deptId = did;
}

void Boss::showInfo() {

    cout << "ְ����ţ� " << this->id
         << "\t name " << this->name
         << "\t depart name " << this->getDeptName()
         << "\t ����˾��������" << endl;
}


string Boss::getDeptName() {
    return string("�ϰ�");
}
