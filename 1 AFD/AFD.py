import sys

def get_token(exp):
    if exp.isdigit():
        return "ENTERO"
    
    if exp == "+":
        return "SUMA"
    elif exp == "++":
        return "INCR"

    splited_exp = exp.split(".")
    if len(splited_exp) == 2 and splited_exp[0].isdigit() and splited_exp[1].isdigit():
        return "REAL"
    
    return "ERROR"

if __name__ == "__main__":
    exp = sys.argv[1]
    token = get_token(exp)
    print("Token:", token)
