function value = fxy(x,y)
% calculate f(x,y) according to the values of x and y
if (x >= 0) && (y >= 0)
    value = x * y;
elseif (x >= 0) && (y <= 0)
    value = x * y.^2;
elseif (x < 0) && (y >= 0)
    value = x.^2 * y;
elseif (x < 0) && (y < 0)
    value = x.^2 * y.^2;
end

