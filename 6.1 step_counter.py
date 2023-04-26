#Katelyn Choudhari
# A step counter

#user enters feet walked
user_feet = float(input("Enter the number of feet walked: "))

#function gets user input and calculatues
#the steps walked for the nmbr of feet walked
#and prints steps walked
def feet_to_steps (user_feet):

    steps_walked = (user_feet // 2.5)

    print (int(steps_walked))

#calls the function
feet_to_steps(user_feet)