/* Copyright (C) 2011 Lv Hongliang. All Rights Reserved.
 * please maitain the copyright information completely when you redistribute the code.
 * 
 * If there are some bugs, please contact me via email honglianglv@gmail.com or submit the bugs 
 * in the google code project http://code.google.com/p/recsyscode/issues/list
 * 
 * my blog: http://lifecrunch.biz
 * my twitter: http://twitter.com/honglianglv
 * my google profile:https://profiles.google.com/honglianglv/about?hl=en
 *
 * It is free software; you can redistribute it and/or modify it under 
 * the license GPLV3.
 *
 * 本程序的目的是实现koren在SIGKDD'08论文中的SVD++方法, 使用的数据是netflix的数据
 * The purpose of this program is to implement the SVD++ method of koren's SIGKDD'08 paper,
 * using the netflix dataset.
 */

#include "../commonHeader.h"
#include "../common.cpp"
#include "../netflixBase.cpp"
#define USER_NUM 480189  //10K:943 1M:6040
#define ITEM_NUM 17770 //10K:1682 1M:3900
#define K_NUM  50
#define TRAINING_SET "./data_without_prob.txt"
#define PROBE_SET "./probe_real.txt"
#define RATE_SP ","  //rate Separator
#include "./svdplusplusBase.cpp"

int main(int argc, char ** argv)
{
    time_t start,end;
	struct tm startInfo;
	struct tm endInfo;
	double duration;
	start = time(NULL);
	localtime_s(&startInfo, &start);
	char buffer[32];
	char buffer_end[32];
	asctime_s(buffer, 32, &startInfo);
	string startStr(buffer);
    float alpha1 = 0.007;    //according suggestion of xlvector
    float alpha2 = 0.007;    //according suggestion of xlvector
    float beta1  = 0.01;     //according suggestion of xlvector
    float beta2  = 0.01;     //according suggestion of xlvector  
    //for(int i=0; i < 10; i++)
    {
        //    beta = i*0.001 + 0.002;
        //    cout << beta << endl;
        svd::model(K_NUM,alpha1,alpha2,beta1,beta2,60,0.9);
    }
    end = time(NULL);
    duration = end-start;
	localtime_s(&endInfo, &end);
	asctime_s(buffer_end, 32, &endInfo);
	string endStr(buffer_end);
	cout << "start at" << startStr << ". And end at " << endStr << endl;
    cout << "duration:"<<duration <<" s!" <<endl;
    return 0;
}