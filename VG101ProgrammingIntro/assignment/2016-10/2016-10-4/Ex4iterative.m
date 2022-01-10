function [ r ] = Ex4iterative(fun,x0,x1,p)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    x=[];
    x(1)=x0;
    x(2)=x1;
    f=inline(fun); %prompt the function expression
    n=3;
    while 1
        x(n)=(x(n-2)*f(x(n-1))-x(n-1)*f(x(n-2)))/(f(x(n-1))-f(x(n-2)));%calculate the root
        if abs(f(x(n))-0)<=p
            break;
        end
        n=n+1;
    end %iterative     
    r=x(n);
end

