#Katelyn Choudhari
#Car wash service program

#sets value to base wash
base_wash = 10

#dictionary of services
services = {'Tire shine': 2, 'Wax': 3, 'Rain repellent': 2}

#prints a welcome message and menu of services
#for the user to select from
print('Welcome to ZyCar Wash! Here is a quick menu of our services:'"\n"
     f'Base car wash - ${base_wash}'"\n"
     f'Services: Tire shine $2, Wax $3, Rain repellent $2'"\n"
     f'Input the - symbol if only one or no services are needed.')

#creates a list of services
#based on user choice(s)
user_services = []

#gets user input
for i in range(2):
    service = input(f"Enter Service: ")
#if the service is not a dash
#append chosen service(s) to list
    if service != '-':
        user_services.append(service)

#calculates total price of
#services chosen with base price
total_price = base_wash
for service in user_services:
    total_price += services[service]

#outputs itemized receipt of
#services and total price
print('ZyCar Wash\n'
        f'Base car wash - ${base_wash}')
for service in user_services:
      print(f"{service.title()} - ${services[service]}")
print(f'-----\n'
        f'Total price: ${total_price}')