while True:
    try:
        line = input()
    except EOFError:
        break

    line = line.split()

    line = [int(i) for i in line]

    for i in range(len(line)):
        result = line.pop(i)
        if result == sum(line):
            print(result)
            break
        line.append(result)
