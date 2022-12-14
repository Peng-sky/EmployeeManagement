//
// Created by Peng on 2022-12-14.
//

#ifndef EMPLOYEEMANAGEMENT_BOSS_H
#define EMPLOYEEMANAGEMENT_BOSS_H

#pragma once

#include "iostream"
#include "worker.h"
class Boss : public Worker{

public:
    Boss(int id, string name, int did);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //EMPLOYEEMANAGEMENT_BOSS_H
