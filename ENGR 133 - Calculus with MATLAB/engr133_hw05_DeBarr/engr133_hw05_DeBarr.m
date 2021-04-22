%% Homework 5
% ENGR 133-003
% Created by Sean DeBarr 2/21/2019
clear
clc

%% Problem 2
clear

disp("*********************" + newline + "Problem 2" + newline);

% ************************************************************************
% Part a

% 1. Enter the values a, b, and c.
% 2. Compute the roots both plus and minus
% 3. Display the results real and imaginary

% ************************************************************************
% Part b

quadP = @(a,b,c) ((-b + sqrt((b.^2) - ( 4 * a * c))) / (2 * a));
quadM = @(a,b,c) ((-b - sqrt((b.^2) - ( 4 * a * c))) / (2 * a));

disp("The roots for a = 2, b = 10, and c = 12 is: " + quadP(2,10,12) + " and " + quadM(2,10,12));
disp("The roots for a = 3, b = 24, and c = 48 is: " + quadP(3,24,48) + " and " + quadM(3,24,48));
disp("The roots for a = 4, b = 24, and c = 100 is: " + quadP(4,24,100) + " and " + quadM(4,24,100) + newline);


%% Problem 6
clear

disp("*********************" + newline + "Problem 6" + newline);

% Declare known arrays
x = [10, -2, 6, 5, -3];
y = [9, -3, 2, 5, -1];

% ************************************************************************
% Part a
disp(newline + "Part a" + newline);

% Do logical comparison
z = (x < 6);
disp("The logical comparison of x < 6 is: ");
disp(z);

% ************************************************************************
% Part b
disp(newline + "Part b" + newline);

% Do logical comparison
z = (x <= y);
disp("The logical comparison of x <= y is: ");
disp(z);

% ************************************************************************
% Part c
disp(newline + "Part c" + newline);

% Do logical comparison
z = (x == y);
disp("The logical comparison of x == y is: ");
disp(z);

% ************************************************************************
% Part d
disp(newline + "Part d" + newline);

% Do logical comparison
z = (x ~= y);
disp("The logical comparison of x ~= y is: ");
disp(z);

%% Problem 7
clear

disp("*********************" + newline + "Problem 7" + newline);

% Declare known arrays
x = [-3, 0, 0, 2, 6, 8];
y = [-5, -2, 0, 3, 4, 10];

% Find all elements in x greater than y
z = (x > y);
disp("The elements in x greater than the corresponding element in y are: ");
disp(z);

%% Problem 8
clear

disp("*********************" + newline + "Problem 8" + newline);

% Declare known arrays
price = [19, 18, 22, 21, 25, 19, 17, 21, 27, 29];

% Check to see if the price was over 20
z = (price > 20);

% Calculate how many days the price was over 20
days = sum(z);
disp("The price was over $20 for " + days + " days." + newline);

%% Problem 9
clear

disp("*********************" + newline + "Problem 9" + newline);

% Declare known arrays
price_A = [19, 18, 22, 21, 25, 19, 17, 21, 27, 29];
price_B = [22, 17, 20, 19, 24, 18, 16, 25, 28, 27];

% Find all elements in price_A greater than price_B
z = (price_A > price_B);

% Calculate how many days price_A was greater than price_B
days = sum(z);
disp("The price of stock A was greater than stock B for " + days + " days." + newline);

%% Problem 10
clear

disp("*********************" + newline + "Problem 10" + newline);

% Declare known arrays
price_A = [19, 18, 22, 21, 25, 19, 17, 21, 27, 29];
price_B = [22, 17, 20, 19, 24, 18, 16, 25, 28, 27];
price_C = [17, 13, 22, 23, 19, 17, 20, 21, 24, 28];

% ************************************************************************
% Part a
disp("Part a" + newline);

% Find all elements in price_A greater than price_B and price_C
a = ((price_A > price_B) & (price_A > price_C));

days1 = sum(a);
disp("The price of stock A was greater than stock B and stock C for " + days1 + " days.");

% ************************************************************************
% Part b
disp(newline + "Part b" + newline);

% Find all elements in price_A greater than price_B or price_C
b = ((price_A > price_B) | (price_A > price_C));

days2 = sum(b);
disp("The price of stock A was greater than stock B or stock C for " + days2 + " days.");

% ************************************************************************
% Part c
disp(newline + "Part c" + newline);

% Find all elements in price_A exclusively greater than price_B or price_C
c = (price_A > price_B); 
d = (price_A > price_C);
e = xor(c,d);

days3 = sum(e);
disp("The price of stock A was exclusively greater than stock B or stock C for " + days3 + " days.");
clear
