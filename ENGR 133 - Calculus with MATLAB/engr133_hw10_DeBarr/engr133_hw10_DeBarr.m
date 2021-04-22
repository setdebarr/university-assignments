%% Homework 10
% ENGR 133-003
% Created by Sean DeBarr 4/5/2019
clear
close all
clc

%% Problem T9.19
clear

disp("*********************" + newline + "Problem T9.19" + newline);

% Declare data points
x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
y = [0, 2, 5, 7, 9, 12, 15, 18, 22, 30, 17];

% Backward difference estimate
dydx = diff(y) ./ diff(x);
dydx = [NaN, dydx];

% display results
fprintf("The estimate of the derivative dy/dx from the data points is:\n");
disp([dydx]);

%% Problem T9.20
clear

disp("*********************" + newline + "Problem T9.20" + newline);

% Declare data points
x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
y = [0, 2, 5, 7, 9, 10, 8, 7, 6, 4, 5];

% finds equation of curve that best fits the points
z = polyfit(x, y, 4);

% evaluates the function at various values of x
a = polyval(z, x);

% plot the curve
plot(x, a);
grid on;
xlabel("x");
ylabel("f(x)");
title("Plot of curve using polyfit and polyval");

% find points where the slope is zero
dxdy = roots(polyder(z));

% display results
fprintf("The points where the slope is zero are:\n");
disp([dxdy]);

%% Problem T9.22
clear

disp("*********************" + newline + "Problem T9.22" + newline);

% Create a vector to represent the polynomials
p1 = [5, 0, 7];
p2 = [5, -6, 7];

% calculate dp2/dx
dp2dx = polyder(p2);

% calculate d(p1*p2)/dx
dp1p2dx = polyder(p1, p2);

% calculate d(p2/p1)/dx
[a, b] = polyder(p2, p1);

% display results
fprintf("dp2/dx:\n");
disp([dp2dx]);

fprintf("d(p1*p2)/dx:\n");
disp([dp1p2dx]);

fprintf("d(p2/p1)/dx:\n");
disp([a]);
disp([b]);