file = open(r"test/lines.txt", "r")
lines = file.read()
lineArr = lines.split("\n")
for line in lineArr:
    if "print" in line:
        print(line)
