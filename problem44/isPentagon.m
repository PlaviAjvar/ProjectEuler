function t = isPentagon(n) %returns n-th pentagonal number

x = (1+sqrt(1+12*double(2*n))) / 6;
eps = 1e-15;
t = abs(x - floor(x)) < eps;

end