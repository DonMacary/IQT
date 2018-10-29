def fizzbuzz_condensed2():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15 
    on multiples of 3 and 5 Condensed to one line!
    """
    #This uses conditional logic in line, allowing us to measure by
    #index and element number!
    print "Fizz Buzz in one line!"
    for x in xrange(1,101):print('{}:'.format(x)+'Fizz'*(x%3==0)
                                +'Buzz'*(x%5==0))
