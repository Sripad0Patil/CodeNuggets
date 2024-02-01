'''
mean = sum of elements / n(number of elements)

median 1. if n is odd  median(X) = X(n+1/2), here X is ordered list of elements
       2. if n is even median(X) = X(n/2) + X((n/2)+1) 

mode = l + ((f1-f0)/(2f1-f0-f2)) * h   where, h - element size, f - ferquency of occurrence, l - lower element

variance = (∈(xi - mean)**2)/n  square sum of all 0 to n-1 diff of Xi-mean divided by n

Standard devitaion = variance**0.5  sqrt of variance 
                                              
'''



def cal_mean(numbers):
    return sum(numbers)/len(numbers)

def cal_median(numbers):
    sorted_numbers=sorted(numbers)
    n = len(sorted_numbers)
    mid = n//2
    if n%2:
        return (sorted_numbers[mid-1]+sorted_numbers[mid])/2
    else:
        return (sorted_numbers[mid])
    
def cal_mode(numbers):
    fer_dict = {}
    for num in numbers:
        if num in fer_dict:
            fer_dict[num] +=  1
        else:
            fer_dict[num] = 1

    max_fer = max(fer_dict.values())
    mode = [num for num, freq in fer_dict.items() if freq == max_fer ]   

def cal_variance(numbers, mean):
    sq_diff = [(x-mean)**2 for x in numbers]
    return sum(sq_diff)/len(numbers)

def cal_standard_deviation(variance):
    return variance**0.5

try:
    n = int(input("Enter number of integers: "))
except ValueError:
    print("Invalid input")
    exit()
  
try:
    num = [int(input(f"Enter numbers #{i+1}: ")) for i in range(n)]
except ValueError:
    print("Invalid input")
    exit()

mean = cal_mean(num)
print(f"Mean: {mean}")

median = cal_median(num)
print(f"Medain: {median}")

mode  = cal_mode(num)
print(f"Mode: {mode}")

variance = cal_variance(num, mean)
print(f"Variance: {variance}")

SD = cal_standard_deviation(variance)
print(f"Standard Deviation: {SD}")


