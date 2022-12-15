//
// Created by Peng on 2022-12-14.
//

#ifndef EMPLOYEEMANAGEMENT_WORKER_H
#define EMPLOYEEMANAGEMENT_WORKER_H
#pragma once
#include "string"
#include "iostream"
using namespace std;

class Worker {

public:

    virtual void showInfo() = 0;

    virtual  string getDeptName() = 0;
    //
    int id;

    string name;

    int deptId;

};


#endif //EMPLOYEEMANAGEMENT_WORKER_H
