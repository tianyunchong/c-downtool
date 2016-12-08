/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   getlinks.h
 * Author: zyh
 *
 * Created on 2016年12月8日, 上午9:23
 */

#ifndef GETLINKS_H
#define GETLINKS_H
#include "../common.h"
void getSearchUrlArr(char *url, urlArr *searchUrlArr);
void getDownUrlArr(urlArr *searchUrlArr, urlArr *downUrlArr);
#endif /* GETLINKS_H */
