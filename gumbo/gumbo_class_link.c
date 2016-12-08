/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gumbo_class_link.c
 * Author: zyh
 * 
 * Created on 2016年12月8日, 上午9:28
 */

#include "gumbo_class_link.h"
#include "gumbo.h"
#include <string.h>
#include "../common.h"
/**
* 从一个节点提取所有的链接
*/
void search_for_links(GumboNode *node, urlArr *urls)
{
    if (node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }
    GumboAttribute *href;
    if (node->v.element.tag == GUMBO_TAG_A &&
        (href = gumbo_get_attribute(&node->v.element.attributes, "href")))
    {
        //printf("url地址：%s\n", href->value);
        addUrlArr(urls, href->value);
    }

    GumboVector *children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i)
    {
        search_for_links(children->data[i], urls);
    }
}
/**
* 扫描节点获取所有class=class的接单，并从对应的节点中获取所有的链接
*/
void getLinksOfClassNode(GumboNode *node, urlArr *urls, char *classname)
{
    /** 节点类型判断，不是该类型的不处理 */
    if (node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }
    /** 获取下当前节点class属性*/
    GumboAttribute *attr = gumbo_get_attribute(&node->v.element.attributes, "class");
    /**该节点获取到了class属性并且class==row */
    if (attr && strcmp(attr->value, classname) == 0)
    {
        search_for_links(node, urls);
        return;
    } 
    /** 遍历下字节点，判断下是否有row节点*/
    GumboVector *children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i)
    {
        getLinksOfClassNode(children->data[i], urls, classname);
    }
}
/**
* 从某种tag节点下获取所有的链接
*/
void getLinkOfTagNode(GumboNode *node, urlArr *urls, const int tagtype)
{
    /** 非节点类型不进行处理 */
    if (node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }
    if (node->v.element.tag == tagtype)
    {
        search_for_links(node, urls);
    }
    /** 遍历子节点 */
    GumboVector *children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i)
    {
        getLinkOfTagNode(children->data[i], urls, tagtype);
    }
}