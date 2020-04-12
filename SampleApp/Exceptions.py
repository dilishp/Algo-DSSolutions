
class InvalidCommand(Exception):
    pass

def validate_input(string):
    """
    If string is a valid command, return its name and arguments.
    If string is not a valid command, raise InvalidCommand
    Valid commands:
    add x y
    sub x y
    mul x y
    div x y
    Parameters:
    string(str): a valid command (see above)

    Return:
    tuple<str, list<float>>: the command and its corresponding arguements

    Precondition:
    Arguments x and y must be convertable to float.
  
    """
    command = string.split();
    if((command[0] == "add") or (command[0] == "sub") or (command[0] == "mul")
       or (command[0] == "div")):
        print("Valid Commmand")
    else:
        raise InvalidCommand

    try:
        arg1 = float(command[1])
        arg2 = float(command[2])
    except ValueError:
        raise InvalidCommand

    return (command[0],[arg1,arg2])


print(validate_input("add 2.1 3.2"))
                             
