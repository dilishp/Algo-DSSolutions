
def reverse(string):
    str = ''

    for i in string:
        str = i + str

    return str

def main():
   count = int(input("How many words would you like to turn backwards : "))

   lst = []

   for num in range(count):
       lst.append(str(input("Please enter string # " + str(num + 1) + " : ")))

   string = lst.pop()
   while string:
       print("The String \"" + string +"\" reversed is " + reverse(string))
       string = ''
       if len(lst) != 0:
            string = lst.pop()


main()
