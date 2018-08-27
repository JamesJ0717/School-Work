# 1. greet user
# 2. display what the program does
# 3. ask the user for an age
# 4. store the users input
# 5. categorize the persons age
#    5a. if age < 1
#        5aa. infant
#    5b. if 1 < age < 13
#        5bb. child
#    5c. if 13 < age < 20
#        5cc. teenager
#    5d. if age > 20
#        5dd. adult
# 6. display category to user
# 7. end

# 1.greeting
# 2.programs intent
print("Hello. This is a categorizing program meant for ages.")

# 3. ask user for age
# 4. store user input
age = int(input("What is the subjects age?"))

# 5. categorizing
# 6. displaying
if age <= 1:
    print("The subject is an infant.")
elif 1 < age < 13:
    print("The subject is a child.")
elif 13 <= age < 20:
    print("The subject is a teenager.")
elif 20 <= age < 100:
    print("The subject is an adult.")
else:
    print("The subject should be dead.")

# 7. ending
print("Thanks for using my program. Have a good day!")
