function [x] = spring_compress(k1, k2, d, W, h)
% computes maximum compression due to falling weight
x = zeros(1, length(h));
for (i = 1:length(h))
    if d > ((W(i) + sqrt((W(i)^2)+(2*k1*W(i).*h(i))))/k1)
        x(i) = (W(i) + sqrt((W(i)^2)+(2*k1*W(i).*h(i))))/k1;
    else
        pos_root = roots([(k1+(2*k2)),-((4*k2*d)+(2*W(i))),((2*k2*(d^2))-(2*W(i).*h(i)))]);
        x(i) = real(max(pos_root));
    end
end
end 
