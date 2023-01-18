contactArr = []
validField = ['name', 'phone']

def render(contactArr):
    file = open(r"test/phoneDirectory.txt", 'w')
    res = ''
    for contact in contactArr:
        res += contact['name'] + "\t\t" + str(contact['phone']) + "\n"
    file.write(res)
    file.close()
    
while True:
    print('1) Add Contact')
    print('2) Delete Contact')
    print('3) Update Contact')
    print('4) Search Contact Based on Name ')
    print('5) Display All Record')
    print('0) Exit Menu Driven Program')
    choice = int(input("Enter choice "))
    
    if choice == 0: exit(0)

    elif choice == 1:
        name = input("Enter name ")
        phone = int(input("Enter phone "))
        contactObj = {"name": name, "phone": phone}
        contactArr.append(contactObj)
        print("1 Row Added\n")
        render(contactObj)
        
    elif choice == 2:
        if len(contactArr) == 0:
            print("No contact available\n")
        else:
            index = -1
            name = input("Enter name of the contact ")
            for i in range(0, len(contactArr)):
                if contactArr[i]['name'] == name:
                    index = i
                    break
            if index == -1: print("No such record is available")
            else: contactArr.pop(index)
            print("1 Contact Deleted\n")
            render(contactArr)

    elif choice == 3:
        if len(contactArr) == 0:
            print("No contact available\n")
        else:
            name = input("Enter name of the contact ")
            value = input(f"Enter phone ")
            for contact in contactArr:
                if contact['name'] == name:
                    contact[phone] = value
            print("1 Contact Updated\n")
            render(contactArr)

    elif choice == 4:
        if len(contactArr) == 0:
            print("No such contact\n")
        else:
            name = input("Enter name of the contact ")
            for contact in contactArr:
                if contact['name'] == name:
                    print(contact, '\n')

    elif choice == 5:
        if len(contactArr) == 0:
            print("No such contact\n")
        else:
            for contact in contactArr:
                print(contact, "\n")

    else:
        print("Enter valid choice\n")
