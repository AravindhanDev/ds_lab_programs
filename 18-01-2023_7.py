facultyArr = []
validField = ['fid', 'name', 'email', 'phone', 'subject']

def render(facultyArr):
    file = open(r"test/faculty.txt", 'w')
    res = ''
    for faculty in facultyArr:
        res += str(faculty['fid']) + "\t\t" + faculty['name'] + "\t\t" + faculty['email'] + "\t\t" + str(faculty['phone']) + "\t\t" + faculty['subject'] + "\n"
    file.write(res)
    file.close()
    
while True:
    print('1) Add Record')
    print('2) Delete Record')
    print('3) Update Record')
    print('4) Display Particular Record')
    print('5) Display All Record')
    print('0) Exit Menu Driven Program')
    choice = int(input("Enter choice "))
    
    if choice == 0: exit(0)

    elif choice == 1:
        fid = int(input("Enter faculty id "))
        name = input("Enter name ")
        email = input("Enter email ")
        phone = int(input("Enter phone "))
        subject = input("Enter subject ")
        facultyObj = {"fid": fid, "name": name, "email": email, "phone": phone, "subject": subject}
        facultyArr.append(facultyObj)
        print("1 Row Added\n")
        render(facultyArr)
        
    elif choice == 2:
        if len(facultyArr) == 0:
            print("No record available\n")
        else:
            index = -1
            field = int(input("Enter id of the faculty "))
            for i in range(0, len(facultyArr)):
                if facultyArr[i]['fid'] == field:
                    index = i
                    break
            if index == -1: print("No such record is available")
            else: facultyArr.pop(index)
            print("1 Row Deleted\n")
            render(facultyArr)

    elif choice == 3:
        if len(facultyArr) == 0:
            print("No record available\n")
        else:
            field = int(input("Enter id of the faculty "))
            updateField = input("Enter field to to updated ")
            if updateField not in validField:
                print(f"{updateField} is not a valid field")
            else:
                value = input(f"Enter {updateField} ")
                for faculty in facultyArr:
                    if faculty['fid'] == field:
                        faculty[updateField] = value
            print("1 Row Updated\n")
            render(facultyArr)

    elif choice == 4:
        if len(facultyArr) == 0:
            print("No such record\n")
        else:
            field = int(input("Enter id of the faculty "))
            for faculty in facultyArr:
                if faculty['fid'] == field:
                    print(faculty, '\n')

    elif choice == 5:
        if len(facultyArr) == 0:
            print("No such record\n")
        else:
            for faculty in facultyArr:
                print(faculty, "\n")

    else:
        print("Enter valid choice\n")
