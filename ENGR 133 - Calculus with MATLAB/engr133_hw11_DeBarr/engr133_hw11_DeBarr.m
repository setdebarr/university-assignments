%% Homework 11
% ENGR 133-003
% Created by Sean DeBarr 4/12/2019
clear
close all
clc

%% Problem T11.1-1
clear

disp("*********************" + newline + "Problem T11.1-1" + newline);

% declare expressions
syms x;
E1 = x^3 - 15*x^2 + 75*x - 125;
E2 = (x+5)^2 - 20*x;

% ************************************************************************
% Part a 
disp("Part a" + newline);

% display product
disp(simplify(E1 * E2));

% ************************************************************************
% Part b 
disp("Part b" + newline);

% display quotient
disp(simplify(E1 / E2));

% ************************************************************************
% Part c 
disp("Part c" + newline);
clear

% define x
x = sym(7.1);

% redeclare expressions
E1 = x^3 - 15*x^2 + 75*x - 125;
E2 = (x+5)^2 - 20*x;

% display symbolic form
fprintf("Sum in symbolic form: %s\n", (E1 + E2));

% display numeric form
fprintf("Sum in numeric form: %.4f\n\n", double(E1 + E2));

%% Problem 11.1
clear

disp("*********************" + newline + "Problem 11.1" + newline);

% ************************************************************************
% Part a 
disp("Part a" + newline);

% declare expression
syms x;
A = (sin(x)^2 + cos(x)^2);

% simplify and display result
disp(simplify(A));

% ************************************************************************
% Part b 
disp("Part b" + newline);
clear

% declare expression
syms x y;
B = sin(x + y);

% expand and display result
disp(expand(B));

% ************************************************************************
% Part c 
disp("Part c" + newline);
clear

% declare expression
syms x;
C = sin(2*x);

% expand and display result
disp(expand(C));

% ************************************************************************
% Part d 
disp("Part d" + newline);
clear

% declare expression
syms x;
D = (cosh(x)^2 - sinh(x)^2);

% simplify and display result
disp(simplify(D));

%% Problem 11.2
clear

disp("*********************" + newline + "Problem 11.2" + newline);

% declare expression
% let t = theta
syms y t x;
y = cos(5 * t);

% expand the expression and substitute cos(theta) for x
y = expand(y);
y = subs(y, cos(t), x);

% display expression
fprintf("The expression is: %s\n\n", y);

%% Problem 11.4
clear

disp("*********************" + newline + "Problem 11.4" + newline);

% declare expression
syms x y r;
C = x^2 + y^2 - r^2;

% substitute in the offset coordinates
syms a b;
C = subs(C, [x, y], [x - a, y - b]);

% expand and display the expression
fprintf("The expanded expression is: ");
disp(expand(C));

% display manually determained values of the coefficients
fprintf("The coefficients are:\n");
fprintf("A = 1\nB = -2a\nC = 0\nD = -2b\nE = 1\nF = r^2 - a^2 - b^2\n");
