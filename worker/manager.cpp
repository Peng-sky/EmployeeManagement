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

    cout << "职工编号： " << this->id
         << "\t name " << this->name
         << "\t depart name " << this->getDeptName()
         << "\t 完成老板的任务，下发任务给员工" << endl;
}


string Manager::getDeptName() {
    return string("经理");
}
