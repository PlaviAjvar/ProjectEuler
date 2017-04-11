j = int64(1);
D = int64(1e62);

while 1
    j
    k = j-1;
    while 1
        if k == 0 || P(j) - P(k) >= D
            break
        end
        if isPentagon(P(k) + P(j)) && isPentagon(P(j)-P(k))
            D = min(D, P(j) - P(k));
        end
        k = k-1;
    end
    if P(j+1) - P(j) > D
        break
    end
    j = j+1;
end

D