/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "common.h"
#include <curl/curl.h>
#include <string.h>
/**
* 往urlArr结构体中增加链接
*/
void addUrlArr(urlArr *urls, const char *url)
{
    strcpy(urls->urls[urls->num], url);
    urls->num++;
}
/**
* 获取返回html内容
*/
size_t callback_gethtml(void *ptr, size_t size, size_t nmemb, void *userp)
{
    strcat(userp, (char *)ptr);
    return size * nmemb;
}

/**
*  curl抓取
*/
char *curlHtml(char *url, struct curl_slist *headers)
{
    static char str[10000000] = {0};
    memset(str, '\0', sizeof(str));
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback_gethtml);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, str);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    //str[9999999] = '\0';
    return str;
}

/**
* 计算下字符指针指向的字符串的长度
*/
int strlenString(char *str)
{
    int i = 0;
    while (1)
    {
        if (*str == '\0')
        {
            break;
        }
        i++;
        str++;
    }
    return i;
}