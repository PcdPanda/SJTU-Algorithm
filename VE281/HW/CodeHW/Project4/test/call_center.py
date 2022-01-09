#!/usr/bin/python
# -*- coding: utf-8 -*-
call = 100
import random
count = 0
f = open("in","w")
do = [False,True]
vip = ['regular','silver','gold','platinum']
duration = [1,2,3,4,5,6,7,8,9,10]
name = ["Niqiu","Ziwei","Derrick","XianYu","Xiaojiejie","Zhanan","Weikang","Yaoyue", "duke", "Gezi", "Mengnan", "ZhouRouxing", "ZhuChengyu", "Feizhai", "Shouzhai"]
time = 0
total_duration = 0;
print>>f,(100)
while True:
	todo = random.choice( do )
	while todo:
		callTime = random.choice(duration);
		total_duration = total_duration + callTime;
		print>>f,("%d %s %s %d" % (time,random.choice(name),random.choice(vip),callTime))
		count+=1
		todo = random.choice(do)
		if count==call:
			break
	if count==call:
		break
	time+=1
print("Total call duration: %d"% total_duration)

