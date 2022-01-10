clc;
clear all;
a=input('enter your number: ');%input how much weight in oroginal weight
u=input('enter your original unit: ','s');
a1=[num2str(a),u,'='];
switch u
    case 'stones'
    a=14*a;
    disp([a1,num2str(a),' pounds'])
    case 'pounds'
    a=a*6.35/14;
    disp([a1,num2str(a),' kg'])
    case 'kg'
    a=a/6.35;
    disp([a1,num2str(a),' stones'])
end  
