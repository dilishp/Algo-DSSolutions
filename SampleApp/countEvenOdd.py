def countNoofEvenandOddNos(list):
    noofEvenNos = 0;
    noofOddNos = 0;
    for element in list:
        if element % 2 == 0:
            noofEvenNos = noofEvenNos + 1
        else:
            noofOddNos = noofOddNos + 1

    print("Noof Even Numbers = ",noofEvenNos);
    print("Noof Odd Numbers = ",noofOddNos);



countNoofEvenandOddNos([1,8,2,3,6,9,4,2,3,6,5])

         
