//
// Created by Peng on 2022-12-14.
//

#include "employee.h"

Employee::Employee(int id, std::string name, int did) {

    this->id = id;
    this->name = name;
    this->deptId = did;
}

void Employee::showInfo() {

    cout << "ְ����ţ� " << this->id
         << "\t name " << this->name
         << "\t depart name " << this->getDeptName()
         << "\t �������" << endl;
}


string Employee::getDeptName() {
    return string("Ա��");
}
