function t = time(h, v0, g)
% time calculates the time required to reach a certain height
    t = roots([0.5*g, -v0, h]);
end

