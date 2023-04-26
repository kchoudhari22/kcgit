low_num = int (input ("What is your low number?"))

high_num = int (input ("What is your high number?"))

x = int (input ("What is your x number?"))

count = 0

for i in range (low_num,high_num + 1,1):

    if i % x == 0:

        count += 1

print (count)
