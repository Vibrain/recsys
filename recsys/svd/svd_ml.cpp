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
 * 本程序的目的是实现koren在SIGKDD'08论文中的方法，svd model, the dataset is movielens
 * The purpose of this program is to implement the in the SVD method of koren's SIGKDD'08 paper,
 * using the movielens dataset.
 *
 */
 
#include "../commonHeader.h"
#include "../common.cpp"
#include "../mlBase.cpp"
#define USER_NUM 943 //10K:943 1M:6040
#define ITEM_NUM 1682 //10K:1682 1M:3900
#define K_NUM  50     //dimension
#define TRAINING_SET "../dataset/movielens/ua.base" //training set
#define PROBE_SET "../dataset/movielens/ua.test"  //test set
#define RATE_SP "	"  //rate Separator
#include "./svdBase.cpp"

int main(int argc, char ** argv)
{
    time_t start,end;
	/* 구조체만 초기화 강요해서 NULL 배정*/
    struct tm * timeStartInfo = NULL;
    struct tm * timeEndInfo = NULL;
    double duration; 
    start = time(NULL);
	localtime_s(timeStartInfo, &start);
	/* safety 강요로 인한 asctime_s 사용 */
	char buffer[32];
	char buffer_end[32];
	asctime_s(buffer, 32, timeStartInfo);
	string timeStartStr(buffer);
    float alpha1 = 0.01;  //0.0045according to the paper of "a guide to SVD for CF"
    float alpha2 = 0.01;  //0.0045according to the paper of "a guide to SVD for CF"
    float beta1 = 0.05;   //0.015 according to the paper of "a guide to SVD for CF"
    float beta2 = 0.05;   //according my own experiment,beta=0.05 is very good ,the RMSE of movielens(1M) test 
    //can reach 0.868692  at step=44
    
    //for(int i=0; i < 10; i++)
    {
        //alpha = i*0.0005 + 0.0025;
        //cout << alpha << endl;
        //void model(int dim, float  alpha1, float alpha2, float beta1, float beta2,
        // int maxStep=60,double slowRate=1,bool isUpdateBias=true)
        svd::model(K_NUM,alpha1,alpha2,beta1,beta2,60,0.99,true);
    }
    end = time(NULL);
    duration = (end-start);
	localtime_s(timeEndInfo, &end);
	asctime_s(buffer_end, 32, timeEndInfo);
	string timeEndStr(buffer_end);
	cout << "Start at " << timeStartStr << ", and end at " << timeEndStr;
    cout << "duration:"<<duration <<" s!" <<endl;
    return 0;
}
