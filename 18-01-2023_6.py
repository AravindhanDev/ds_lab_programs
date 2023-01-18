def stringFormat(string):
    newStr = ''
    uppercase = False
    for char in string:
        if uppercase: newStr += char.upper()
        else: newStr += char
        if char == '.': uppercase = True
        else: uppercase = False
    return newStr

def surroundNumbersByBrackets(string):
    newStr = ''
    numberStr = ''
    for char in string:
        if numberStr != '' and char.isdigit() == False:
            newStr += numberStr + ']'
            numberStr = ''
        if char.isdigit():
            if numberStr == '': numberStr = numberStr + '[' + char
            else: numberStr += char
        else: newStr += char
    return newStr

format1 = open(r'test/format1.txt', 'r')
format2 = open(r'test/format2.txt', 'w')
content = format1.read()
result = stringFormat(content)
output = surroundNumbersByBrackets(result)
format2.write(output)
format1.close()
format2.close()
print("Operation successfully")
