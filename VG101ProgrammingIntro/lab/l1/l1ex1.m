clc;
clear all;
x=[3;2;6;8];
y=[4;1;3;5];
y=sum(x)+y;
y=y./x;
z=x.*y;
w=sum(z);
disp(x'*y-w);