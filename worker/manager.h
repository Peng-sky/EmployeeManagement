//
// Created by Peng on 2022-12-14.
//

#ifndef EMPLOYEEMANAGEMENT_MANAGER_H
#define EMPLOYEEMANAGEMENT_MANAGER_H

#pragma once

#include "iostream"

using namespace std;

#include "worker.h"

class Manager : public Worker {

public:
    Manager(int id, string name, int did);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //EMPLOYEEMANAGEMENT_MANAGER_H
