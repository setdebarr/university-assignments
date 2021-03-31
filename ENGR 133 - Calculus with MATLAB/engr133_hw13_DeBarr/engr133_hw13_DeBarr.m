%% Homework 13
% ENGR 133-003
% Created by Sean DeBarr 4/26/2019
clear
close all
clc

%% Problem T11.3-2
clear

disp("*********************" + newline + "Problem T11.3-2" + newline);

% declare symbolic variables
syms x y;

% declare equation symbolicly
z = 5*cos(2*x) * log(4*y);

% find derivative of function with respect to y
dzdy = diff(z, y);

% display results
fprintf("dz/dy = %s.\n\n", dzdy);

%% Problem T11.3-3
clear

disp("*********************" + newline + "Problem T11.3-3" + newline);

% declare symbolic variables
syms x;

% declare equation symbolicly
y = x * sin(3*x);

% find integral of function with respect to x
integral = int(y);

% display results
fprintf("The integral = %s.\n\n", integral);

%% Problem T11.3-4
clear

disp("*********************" + newline + "Problem T11.3-4" + newline);

% declare symbolic variables
syms x y;

% declare equation symbolicly
z = 6*y^2 * tan(8*x);

% find integral of function with respect to x
integral = int(z, y);

% display results
fprintf("The integral = %s.\n\n", integral);

%% Problem T11.3-7
clear

disp("*********************" + newline + "Problem T11.3-7" + newline);

% declare symbolic variable
syms m;

% find formula for the sum
form = symsum(m^3, m, 0, m-1);

% display results
fprintf("The formula is %s.\n\n", form);

%% Problem T11.3-9
clear

disp("*********************" + newline + "Problem T11.3-9" + newline);

% declare symbolic variable
syms x;

% declare equation symbolicly
y = (2*x -10) / (x^3 - 125);

% evaluate the limit
lim = limit(y, x, 5);

% display results
fprintf("The limit as x -> 5 is %s.\n\n", lim);

%% Problem T11.11
clear

disp("*********************" + newline + "Problem T11.11" + newline);

% declare symbolic variable
syms x;

% declare equation symbolicly
y = 3^x - 2*x;

% find derivative of function with respect to x
dydx = diff(y, x);

% find values where dydx is 0
values = solve(dydx, x);

% display results
fprintf("The the value of x where the graph has a horizontal\n");
fprintf("tangent line %s.\n\n", values);

%% Problem T11.13
clear

disp("*********************" + newline + "Problem T11.13" + newline);

% declare symbolic variable
syms r;

% declare equations symbolicly
S = 4*pi*r^2;
V = (4*pi*r^3)/3;

% ************************************************************************
% Part a 
disp("Part a" + newline);

% find derivative
dSdV = diff(S, r) / diff(V, r);

% display results
fprintf("dS/dV = %s.\n\n", dSdV);

% ************************************************************************
% Part b 
disp("Part b" + newline);

% solve for r
radius = solve(V == 30, r);

% substitute in radius to find rate
rate = double(subs(dSdV, radius(1)));

% display results
fprintf("The rate of increase in the balloon's surfacea area\n");
fprintf("is %g in^2/in^3.\n\n", rate);

%% Problem T11.22
clear

disp("*********************" + newline + "Problem T11.22" + newline);

syms t R;

% ************************************************************************
% Part a
disp("Part a" + newline);

% declare current in A
i = 0.2 * (1 + sin(0.2 * t));

% take the integral to get function
E = int(i^2 * R);

% display result
fprintf("Energy dissipated as a function of time:\n%s\n\n", E);

% ************************************************************************
% Part b
disp("Part b" + newline);

% find energy disipated in 1 minute
D = subs(E, {t, R}, {60, 1000});

% convert to double
D = double(D);

% display result
fprintf("Energy dissipated in 1 minute if R = 1000ohms is:\n");
fprintf("%g\n\n", D);
clear
