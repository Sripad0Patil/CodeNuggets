# CALCULATOR
a = float(input('Assign a value to A: '))
b = float(input('Assign a value to B: '))

print('\n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Remainder')
z = int(input('\nSelect an Arthmetic operation: '))
match z:
 case 1:
  def add(a, b):
    return(a+b)
  print(add(a, b))
 
 case 2:
   def sub(a, b):
     return(a-b)
   print(sub(a, b)) 
 
 case 3:
   def mult(a, b):
     return(a*b)
   print(mult(a, b))

 case 4:
    def div(a, b):
      return(a/b)
    print(div(a, b))

 case 5:
   def rem(a, b):
     return(a%b)
   print(rem(a, b))
  
 case _:
   print("Invalid choice")

