#!/usr/bin/python
# -*- coding: utf-8 -*-
call = 200
import random
count = 0
f = open("in","w")
option = ["BUY", "SELL"]
ts_max = 200
clt_num = 20
for i in range(ts_max):
	cnt = random.randint(0, 80)
	for j in range(cnt): 
		op = random.choice(option)
		clt = random.randint(0, clt_num)
		price = random.randint(20, 300)
		num = random.randint(20, 300)
		duration = random.randint(0, 300)
		stock = random.randint(0, 50)
		if duration > 210: 
			duration = -1
		if duration <= 210 and duration > 200:
			duration = 0
		print>>f, ("%d n%d %s s%d $%d #%d %d"%\
		(i, clt, op, stock, price, num, duration) )
