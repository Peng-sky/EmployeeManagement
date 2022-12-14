//
// Created by Peng on 2022-12-13.
//

#ifndef EMPLOYEEMANAGEMENT_WORKERMANAGER_H
#define EMPLOYEEMANAGEMENT_WORKERMANAGER_H
#pragma once

#include "iostream"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "Boss.h"
#include "fstream"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager {
public:
    WorkerManager();

    void showMenu();

    void exitSystem();

    int number;

    Worker **workers;

    void addWorker();

    void save();

    ~WorkerManager();
};


#endif //EMPLOYEEMANAGEMENT_WORKERMANAGER_H
