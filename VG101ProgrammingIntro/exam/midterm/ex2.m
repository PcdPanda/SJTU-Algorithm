function ex2(n)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    global t;
    global fd;
    t=0;
    P=[n 0 0];
    k=n;
    fd=fopen('Output.txt','w');
    move(n,1,2,3);
    fclose(fd);
    disp (['It took ',num2str(t),' moves']);
end
function t=move(n,a,b,c);
    global t;
    global fd;
    if n==1
        fprintf(fd,'moving disc %d from Peg%d to Peg%d\n',n,a,b);   
    else
        move(n-1,1,3,2);
        fprintf(fd,'moving disc %d from Peg%d to Ped%d\n',n,a,b);
        move(n-1,3,2,1);
    end
    t=t+1;
end
