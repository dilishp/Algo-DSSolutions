def file_index(fileName):
    with open(fileName,'r') as f:
        worddict = {}
        count = 0
        linenolist = []
        for line in f:
            count = count + 1
            for word in line.split():
                linenolist.append(count)
                linenolist = list(dict.fromkeys(linenolist))
                linenolist.sort()
                worddict[word] = linenolist

    return worddict


print(file_index("input.txt"))