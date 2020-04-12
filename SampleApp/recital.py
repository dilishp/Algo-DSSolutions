lst = []
number = int(input('Enter an integer number : '))
#add to the list if the number is not -1 and in the range 1 to 10
if number != -1 and number in range(1,10):
    lst.append(number)
#Continue till user enters -1
while number != -1:
    number = int(input('Enter next : '))
    if(number in range(1,10)):
        lst.append(number)

print('The list is : ',*lst)
