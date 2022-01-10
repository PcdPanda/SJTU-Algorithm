function [c] = l2ex1(fun,a,b)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
f=inline(fun);
c=(a+b)/2;
while f(c)~=0&&abs(f(c)-0)>0.001
    if sign(f(a))==sign((f(c)))
        a=c;
    else
        b=c;
    end
    c=(a+b)/2;
end
end

