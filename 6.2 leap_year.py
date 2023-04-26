#Katelyn Choudhari
#leapyear calculator

user_year = input("Enter a year: ")

def days_in_feb (user_year):
    if (int(user_year) % 4 == 0):
    
        if (int(user_year) % 100 == 0) and (int(user_year) % 400 == 0):
            leap_year = "has 29 days in February"
            return leap_year

        elif (int(user_year) % 100 != 0):
            leap_year = "has 29 days in February"
            return leap_year
        else:
            leap_year = "has 28 days in February"
            return leap_year
    else:
            leap_year = "has 28 days in February"
            return leap_year

leap_year = days_in_feb (user_year)
print (user_year, leap_year)