function [A, h] = coneArea(R)
% coneArea calculates the surface area of a conical paper cup given the
% radius and volume
    global V;
    h = (3 .* V) ./ (pi .* R.^2); 
    A = (pi .* R .* sqrt((R.^2) + h.^2));
end

