%% Problem 10
clear
clc

disp("*********************" + newline + "Problem 10" + newline);

% Declare the given arrays
A = [1, 4, 2; 2, 4, 100; 7, 9, 7; 3, pi, 42];
B = log(A);

% ************************************************************************
% Part a
disp("Part a" + newline);

% Extracts the second row of array B and displays it
row2B = B(2, :);
disp("The second row of B is: ");
disp(row2B);

% ************************************************************************
% Part b
disp("Part b" + newline);

% Uses the second row obtained from part a and then adds them together and 
% displays the value
sumR2B = sum(row2B);
disp("The sum of the second row of B is: " + sumR2B + newline);

% ************************************************************************
% Part c
disp("Part c" + newline);

% Extracts the first column from A and the second column from B
col1A = A(:, 1);
col2B = B(:, 2);

% Multiplies the two columns element-by-element and displays the results
prodC2BC1A = col2B .* col1A;
disp("The product of column 2 of B and column 1 of A is: ");
disp(prodC2BC1A);

% ************************************************************************
% Part d
disp("Part d" + newline);

% Gets and diplays the max value of vector prodC2BC1A
disp("The maximum value from the vector in part c is: " + max(prodC2BC1A));
disp(newline);

% ************************************************************************
% Part e
disp("Part e" + newline);

% Extracts the first row of A and the first three elements of the third
% column of B
row1A = A(1, :);
col3B = [B(1, 3), B(2, 3), B(3, 3)];

% Divides the two vectors using element-by-element division
quotR1AC3B = row1A ./ col3B;

% Adds all the elements in vector quotR1AC3B and displays it
sumquot = sum(quotR1AC3B);
disp("The sum of the vector by dividing the elements of A and B is: " + sumquot);
disp(newline);

%% Problem 13
clear

disp("*********************" + newline + "Problem 13" + newline);

% Declare the given matrices
A = [9, 6; 2, 7];
B = [8, 9; 6, 2];

% ************************************************************************
% Part a
disp("Part a" + newline);

% Adds the two matrices and displays the result
disp("The sum of matrices A and B is:");
disp(A + B);

% ************************************************************************
% Part b
disp("Part b" + newline);

% Multiplies the two matrices and displays the result
w = A .* B;
disp("The array product of matrices A and B. w =");
disp(w);

% ************************************************************************
% Part c
disp("Part c" + newline);

% Multiplies the two matrices and displays the result
z = B .* A;
disp("The array product of matrices A and B. z =");
disp(z);

% Conclusion
disp("Conclusion" + newline);
disp("z and w are equal." + newline);

%% Problem 16
clear

disp("*********************" + newline + "Problem 16" + newline);

% Declare the given matrices
A = [5, 9; 6, 2];
B = [4, 7; 2, 8];

% ************************************************************************
% Part a
disp("Part a" + newline);

% Divides the two matrices and displays the result
C = A ./ B;
disp("The array quotient of matrices A ./ B. C =");
disp(C);

% ************************************************************************
% Part b
disp("Part b" + newline);

% Divides the two matrices and displays the result
D = B ./ A;
disp("The array quotient of matrices B ./ A. D =");
disp(D);

% ************************************************************************
% Part c
disp("Part c" + newline);

% Divides the two matrices and displays the result
E = A .\ B;
disp("The array quotient of matrices A .\ B. E =");
disp(E);

% ************************************************************************
% Part d
disp("Part d" + newline);

% Divides the two matrices and displays the result
F = B .\ A;
disp("The array quotient of matrices B .\ A. F =");
disp(F);

% ************************************************************************
% Part e
disp("Part e" + newline);

disp("C and F are equivalent, and D and E are equivalent." + newline);

%% Problem 19
clear

disp("*********************" + newline + "Problem 19" + newline);

% Define the values of x according to the interval given in 
% increments of 0.01
x = -2:0.01:16;

% Define the values of y according to the function given
y = (4 * cos(x)) ./ (x + exp(-0.75 * x));

% Plot the function
plot(x, y);
grid on

% Labels the plot
xlabel("x");
ylabel("f(x)");
legend("f(x)= 4cos(x) / (x+e^-^0^.^7^5^x)","Location","northeast");

disp("Refer to external figure plot" + newline);

%% Problem 25
clear

disp("*********************" + newline + "Problem 25" + newline);

% Create array for hourly wage
wage = [5 , 5.50, 6.50, 6, 6.25];

% Create array for hours worked
hours = [40, 43, 37, 50, 45];

% Create array for Output(widgets)
widget = [1000, 1100, 1000, 1200, 1100];

% ************************************************************************
% Part a
disp("Part a" + newline);

% Calculates the wage of each worker and displays it in proper currency
% form
disp("Each worker earned the following amounts from worker 1-5:");
disp(cur2str(wage .* hours));
disp(newline);

% ************************************************************************
% Part b
disp("Part b" + newline);

% Calculates the total salary paid out displays it in proper currency
% form
disp("The total salary paid out is: " + cur2str(sum(wage .* hours)));
disp(newline);

% ************************************************************************
% Part c
disp("Part c" + newline);

% Calculates the total widgets made displays it
disp("The total amount of widgets made were: " + sum(widget));
disp(newline);

%% Problem 26
clear

disp("*********************" + newline + "Problem 26" + newline);

% Create vector for location of each diver
dive1 = [-60, -25, 30];
dive2 = [-30, -55, 20];

% ************************************************************************
% Part a
disp("Part a" + newline);

% Calculates distance between diver 1 and starting point
dist1 = sqrt(sum(dive1 .* dive1));
disp("The distance between diver 1 and the starting point is: " + dist1 + "ft");
disp(newline);

% ************************************************************************
% Part b
disp("Part b" + newline);

% Create vector pointing from diver 1 to diver 2
v = dive2 - dive1;

disp("To reach diver 2, diver 1 must swim " + v(1) + "ft west, " + (v(2)*-1) + "ft south, and " + (v(3)*-1) + "ft up.");
disp(newline);

% ************************************************************************
% Part c
disp("Part c" + newline);

% Calculate distance between the divers
dist2 = sqrt(sum(v .* v));
disp("Diver 1 must swim " + dist2 + "ft in a straight line to reach diver 2.");
disp(newline);

%% Problem 28
clear

disp("*********************" + newline + "Problem 28" + newline);

% Create matrix for price per ton of each material
price = [300; 550; 400; 250; 500];

% Create matrix of quantity purchased for May, June, and July
quantity = [5, 4, 6;
            3, 2, 4;
            6, 5, 3;
            3, 5, 4;
            2, 4, 3];
        
% ************************************************************************
% Part a
disp("Part a" + newline);

% Create 5x3 matrix of amounts spent each month
spent = price .* quantity;
disp("The 5x3 matrix containing the amounts spent on each item each month is: ");
disp(spent);

% ************************************************************************
% Part b
disp("Part b" + newline);

% Calculates money spent for each month
disp("The total spent in May is: " + cur2str(sum(spent(:, 1))));
disp("The total spent in June is: " + cur2str(sum(spent(:, 2))));
disp("The total spent in July is: " + cur2str(sum(spent(:, 3))));
disp(newline);

% ************************************************************************
% Part c
disp("Part c" + newline);

disp("The total spent on each material in the three month period from 1-5 is: ");

% Calculates the total spent for each material
disp(cur2str(sum(spent'))); %#ok<UDIM>
disp(newline);

% ************************************************************************
% Part d
disp("Part d" + newline);

% Calculates the total spent on all materials
disp("The total spent on all materials in the three-month period is: " + cur2str(sum(spent(:))));
clear