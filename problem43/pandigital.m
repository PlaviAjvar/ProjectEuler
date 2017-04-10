function r = pandigital(a, idx, dig)

valrange = [];
r = int64(0);

if idx < 4 
    if idx == 1 %first digit can't be zero
        valrange = 1:9; 
    else
        valrange = 0:9;
    end
elseif idx == 4 %divisibility test for 2: last digit divisible by 2
    valrange = 0:2:9;
elseif idx == 5
    valrange = mod(3 - mod(a(3) + a(4), 3), 3):3:9;
elseif idx == 6 %divisibility test for 5: final digit either 0 or 5
    valrange = [0 5];
elseif idx == 7 %divisibility test for 7: multiply digits from right to left by repeating 
                %pattern 1,3,2,-1,-3,-2 from left to right and test divisibility by 7
    valrange = mod(7 - mod(3*a(6) + 2*a(5), 7), 7):7:9;
elseif idx == 8 %divisibility test for 11: form alternating sum of digits and test for 
                 %divisibility by 11(obviously left->right or right->left doesn't matter)
    valrange = mod(11 - mod(11+a(6)-a(7)+a(8), 11), 11):11:9;
elseif idx == 9 %brute
    for i = 0:9
        if mod(a(7)*100 + a(8)*10 + i, 13) == 0
            valrange(end+1) = i;
        end
    end
elseif idx == 10 %brute
    for i = 0:9
        if mod(a(8)*100 + a(9)*10 + i, 17) == 0
            valrange(end+1) = i;
        end
    end
else
    valrange = [];
    for i = 1:10
        r = 10*r + a(i);
    end
end

for i = valrange
    if dig(i+1) > 0 
        a(idx) = i;
        dig(i+1) = 0;
        r = r + pandigital(a, idx+1, dig);
        dig(i+1) = 1;
    end
end

end