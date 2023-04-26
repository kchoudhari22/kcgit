#Katelyn Choudhari

#Student records/grades program

#gets file name from user
tsv_file = input("Enter the file name: ")

#opens and reads user file
with open(tsv_file,'r') as f:
    #writes to new text file
    with open('report.txt','w') as file:
        exam1_average = 0
        exam2_average = 0
        final_average = 0  
        length = 0 
        for x in f:
            #splits the info
            last,first,exam1,exam2,final = x.split()
            
            #gets total average of exams for each student
            exam1_average += int(exam1)
            exam2_average += int(exam2)
            final_average += int(final)
            length += 1
            exam1, exam2, final = int(exam1), int(exam2), int(final)
            average = (exam1 + exam2 + final) / 3

            #outputs name, exams, and letter grade based on average of exams 
            if average >= 90:
                grade = (f'{last:<8}\t{first:<8}\t{exam1:<4}\t{exam2:<4}\t{final:<4}\t A')
            elif average >=80:
                grade = (f'{last:<8}\t{first:<8}\t{exam1:<4}\t{exam2:<4}\t{final:<4}\t B')
            elif average >=70:
                grade = (f'{last:<8}\t{first:<8}\t{exam1:<4}\t{exam2:<4}\t{final:<4}\t C')
            elif average >=60:
                grade = (f'{last:<8}\t{first:<8}\t{exam1:<4}\t{exam2:<4}\t{final:<4}\t D')
            else:
                grade = (f'{last:<8}\t{first:<8}\t{exam1:<4}\t{exam2:<4}\t{final:<4}\t F')

            #writes average of all students exams to new text file
            file.write(grade + "\n")
        file.write(f'Averages: Midterm1 {exam1_average/length:.2f}, Midterm2 {exam2_average/length:.2f}, Final {final_average / length:.2f}')

