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

