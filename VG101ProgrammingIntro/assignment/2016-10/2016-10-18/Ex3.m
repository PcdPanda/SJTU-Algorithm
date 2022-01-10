function Ex3( n )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    fd1=fopen('Ex3.txt','w');
    for i=0:10
        fprintf(fd1,'%d ¡Á %d = %d\n',n,i,(n*i));
    end
    fclose(fd1);
end

