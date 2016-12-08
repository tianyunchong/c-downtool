/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   common.h
 * Author: zyh
 *
 * Created on 2016年12月8日, 上午9:18
 */

#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
extern "C" {
#endif
#include <curl/curl.h>
typedef struct _urlArr {
    int num;
    char urls[2000][200];
} urlArr;
void addUrlArr(urlArr *urls, const char *url);
size_t callback_gethtml(void *ptr, size_t size, size_t nmemb, void *userp);
char *curlHtml(char *url, struct curl_slist *headers);
int strlenString(char *str);

#ifdef __cplusplus
}
#endif

#endif /* COMMON_H */

