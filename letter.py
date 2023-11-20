print('Welcome to letter generator.')
print("\nWhat kind of letter do you need ?")
print("\n1. Formal letter \n2. Informal letter \n3. semi-Formal letter ")
m = int(input('\nEnter your choice: '))

match(m):
 case 1:
    name = input('\nYour name: ')
    address = input('Your address: ')
    date = input('The date: ')
    toname = input("The receiver's name: ")
    toaddress = input("The receiver's address: ")
    topincode = input("The receiver's pincode: ")
    subject = input("Related subject: ")  
    body = input("The body: ")

    f = open('letter.txt', 'w')
    f.write(f'''\n
                From
                {name}
                {address}         
                {date}

                 To
                {toname}
                {toaddress}
                {topincode}   

                 Respected Sir/Madam 

                   Subject: {subject}

                     {body}

                Yours Sincerely.
                   {name}
                   Signature''') 
    f.close()

 case 2:
    name = input('\nYour name: ')
    date = input('The date: ')
    toname = input("The receiver's name: ")
    toaddress = input("The receiver's address: ")
    topincode = input("The receiver's pincode: ")
    greeting = input("Greetings: ") 
    body = input("The body: ")
    f = open('letter.txt', 'w')
    f.write(f'''\n
               To
               {toname}
               {toaddress}
               {topincode}

               {date}

               Dear {toname}

               {greeting}

               {body}

                With Love
               {name}''')
    f.close()

 case 3:
   name = input('\nYour name: ')
   address = input('Your address: ')
   date = input('The date: ')
   toname = input("The receiver's name: ")
   toaddress = input("The receiver's address: ")
   topincode = input("The receiver's pincode: ")
   subject = input("Related subject: ")  
   body = input("The body: ")
   f = open('letter.txt', 'w')
   f.write(f'''\n
                To
                {toname}
                {toaddress}
                {topincode}

                {date}
  
                 Dear {toname}

                 {subject}  

                {body}

                Yours Sincerely.
                {name}
                {address}''')
   f.close()

 case _:
    print('Invalid choice')