#Sum of Numbers, James Johnson
#1. greet user
print("Hello User!")

#2. ask user to enter a series of positive numbers
        #2a. the series should end with a negative number
#3. store users input
series = []
numberSeries = int(input("Please enter a series of positive numbers" \
                " with the last number in the series being negative."))
for i in range(100):
    moreNumbers = int(input("Keep going: "))
    if moreNumbers < 0:
        break;
    series.append(moreNumbers)

#4. calculate sum
sumNumberSeries = 0
for i in series:
    sumNumberSeries += i
print(sumNumberSeries)

##5. display sum of the series
print("The sum of the series," ,series, "is", sumNumberSeries,".")

##6. end
print("Hope you enjoyed using my program! Have a good day!")