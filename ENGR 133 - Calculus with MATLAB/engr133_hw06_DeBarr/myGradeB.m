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



