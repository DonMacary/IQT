
def fizzbuzz_elegant():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15 
    on multiples of 3 and 5. Uses 2 if statements within a for loop
    """
    #Improved solution, uses a variable to track the string.
    #Removes the need for a third if statement and no elses!
    print "Fizz Buzz in For loop!"
    for i in xrange(1,101):
        text = "{}: ".format(i)
        if i % 3 == 0:
            text += "Fizz"
        if i % 5 == 0:
            text += "Buzz"
        print text

