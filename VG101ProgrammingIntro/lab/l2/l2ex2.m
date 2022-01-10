function l2ex2(n)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
fd=fopen('Triangle.txt','wt');
for i=1:1:n
    for c=1:1:(n-i)
        fprintf(fd,'  ');
    end
    l=rot90(diag(rot90(pascal(i))));
    for c=1:1:numel(l)
        for k=1:1:(3-fix(log10(l(1,c))))
            fprintf(fd,' ');
        end
        fprintf(fd,'%d',l(1,c));
    end
    fprintf(fd,'\n');
end
fclose(fd);
end

