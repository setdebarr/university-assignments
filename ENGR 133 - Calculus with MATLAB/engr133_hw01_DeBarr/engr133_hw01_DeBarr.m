%% Executes everything
main()

%% Calls the void function for each problem
function main()
    probFive()
    probTwelve()
    probSixteen()
    probTwentySix()
    probTwentyEight()
end

%% Problem 5
function probFive()
    clear

    disp(" ");
    disp("Problem 5");

    % Declare Variables
    a = 1.12;
    b = 2.34;
    c = 0.72;
    d = 0.81;
    f = 19.83;

    % Calculates x
    x = 1 + (a/b) + (c/(f^2));

    % Prints x to terminal
    disp("x = " + x);

    % Calculates s
    s = (b - a)/(d - c);

    % Prints s to terminal
    disp("s = " + s);

    % Calculates r
    r = 1/((1/a) + (1/b) + (1/c) + (1/d));

    % Prints r to terminal
    disp("r = " + r);

    % Calculates y
    y = a * b * (1/c) * ((f^2)/2);

    % Prints y to terminal
    disp("y = " + y);

end
    
%% Problem 12
function probTwelve()
    clear

    disp(" ");
    disp("Problem 12");

    % Declare Variables
    x = -7 - 5i;
    y = 4 + 3i;

    % Calculates a
    a = x + y;

    % Prints a to terminal
    disp("a = " + a);

    % Calculates b
    b = x * y;

    % Prints b to terminal
    disp("b = " + b);

    % Calculates c
    c = x / y;

    % Prints c to terminal
    disp("c = " + c);

end

%% Problem 16
function probSixteen()
    clear

    disp(" ");
    disp("Problem 16");

    % Declare known Variables
    R = 0.08206;
    P = 2.2;
    V = 28500;
    T = -15;

    % Convert V to m^3
    V = V * ((1/3.28)^3);

    % Convert December T to Kelvin
    T = convK(T);

    % Calculate n
    n = (P * V)/(R * T);

    % Convert July T to Kelvin
    T = convK(31);

    % Calculate volume of gas in July
    V = (n * R * T) / P;

    % Convert V to back to ft^3
    V = V * ((3.28/1)^3);

    % Prints the volume to terminal
    disp("The volume of the gas in July is " + V + "ft^3");

    % Convert temperature to Kelvin
    function temp = convK(T)
        temp = T + 273.2;
    end
end

%% Problem 26
function probTwentySix()
    clear

    disp(" ");
    disp("Problem 26");

    % Store coefficients in array
    p = [70, 24, -10, 20];

    % Calculate roots with the roots function
    r = roots(p);

    % Display the roots
    disp(r);

end

%% Problem 28
function probTwentyEight()
    clear

    disp("Problem 28");

    % Define the values or x according to the interval givent in 
    % increments of 0.1
    x = 0:0.1:2;

    % Define u and v vector
    u = 2 * log((60 * x) + 1);
    v = 3 * cos(6 * x);

    % Plot the functions
    plot(x, u, x, v);
    grid on

    % Labels the plot
    xlabel("Distance(miles)");
    ylabel("Speed(mph)");
    legend({"u = 2*log((60*x)+1)","v = 3*cos(6*x)"},"Location","northwest");

    disp("Refer to external figure plot");

end