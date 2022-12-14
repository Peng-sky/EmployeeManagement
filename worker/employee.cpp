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

    cout << "职工编号： " << this->id
         << "\t name " << this->name
         << "\t depart name " << this->getDeptName()
         << "\t 完成任务" << endl;
}


string Employee::getDeptName() {
    return string("员工");
}
