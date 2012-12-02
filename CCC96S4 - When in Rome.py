import sys
def printf(format, *args):
    sys.stdout.write(format % args)

def To_decimal(x):
    '''str -> int
    converts a roman number to its decimal equivalent'''
    total = 0
    prev_dig = 1000000    
    for i in range(0, len(x)):
        if x[i] == 'I':
            curr_dig = 1
        elif x[i] == 'V':
            curr_dig = 5
        elif x[i] == 'X':
            curr_dig = 10
        elif x[i] == 'L':
            curr_dig = 50
        elif x[i] == 'C':
            curr_dig = 100
        elif x[i] == 'D':
            curr_dig = 500
        elif x[i] == 'M':
            curr_dig = 1000
        
        total = total + curr_dig
        
        if curr_dig > prev_dig:
            total = total - (2 * prev_dig)
            
        prev_dig = curr_dig
        
    return total

def To_roman(x):
    '''int -> str
    converts a decimal number to its roman equivalent'''
    
    total = ''
    if x > 1000:
        return "CONCORDIA CUM VERITATE"
    if x >= 100:
        if x / 100 == 9:
            total = total + 'CM'
            x = x - 900
        elif x / 100 >= 5:
            total = total + 'D'
            x = x - 500
            total = total + 'C'*(x/100)
            x = x - (x/100) * 100
        elif x / 100 == 4:
            total = total + 'CD'
            x = x-400
        else:
            total = total + 'C'*(x/100)
            x = x - (x/100) * 100

    if x >= 10:
        if x / 10 == 9:
            total = total + 'XC'
            x = x - 90
        elif x / 10 >= 5:
            total = total + 'L'
            x = x - 50
            total = total + 'X'*(x/10)
            x = x - (x/10) * 10
        elif x / 10 == 4:
            total = total + 'XL'
        else:
            total = total + 'X'*(x/10)
            x = x - (x/10) * 10    
            
    if x >= 0:
        if x == 9:
            total = total + 'IX'
        elif x >= 5:
            total = total + 'V'
            x = x - 5
            total = total + 'I'*(x)
        elif x == 4:
            total = total + 'IV'
        else:
            total = total + 'I'*(x)
            
    return total
        
x = raw_input()

for i in range(int(x)):
    roman = raw_input()
    pos = roman.find('+')
    first = roman[:pos]
    second = roman[pos+1:len(roman)-1]
    
    sum = To_roman(To_decimal(first) + To_decimal(second))
    printf ('%s%s\n', roman,  sum)
