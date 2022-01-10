function [ r ] = Ex4recursion(fun,x0,x1,p)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    f=inline(fun); %prompt the function expression
    x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));%calculate the similar root
    if abs(f(x2)-0)<=p
        r=x2;
        return;
    end
    x0=x1;
    x1=x2;
    r=Ex4recursion(fun,x0,x1,p);%recursion
end

