clear all;
clc;
prompt=input('please enter the distance:');%input the total distance
laps=fix(prompt/400);%divide the distance into laps and get the integer
rem=(prompt-laps*400);%calculate the remaining distance which is smaller than 400
if laps==0
    rem=400-prompt;
    disp([num2str(rem),'m']);
elseif rem==0
         disp([num2str(laps),' laps ']);
else
    disp([num2str(laps),' laps and ',num2str(400-rem),' m']);
end