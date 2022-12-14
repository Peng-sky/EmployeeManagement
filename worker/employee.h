//
// Created by Peng on 2022-12-14.
//

#ifndef EMPLOYEEMANAGEMENT_EMPLOYEE_H
#define EMPLOYEEMANAGEMENT_EMPLOYEE_H

#pragma once

#include "iostream"
#include "worker.h"

using namespace std;

class Employee : public Worker {

public:
    Employee(int id, string name, int did);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //EMPLOYEEMANAGEMENT_EMPLOYEE_H
