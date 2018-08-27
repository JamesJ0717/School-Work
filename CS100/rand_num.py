# 1. greet user
# 2. ask user to input two numbers
# 3. test to see which number is larger
# 4. print results
# 5. end and goodbye

# greeting
print("Hello.")

# number1
number_one = int(input("Please choose a number greater than 0:"))
# number2
number_two = int(input("Please choose a different number greater than 0:"))

if number_one != number_two:
    if number_one > number_two:
        print(number_one, "is greater than", number_two, ".")
    else:
        print(number_two, "is greater than", number_one, ".")
else:
    print("You chose equal numbers. You are not good at following directions.")
