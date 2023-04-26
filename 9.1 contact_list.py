#Katelyn Choudhari
#Contact list program

#initial message
print(f'Welcome to your contact list.'"\n"
      f'Enter the name,number of three contacts.')

#empty dictionary of contacts
contacts = {}

#gets user input to create contact dictionary
for i in range(3):
    user_contact = input(f"Enter name,number {i + 1}: ")
    #splits key and value
    key, value = user_contact.split(",")
    contacts[key] = value

#gets user input to search contact name
search = input('Which contact name would you like to lookup?: ')

#outputs phone number from search
print(f"{search.capitalize()}'s phone number is {contacts[search]}")