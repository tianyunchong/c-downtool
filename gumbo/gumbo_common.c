/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gumbo_common.c
 * Author: zyh
 * 
 * Created on 2016年12月8日, 上午9:27
 */
#include <stdio.h>
#include "gumbo_common.h"
#include "gumbo.h"

/**
* 获取gumbo结构体变量 
*/
GumboOutput * get_gumbo_obj(char *input, int input_length)
{
    GumboOutput *output = gumbo_parse_with_options(
        &kGumboDefaultOptions, input, input_length);
    return output;
}