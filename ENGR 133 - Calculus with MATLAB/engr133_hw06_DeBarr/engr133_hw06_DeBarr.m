%% Homework 6
% ENGR 133-003
% Created by Sean DeBarr 2/26/2019
clear
clc

%% Problem 12
clear

disp("*********************" + newline + "Problem 12" + newline);

% Declare known variables
A = 30*pi/180;
v0 = 40;
g = 9.81;

% calculate time to hit surface
t_hit = 2 *(v0 / g) * sin(A);

% make time vector from 0 to the time to hit surface
t = 0:t_hit/100:t_hit;

% Calculate height
h = v0 .* t .* sin(A) - 0.5 .* g .* (t.^2);

% Calculate velocity
v = sqrt((v0.^2) - 2 .* v0 .* g .* sin(A) .* t + (g.^2) .* (t.^2));

% ************************************************************************
% Part a 
disp("Part a" + newline);

% find values of h >= 15
x = find(h >= 15);

% calulate the times
t1a = (x(1) - 1) * (t_hit / 100);
t2a = x(length(x) - 1) * (t_hit / 100);

% display results
fprintf('The times between which the height is no less than 15 m are\n');
TA = [num2str(t1a), 's and ', num2str(t2a), 's'];
disp(TA);
disp(newline);

% ************************************************************************
% Part b
disp("Part b" + newline);

% find values of h >= 15 and v <= 36
y = find(h >= 15 & v <= 36);

% calulate the times
t1b = (y(1) - 1) * t_hit / 100;
t2b = y(length(y) - 1) .* (t_hit / 100);

% display results
fprintf('The times between which the height is no less than 15 m\n');
fprintf('and speed is simultaneously no greater than 36 m/s are:\n');
TB = [num2str(t1b), 's and ', num2str(t2b), 's'];
disp(TB);
disp(newline);

% ************************************************************************
% Part c
disp("Part c" + newline);

% find values of h < 5 or v > 35
z = find(h < 5 | v > 35);

% calulate the times
t1c = (z(1) - 1) * t_hit / 100;
t2c = z(length(z) - 1) .* (t_hit / 100);

% display results
fprintf('The times between which the height is less than 5 m\n');
fprintf('or the speed is greater than 35 m/s are:\n');
TC = [num2str(t1c), 's and ', num2str(t2c), 's'];
disp(TC);
disp(newline);

%% Problem 16
clear

disp("*********************" + newline + "Problem 16" + newline);

%{
function y = prob16(x)
% calculate y depending on the value of x
if x < -1
    y = exp(x + 1);
elseif x >= -1 && x < 5
    y = 2 + cos(pi * x);
else
    y = 10 * (x - 5) + 1;
end
%}

% declare test cases
TC1 = prob16(-5);
TC2 = prob16(3);
TC3 = prob16(15);

% display results
fprintf('When x = -5, y = %d\n', TC1);
fprintf('When x = 3, y = %d\n', TC2);
fprintf('When x = 15, y = %d\n', TC3);
disp(newline);

%% Problem 18
clear

disp("*********************" + newline + "Problem 18" + newline);

% ************************************************************************
% Part a 
disp("Part a" + newline);

%{
function grade = myGradeA(x)
% accepts an x value between 0-100 
% and returns grade using only nested if statements
if (x > 0) && (x <= 100)
   if x >= 90
        grade = 'A';
   end
        if (x <= 89)&& (x >= 80)
            grade = 'B';
        end
            if (x <= 79)&& (x >= 70)
                grade = 'C';
            end
                if (x <= 69)&& (x >= 60)
                    grade = 'D';
                end
                    if x < 60
                        grade = 'F';
                    end
end
end
%}

% create test cases
TC1 = myGradeA(55);
TC2 = myGradeA(65);
TC3 = myGradeA(75);
TC4 = myGradeA(85);
TC5 = myGradeA(95);

% display results
fprintf("Your grade when your score is 55 is a %s\n", TC1);
fprintf("Your grade when your score is 65 is a %s\n", TC2);
fprintf("Your grade when your score is 75 is a %s\n", TC3);
fprintf("Your grade when your score is 85 is a %s\n", TC4);
fprintf("Your grade when your score is 95 is a %s\n", TC5);
disp(newline);
clear

% ************************************************************************
% Part b
disp("Part b" + newline);

%{
function grade = myGradeB(x)
% accepts an x value between 0-100 
% and returns grade using only elseif statements
if x >= 90
    grade = 'A';
elseif (x <= 89)&& (x >= 80)
    grade = 'B';
elseif (x <= 79)&& (x >= 70)
    grade = 'C';
elseif (x <= 69)&& (x >= 60)
    grade = 'D';
elseif x < 60
    grade = 'F';
end
end
%}

% create test cases
TC1 = myGradeB(55);
TC2 = myGradeB(65);
TC3 = myGradeB(75);
TC4 = myGradeB(85);
TC5 = myGradeB(95);

% display results
fprintf("Your grade when your score is 55 is a %s\n", TC1);
fprintf("Your grade when your score is 65 is a %s\n", TC2);
fprintf("Your grade when your score is 75 is a %s\n", TC3);
fprintf("Your grade when your score is 85 is a %s\n", TC4);
fprintf("Your grade when your score is 95 is a %s\n", TC5);
disp(newline);

%% Problem 21
clear

disp("*********************" + newline + "Problem 18" + newline);

%{
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
%}

% create test cases
TC1 = fxy(2, 2);
TC2 = fxy(2, -2);
TC3 = fxy(-4, 4);
TC4 = fxy(-4, -4);

% display results
fprintf("When x = 2 and y = 2, f(x,y) = %d\n", TC1);
fprintf("When x = 2 and y = -2, f(x,y) = %d\n", TC2);
fprintf("When x = -4 and y = 4, f(x,y) = %d\n", TC3);
fprintf("When x = -4 and y = -4, f(x,y) = %d\n", TC4);
disp(newline);
clear