%% Homework 8
% ENGR 133-003
% Created by Sean DeBarr 3/22/2019
clear
close all
clc

%% Problem T5.1-2
clear

disp("*********************" + newline + "Problem T5.1-2" + newline);

disp("Please refer to external plots");

% plot using fplot
fplot(@(x) tan(cos(x)) - sin(tan(x)), [0, 2 * pi]);
xlabel('0 <= x <= 2pi');
ylabel('tan(cos(x)) - sin(tan(x))');
title('fplot version');


% plot using the plot command
x = 0:0.001:2*pi;

func = @(x) tan(cos(x)) - sin(tan(x));

figure;
plot(x, func(x)); 
xlabel('0 <= x <= 2pi');
ylabel('tan(cos(x)) - sin(tan(x))');
title('plot version');

fprintf("\nWe need %d values of x to obtain the same plot using the plot command.", length(x));
disp(newline);

%% Problem 5.2
clear

disp("*********************" + newline + "Problem 5.2" + newline);

% fixed cost
fixed = 2.045e+6;

% variable costs
material = .62;
energy = .24;
labor = .16;

% quantity
Q = [0:0.01:8] * 1.0e+6;

% selling price
P = ((6e+6 - Q) / 1.1e+6) .* Q;

% cost
cost = fixed + (material + energy + labor) * Q;

% plot
figure;
plot(Q, P, Q, cost);

% label plot
legend("Revenue", "Cost", "Location", "best");
xlabel('Q (millions of gallons)');
ylabel('Revenue and Cost (millions of gallons)');
title('Revenue and Cost vs Price and Quantity');
gtext('Breakeven Point 1');
gtext('Breakeven Point 2');
grid on;

fprintf("Upon analysis of the graph Q is profitable from\n");
fprintf("approximately 0.5 to 4.5 million gallons of product.\n");
fprintf("Q's profit is maximized at approximately 2.5 million gallons of product\n\n");

%% Problem 5.15
clear

disp("*********************" + newline + "Problem 5.15" + newline);

disp("Please refer to external plot");

% declare functions
x = @(t) (10 .* exp(-0.5 .* t)) .* sin(3 .* t + 2);
y = @(t) (7 .* exp(-0.4 .* t)) .* cos(5 .* t - 3);

% plot x value
t = [0:0.01:10];

% plot the functions
figure;
plot(t, x(t), 'r', t, y(t), '--k');
legend("x(t)=10e^-^0^.^5^tsin(3t+2)", "y(t)=7e^-^0^.^4^tcos(5t-3)", "Location", "best");
xlabel("Time (t)");
ylabel("Oscillations[x(t)] and Vibrations[y(t)]");
title("Oscillations and Vibrations over Time");
grid on;
disp(newline);

%% Problem 5.23
clear

disp("*********************" + newline + "Problem 5.23" + newline);

disp("Please refer to external plots");

% declare functions
V = @(r) (4 * pi * r.^3) / 3;
A = @(r) 4 * pi * r.^2;
V2 = @(A) (A.^(3 / 2)) / (6 * sqrt(pi));
R = @(A) sqrt(A / (4 * pi));

% ************************************************************************
% Part a 

% declare r interval
r = [0.1:0.01:100];

% plot volume
figure;
subplot(2,1,1);
loglog(r, V(r));
xlabel("Radius (r)");
ylabel("Volume (V)");
title("Volume vs Radius");
grid on;

% plot area
subplot(2,1,2);
loglog(r, A(r));
xlabel("Radius (r)");
ylabel("Area (A)");
title("Area vs Radius");
grid on;

% ************************************************************************
% Part b

% declare A interval
A2 = [1:0.01:10e+4];

% plot volume
figure;
subplot(2,1,1);
loglog(A2, V2(A2));
xlabel("Surface Area (A)");
ylabel("Volume (V)");
title("Volume vs Surface Area");
grid on;

% plot area
subplot(2,1,2);
loglog(A2, R(A2));
xlabel("Surface Area (A)");
ylabel("Radius (r)");
title("Radius vs Surface Area");
grid on;
disp(newline);

%% Problem 5.24
clear

disp("*********************" + newline + "Problem 5.24" + newline);

disp("Please refer to external plots");

% declare functions
A = @(n, t) 10000 .* ( 1+ (0.035 / n)).^(n .* t);
A2 = @(t) 10000 * exp(0.035 * t);

% declare time interval
t = [0:0.01:20];

% plot the continuously compounded function
figure;
subplot(2,2,1);
plot(t, A2(t));
xlabel("Time (t)[years]");
ylabel("Amount (A)[$]");
title("Continuous compounding interest");
grid on;

% plot the annually compounded function
subplot(2,2,2);
plot(t, A(1,t));
xlabel("Time (t)[years]");
ylabel("Amount (A)[$]");
title("Annually compounding interest");
grid on;

% plot the quarterly compounded function
subplot(2,2,3);
plot(t, A(4,t));
xlabel("Time (t)[years]");
ylabel("Amount (A)[$]");
title("Quarterly compounding interest");
grid on;

% plot the monthly compounded function
subplot(2,2,4);
plot(t, A(12,t));
xlabel("Time (t)[years]");
ylabel("Amount (A)[$]");
title("Monthly compounding interest");
grid on;

% create variables of the difference between continuously 
% compounded and annually, quarterly, and monthly compounding
Diff1 = A2(t )- A(1,t);
Diff4 = A2(t) - A(4,t);
Diff12 = A2(t) - A(12,t);

figure
subplot(3,1,1);
plot(t,Diff1);
grid on;
title('Difference of continuous and annual compounding');

subplot(3,1,2);
plot(t,Diff4);
grid on;
title('Difference of continuous and quarter compounding');

subplot(3,1,3);
plot(t,Diff12);
grid on;
title('Difference of continuous and monthly compounding');

% ************************************************************************
% Part b

% plot the continuous compounding function
figure
subplot(2,2,1);
loglog(t,A2(t));
grid on;
title('Continuous compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the annually compounded function
subplot(2,2,2);
loglog(t,A(1,t));
grid on;
title('Annually compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');
ylim([1e+4 2.2e+4]);

% plot the quarterly compounded function
subplot(2,2,3);
loglog(t,A(4,t));
grid on;
title('Quarterly compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the monthly compounded function
subplot(2,2,4);
loglog(t,A(12,t));
grid on;
title('Monthly compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the continuous compounding function
figure
subplot(2,2,1);
semilogx(t,A2(t));
grid on;
title('Continuous compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the annually compounded function
subplot(2,2,2);
semilogx(t,A(1,t));
grid on;
title('Annually compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');
ylim([1e+4 2.2e+4]);

% plot the quarterly compounded function
subplot(2,2,3);
semilogx(t,A(4,t));
grid on;
title('Quarterly compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the monthly compounded function
subplot(2,2,4);
semilogx(t,A(12,t));
grid on;
title('Monthly compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the continuous compounding function
figure
subplot(2,2,1);
semilogy(t,A2(t));
grid on;
title('Continuous compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the annually compounded function
subplot(2,2,2);
semilogy(t,A(1,t));
grid on;
title('Annually compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');
ylim([1e+4 2.2e+4]);

% plot the quarterly compounded function
subplot(2,2,3);
semilogy(t,A(4,t));
grid on;
title('Quarterly compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');

% plot the monthly compounded function
subplot(2,2,4);
semilogy(t,A(12,t));
grid on;
title('Monthly compounding interest');
xlabel('Time (t)[years]');
ylabel('Amount (A)[$]');


fprintf('\nThe semilogy plot function gives a linear plot.\n');
