#  1. greet user
#  2. display steps/instructions
#  3. have user insert or swipe card
#  4. have user input pin
#  5. record pin
#  6. check database for matching pin number
#  6a. if pin matches continue
#  6a1. ask user how much money they would like to withdraw
#  6a2.record amount
#  6a3.check with bank if the money is available
#  6a3a.if they have enough money
#  6a3a1. give them the money
#  6a3b. if not
#  6a3b1. tell them they do not have enough money
#  6a3b2. skip to step 7
#  6b. if pin does not match
#  6b1. tell user pin doesnt match
#  6b2. go back to step 5
# 6b2a. after 3rd attempt, skip to step 7
#  7. thank user and end

# greeting
print("Hello. Welcome to this ATM.")

# insert card
print("Please insert and remove your card.")

# input pin
pin = int(input("What is your pin?"))

# checking pin
if (pin == 1234):
    # money time
    money = float(input("How much money do you want?"))

    bank = money + 100000
    # checking with bank
    if (money < bank):

        # print money
        print("Here is your money.")

    else:
        print("You have no money! HA!")
else:
    print("You have the wrong pin.")

# goodbye
print("Good Day.")
