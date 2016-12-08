/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: zyh
 *
 * Created on 2016年12月8日, 上午7:58
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "links/getlinks.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char *url = "http://www.panduoduo.net/s/name/精灵王座";
    /** 存放盘多多搜索的url集合 */
    urlArr searchUrlArr;
    searchUrlArr.num = 0;
    urlArr downUrlArr;
    downUrlArr.num = 0;
    /** 开始搜索获取盘多多url地址 */
    getSearchUrlArr(url, &searchUrlArr);
    /** 开始通过搜索url地址获取下载地址 */
    getDownUrlArr(&searchUrlArr, &downUrlArr);
    printf("下载地址数量: %d\n", downUrlArr.num);
    return (EXIT_SUCCESS);
}

