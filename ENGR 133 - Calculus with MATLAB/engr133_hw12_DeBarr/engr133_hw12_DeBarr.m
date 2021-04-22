%% Homework 12
% ENGR 133-003
% Created by Sean DeBarr 4/19/2019
clear
close all
clc

%% Problem T11.2-1
clear

disp("*********************" + newline + "Problem T11.2-1" + newline);

% declare symbolic variable
syms x

% declare equation symbolicly
eqn = sqrt(1 - x^2) == x;

% solve equation symbolicly
solution = solve(eqn);

% display results
fprintf("The solution is: %s\n\n", solution);

%% Problem T11.2-2
clear

disp("*********************" + newline + "Problem T11.2-2" + newline);

% declare symbolic variables
syms x y a

% declare equations symbolicly
eqn1 = x + 6*y == a;
eqn2 = 2*x - 3*y == 9;

% solve equations symbolicly for 'x' and 'y'
solution = solve(eqn1, eqn2, x , y);

% display results
fprintf("The solution for 'x' in terms of 'a' is: %s\n", solution.x);
fprintf("The solution for 'y' in terms of 'a' is: %s\n\n", solution.y);


%% Problem 11.7
clear

disp("*********************" + newline + "Problem 11.7" + newline);

% ************************************************************************
% Part a 
disp("Part a" + newline);

% declare symbolic variables
syms x a

% declare equation symbolicly
eqn = x^3 + 8*x^2 + a*x + 10 == 0;

% solve equation symbolicly for 'x' 
solution = solve(eqn);


% display results
fprintf("The solution for 'x' in terms of 'a' is: \n");
disp(solution);

% ************************************************************************
% Part b 
disp("Part b" + newline);

% evaluate solution for 'a = 17'
roots = subs(solution, a, 17);

% convert to numerical answer
roots = double(roots);

% display results
fprintf("The roots of the equation for 'a = 17 are: %g, %g, %g\n\n", roots(1) ,roots(2), roots(3));

% verify with matlab poly function
fprintf("This solution is verified using poly:");
disp(poly(roots));

%% Problem 11.9
clear

disp("*********************" + newline + "Problem 11.9" + newline);

% ************************************************************************
% Part a 
disp("Part a" + newline);

% declare symbolic variable
syms th

% declare equations symbolicly
rA = 1 / (1 - 0.01 * cos(th));
rB = 0.1 / (1 - 0.9 * cos(th));

% find intersection points
solution = solve(rA - rB);

% convert to numerical answer
solution = double(solution);

% display results
fprintf("The intersection points are:\n");
disp(solution(1));
disp(solution(2));
fprintf("Since the intersections are imaginary, the orbits do not intersect.\n\n");

% ************************************************************************
% Part b 
disp("Part b" + newline);
clear

% declare symbolic variable
syms th

% declare equations symbolicly
rA = 1 / (1 - 0.01 * cos(th));
rB = 1.5 / (1 - 0.5 * cos(th));

% find intersection points
solution = solve(rA - rB);

% convert to numerical answer
solution = double(solution);

% find r cordinates
r1 = double(subs(rA, th, solution(1)));
r2 = double(subs(rB, th, solution(2)));

% display results
fprintf("The orbits intersect at (%g, %g)", r1, solution(1));
fprintf(" and (%g, %g).\n\n", r2, solution(2));

%% Problem 11.10
clear

disp("*********************" + newline + "Problem 11.10" + newline);

% ************************************************************************
% Part a
disp("Part a" + newline);

% declare symbolic variable
syms th1 th2

% declare equations symbolicly
eqn1 = 3*cos(th1) + 2*cos(th1 + th2) == 3;
eqn2 = 3*sin(th1) + 2*sin(th1 + th2) == 1;

% evaluate solutions
S = solve(eqn1, eqn2);

% convert to degrees
S1 = double(S.th1) * (180 / pi);
S2 = double(S.th2) * (180 / pi);

% display results
fprintf("The elbow up solution is (%g, %g)\n", S1(1), S2(1));
fprintf("and the elbow down solution is (%g, %g).\n\n", S1(2), S2(2));

% ************************************************************************
% Part b 
disp("Part b" + newline);

% declare symbolic variable
syms th1 th2 x

% declare equations symbolicly
eqn1 = 3*cos(th1) + 2*cos(th1 + th2) == x;
eqn2 = 3*sin(th1) + 2*sin(th1 + th2) == 1;

% evaluate solutions
S = solve(eqn1, eqn2, th1, th2);

% declare x interval
xr = 2:0.01:4;

% create data points for each x in interval
th1r = subs(S.th1, x, xr);
th2r = subs(S.th2, x, xr);

% convert to degrees
th1r = double(th1r) * (180 / pi);
th2r = double(th2r) * (180 / pi);

% plot solutions
subplot(2, 1, 1);
p1 = plot(xr, th1r);
hold on;
grid on;
p2 = plot(3, S1(1), 'ko');
p3 = plot(3, S1(2), 'rx');
xlabel("x (feet)");
ylabel("Theta1 (degrees)");
title("Motor angles vs x");
legend([p2, p3],"elbow up","elbow down", "Location", "northeastoutside");

subplot(2, 1, 2);
p4 = plot(xr, th2r);
hold on;
grid on;
p5 = plot(3, S2(1), 'ko');
p6 = plot(3, S2(2), 'rx');
xlabel("x (feet)");
ylabel("Theta2 (degrees)");
legend([p5, p6],"elbow up","elbow down", "Location", "northeastoutside");

clear
