import collections

def add_contact(phoneBookdict):
    name = input('Enter the name of the contact to be added')
    phone = input('Enter the phone of the contact to be added')
    email = input('Enter the email of the contact to be added')
    address = input('Enter the address of the contact to be added')
    #named Tuple
    C = collections.namedtuple('C',['phone','email','address'])
    Contact = C(phone,email,address)

    phoneBookdict[name] = Contact

    print('Contact ',name,' with phone ',phone , ' email ',email,' , and address ',address,' has been added successfully!')

    print('You have ',len(phoneBookdict),' Contact(s) in your phonebook')

def consult_contact(phoneBookdict):
    namein = input('What is the name of the contact ? ')
    valuefield = input('What information do you need ? ')

    Contact = phoneBookdict[namein]

    if len(Contact) == 0:
        print('Contact not found')
    else:
        print(getattr(Contact,valuefield))

    

phoneBookdict = {}

add_contact(phoneBookdict)
add_contact(phoneBookdict)
add_contact(phoneBookdict)
add_contact(phoneBookdict)
add_contact(phoneBookdict)

consult_contact(phoneBookdict)
consult_contact(phoneBookdict)
consult_contact(phoneBookdict)
consult_contact(phoneBookdict)
consult_contact(phoneBookdict)

