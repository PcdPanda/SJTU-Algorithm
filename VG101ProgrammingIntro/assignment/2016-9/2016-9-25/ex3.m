clc;
clear all;
angle=1/50;%input the angle between a vertical rod and its shadow
d=5000*157.5;%input the distance between Syene and Alexandria
c=d/angle;%calculate The Earth's circumsference
r=c/(2*pi);
disp(['circumsference=',num2str(c),' and radius = ',num2str(r)]);

