/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   getlinks.c
 * Author: zyh
 * 
 * Created on 2016年12月8日, 上午9:23
 */
#include "getlinks.h"

#include <string.h>
#include "../common.h"
#include <curl/curl.h>
#include "gumbo.h"
#include "../gumbo/gumbo_common.h"
#include "../gumbo/gumbo_class_link.h"

/**
* 搜索获取盘多多搜索url
*/
void getSearchUrlArr(char *url, urlArr *searchUrlArr)
{

    char *html;
    struct curl_slist *headers = NULL;
    /** 获取下header*/
    headers = curl_slist_append(headers, "Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
    //headers = curl_slist_append(headers, "Accept-Encoding:gunzip, deflate, sdch");
    headers = curl_slist_append(headers, "Accept-Language:zh-CN,zh;q=0.8");
    headers = curl_slist_append(headers, "Connection:keep-alive");
    headers = curl_slist_append(headers, "Cookie:Hm_lvt_11b39dcf34d304adbc3f3f49e67cb940=1480900705,1481179957; Hm_lpvt_11b39dcf34d304adbc3f3f49e67cb940=1481186798; CNZZDATA5767138=cnzz_eid%3D138482800-1480896327-%26ntime%3D1481186261");
    headers = curl_slist_append(headers, "Host:www.panduoduo.net");
    headers = curl_slist_append(headers, "Upgrade-Insecure-Requests:1");
    headers = curl_slist_append(headers, "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.100 Safari/537.36");
    html = curlHtml(url, headers);
    curl_slist_free_all(headers);
    int len = strlenString(html);
    GumboOutput *output = get_gumbo_obj(html, len);
    getLinkOfTagNode(output->root, searchUrlArr, GUMBO_TAG_H3);
}

/**
 * 获取下载页面的url
 * @param searchUrlArr 搜索地址url
 * @param downUrlArr   下载地址url
 */
void getDownUrlArr(urlArr *searchUrlArr, urlArr *downUrlArr)  
{
    struct curl_slist *headers = NULL;
    /** 获取下header*/
    headers = curl_slist_append(headers, "Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
    //headers = curl_slist_append(headers, "Accept-Encoding:gunzip, deflate, sdch");
    headers = curl_slist_append(headers, "Accept-Language:zh-CN,zh;q=0.8");
    headers = curl_slist_append(headers, "Connection:keep-alive");
    headers = curl_slist_append(headers, "Cookie:Hm_lvt_11b39dcf34d304adbc3f3f49e67cb940=1480900705; Hm_lpvt_11b39dcf34d304adbc3f3f49e67cb940=1480903871; CNZZDATA5767138=cnzz_eid%3D138482800-1480896327-%26ntime%3D1480901727");
    headers = curl_slist_append(headers, "Host:www.panduoduo.net");
    headers = curl_slist_append(headers, "Upgrade-Insecure-Requests:1");
    headers = curl_slist_append(headers, "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.100 Safari/537.36");
    int i = 1;
    char url[100];
    char *html;
    printf("%d\n", searchUrlArr->num);
    while (i < searchUrlArr->num) {
        strcpy(url, "http://www.panduoduo.net");
        strcat(url, searchUrlArr->urls[i]);
         /** 获取下载页面html */
        html = curlHtml(url, headers);
        printf("%s\n", html);
        /** 提取下载链接 */
        int len = strlenString(html);
        printf("%d: %s,长度: %d\n", i, url, len);
        GumboOutput *output = get_gumbo_obj(html, len);
        getLinksOfClassNode(output->root, downUrlArr, "dbutton2");
        i++;
        if (i > 1) {
            break;
        }
    }
    fprintf(stdout, "down:%d\n", downUrlArr->num);
    fprintf(stdout, "%s\n", downUrlArr->urls[0]);
    fprintf(stdout, "%s\n", downUrlArr->urls[1]);
    fprintf(stdout, "%s\n", downUrlArr->urls[2]);
    curl_slist_free_all(headers);
}