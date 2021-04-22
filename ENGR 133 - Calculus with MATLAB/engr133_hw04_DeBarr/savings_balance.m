function balance = savings_balance(a, n, r)
% savings_balance determines your account growth over a period of time
    balance = a * ((1 + r / 100).^n);
end

