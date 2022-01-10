clear all,clc;
n=input('Please enter the total number of cars = ');
hold on;
x1=[0 25 25];
y1=[33 33 58];
y2=[25 25 0];
y3=[58 33 33];
c=[];
for i=1:n
    c=[c randi(4)];
end
plot(x1,y1,'b',x1,y2,'b',y1,x1,'b',y1,y3,'b');
plot(25,25,'.r',33,33,'.r',25,33,'.g',33,25,'.g');
i=0;
 while 1
    if mod(i,2)==0
        plot(25,25,'.r',33,33,'.r',25,33,'.g',33,25,'.g');
    else
        plot(25,25,'.g',33,33,'.g',25,33,'.r',33,25,'.r');
    end
    axis([0 58 0 58]);
    pause(5);
    i=i+1;
 end