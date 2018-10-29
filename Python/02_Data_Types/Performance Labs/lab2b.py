"""Python2 lab2b"""
print "==================================="

# TODO: Set x equal to 545
x = 545

# TODO: Set y equal to 24
y = 24

# TODO: Set binX equal to bin representation of x
binX = bin(x)

# TODO: Set binY equal to bin representation of y
binY = bin(y)

print "{} is {} in binary. {} is {} in binary.".format(x, binX, y, binY)

print "Values before modification: x: {} and y: {}".format(x, y)


# TODO: manually flip the third bit in x
x = x ^ (1 << 2)

# TODO: manually flip the 1st bit in y
y = y ^ (1 << 0)

print "Values after modificaiton: x: {} and y: {}".format(x, y)

# NOTE: You may need to add additional re-asignments for the TODOs below
# TODO: sum of x and y as a hex value
answer1 = hex(x + y)

# TODO: difference of x minus y as int
answer2 = x - y

# TODO: product of x and y as octal
answer3 = oct(x * y)

# TODO: quotient of x divided by y as binary
answer4 = bin(x/y)

# TODO: x modulus 3 as int
answer5 = x % 3 

# TODO: y squared as int
answer6 = y ** 2

print "1: {}\n2: {}\n3: {}\n4: {}\n5: {}\n6: {}\n \b===================================".format(answer1, answer2, answer3, answer4, answer5, answer6)

# TODO: Using prefixes and conversions:

## TODO: Set binA == 0011, set binB to 1001
binA = 0b0011
binB = 0b1001

## TODO: binA AND binB, assign the value to binC
binC = binA & binB


## TODO: Set decA to decimal version of binA, set decB to decimal version of binB
decA = int(binA)
decB = int(binB)

## TODO: Set binA to bin representation of binA, set binB to the bin representation of binB
binA = bin(binA)
binB = bin(binB)

print "Results:\n-Decimal- A: {} B: {}\n-Binary- A: {} B: {}".format(decA, decB, binA, binB)