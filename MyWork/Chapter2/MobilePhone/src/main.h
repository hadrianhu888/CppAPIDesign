/**
 * @file main.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAIN_H
#define MAIN_H

#include "MobilePhone.h"
#include <iostream>
#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MobilePhone MobilePhone;

MobilePhone *MobilePhone_new(const std::string &model,
                             const std::string &manufacturer,
                             const std::string &operatingSystem);

int main(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif // MAIN_C

#endif // MAIN_H