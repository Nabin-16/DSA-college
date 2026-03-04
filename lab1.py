def PostFix(expression):
    exp_list = []
    split_Expression = expression.split()
    print(split_Expression)
    for character in split_Expression:
        if character == "+" or character == "-" or character == "*" or character == "/":
            operand2 = exp_list.pop()
            operand1 = exp_list.pop()
            if character == "+":
                result = operand1 + operand2
            if character == "-":    
                result = operand1 - operand2
            if character == "*":
                result = operand1 * operand2
            if character == "/":
                result = operand1 / operand2
            exp_list.append(result)
        else:
            exp_list.append(int(character))
        # print("Appended result:")
        # print(exp_list)
    return exp_list[0]


def postfix():
    Inp_expression = input("Enter the postfix expression:")
    Result = PostFix(Inp_expression)
    print(f"The result is {Result}")


postfix()