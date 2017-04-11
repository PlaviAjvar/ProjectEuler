i = int64(1);
cnt = 0;

while 1
    x = i*(i+1)/2;
    j = (1 + sqrt(1+24*double(x))) / 6;
    k = (1 + sqrt(1+8*double(x))) / 4;
    if j == floor(j) && k == floor(k)
        cnt = cnt + 1;
    end
    if cnt == 3
        i*(i+1)/2
        break
    end
    i = i+1;
end