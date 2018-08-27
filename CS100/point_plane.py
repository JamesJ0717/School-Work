# Coordiante Plane by James Johnson
# 1. greet user
# 2. ask user for coordinates
# 3. store users input
# 4. determine where on the plane the point is
# 4a. quadrant 1 is +x, +y
# 4b. quadrant 2 is +x, -y
# 4c. quadrant 3 is -x, -y
# 4d. quadrant 4 is -x, +y
# 5. display results

# greeting
print("Hello and Thank you for using my program.")

# coordinates
point_x = int(input("Please choose an 'X' coordinate: "))
point_y = int(input("Please choose a 'Y' coordinate: "))

# what quadrant
if point_x > 0 and point_y > 0:
    print("Your point (", point_x, ",", point_y, ") is in quadrant one.", sep='')
elif point_x > 0 and point_y < 0:
    print("Your point (", point_x, ",", point_y, ") is in quadrant two.", sep='')
elif point_x < 0 and point_y < 0:
    print("Your point (", point_x, ",", point_y, ") is in quadrant three.", sep='')
elif point_x < 0 and point_y > 0:
    print("Your point (", point_x, ",", point_y, ") is in quadrant four.", sep='')
elif point_x == 0 and point_y == 0:
    print("Your point (", point_x, ",", point_y, ") is at the origin.", sep='')
elif point_x == 0 and point_y > 0:
    print("Your point (", point_x, ",", point_y, ") is on the x-axis on the",
          " right side of the y-axis.", sep='')
elif point_x == 0 and point_y < 0:
    print("Your point (", point_x, ",", point_y, ") is on the x-axis on the",
          " left side of the y-axis.", sep='')
elif point_x > 0 and point_y == 0:
    print("Your point (", point_x, ",", point_y, ") is on the y-axis north of",
          " the x-axis.", sep='')
elif point_x < 0 and point_y == 0:
    print("Your point (", point_x, ",", point_y, ") is on the y-axis south of",
          " the x-axis.", sep='')
else:
    print("Your point is not on the Cartesian plane.")

#end and farewell
print("Thank you for using my program. Have a good day.")
