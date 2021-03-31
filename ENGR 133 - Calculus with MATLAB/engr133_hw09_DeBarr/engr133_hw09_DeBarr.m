%% Homework 9
% ENGR 133-003
% Created by Sean DeBarr 3/29/2019
clear
close all
clc

%% Problem T9.1-1
clear

disp("*********************" + newline + "Problem T9.1-1" + newline);

% declare variables
t = 0:10;
a = [0, 2, 4, 7, 11, 17, 24, 32, 41, 48, 51];

% preallocate for extra speed
d = zeros(1, 10);
v = zeros(1, 10);

% set initial value to 0
v(1) = 0;
d(1) = 0;

% calculate velocity and distance
for (k = 1:10)
    v(k + 1) = trapz(t(k:k + 1), a(k:k + 1)) + v(k);
    d(k + 1) = trapz(t(k:k + 1), v(k:k + 1)) + d(k);
end

% display results in table form
fprintf("Time (t)[sec] vs Distance (d)[m]:\n");
disp([t', d']);

% The final displacement in the textbook is wrong because when you run
% the code, the velocity at 9 sec is 117.5, but the book has it as being
% 117. Therefore, my values are slightly different.

%% Problem T9.1-2
clear

disp("*********************" + newline + "Problem T9.1-2" + newline);

% calculate integral
A = integral(@(x) 1 ./ x, 2, 5);

% display results
fprintf("A = %.4f, which is the same solution as the\n", A);
fprintf("closed-form solution, which is A = 0.9163.\n\n");

%% Problem 9.3
clear

disp("*********************" + newline + "Problem 9.3" + newline);

% declare variables
t = 0:4;
a = 7 .* t;

% preallocate for extra speed
d = zeros(1, 4);
v = zeros(1, 4);

% set initial value to 3
v(1) = 3;

% set initial value to 0
d(1) = 0;

% calculate velocity and distance
for (k = 1:4)
    v(k + 1) = trapz(t(k:k + 1), a(k:k + 1)) + v(k);
    d(k + 1) = trapz(t(k:k + 1), v(k:k + 1)) + d(k);
end

% display results 
fprintf("The total distance the object travels in 4s is %gm.\n\n", d(5));

%% Problem 9.6
clear

disp("*********************" + newline + "Problem 9.6" + newline);

% declare variables
t = 0:10;
v = [0, 2, 5, 7, 9, 12, 15, 18, 22, 20, 17];
d(1) = 3;

% calculate position
for (k = 1:10)
    d(k + 1) = trapz(t(k:k + 1), v(k:k + 1)) + d(k);
end

% display results 
fprintf("The objects position at t = 10s is %gm.\n\n", d(11));

%% Problem 9.9
clear

disp("*********************" + newline + "Problem 9.9" + newline);

% declare variables and force
t = 0:5;
F = @(t) (500 .* (2 - exp(-t) .* sin(5 * pi .* t)));

% calculate accelaration
A = @(t) (F(t) / 100);

% calculate velocity
velocity = integral(A, 0, 5);

% display results 
fprintf("The objects velocity at t = 5s is %gm.\n\n", velocity);
