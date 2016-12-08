/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gumbo_class_link.h
 * Author: zyh
 *
 * Created on 2016年12月8日, 上午9:28
 */

#ifndef GUMBO_CLASS_LINK_H
#define GUMBO_CLASS_LINK_H
#include "../common.h"
#include "gumbo.h"
/** 从一个节点提取所有的链接*/
void search_for_links(GumboNode *node, urlArr *urls);
/** 扫描节点获取所有class=class的接单，并从对应的节点中获取所有的链接*/
void getLinksOfClassNode(GumboNode *node, urlArr *urls, char *classname);
/** 从某种tag节点下获取所有的链接*/
void getLinkOfTagNode(GumboNode *node, urlArr *urls, const int tagtype);
#endif /* GUMBO_CLASS_LINK_H */
