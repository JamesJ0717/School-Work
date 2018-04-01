#1. greet user
#2. ask user for dimenions of two rectangles
    #2a. rectangle_1_length
    #2b. rectangle_1_width
    #2c. rectangle_2_length
    #2d. rectangle_2_width
#3. store users data
#4. equate rectangle_1 area
#5. equate rectangle_2 area
#6. compare areas
    #6a. if area_rectangle_1 > area_rectangle_2
        #6a. tell user
    #6b. elif area_rectangle_1 = area_rectangle_2
        #6b. tell user
    #6c. else
        #6c. tell user
#7. end

#greeting
print("Hello. This is an area comparision program.")

#dimensions and storing of data
rectangle_1_length = float(input("Please give me a length of a side of Rectangle 1:"))
rectangle_1_width = float(input("Please give me a width of a side of Rectangle 1:"))
rectangle_2_length = float(input("Please give me a length of Rectangle 2:"))
rectangle_2_width = float(input("Please give me a width of Rectangle 2:"))

#areas
#area of a rectangle = length * width
area_A = rectangle_1_length * rectangle_1_width
area_b = rectangle_2_length * rectangle_2_width

#comparison
if area_A > area_b:
    print("The area of Rectangle 1, ",format(area_A, ',.2f')," square inches, is larger than the area of Rectangle 2, ", \
        format(area_b, ',.2f')," square inches.", sep='')
elif area_A == area_b:
    print("The area of Rectangle 1, ",format(area_A, ',.2f')," square inches, is equal to the area of Rectangle 2, ", \
        format(area_b, ',.2f')," square inches.", sep='')
else:
    print("The area of Rectangle 1, ",format(area_A, ',.2f')," square inches, is less than the area of Rectangle 2, ", \
        format(area_b, ',.2f')," square inches.", sep='')

#ending
print("Thank you for using my program. Good bye.")
