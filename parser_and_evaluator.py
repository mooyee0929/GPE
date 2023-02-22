count = 1

while True:
    s = input()
    if(s==''):
        break
    print('case ',count,':')
    try:
        print(eval(s))
    except SyntaxError:
        print('syntactically incorrect')

    print('')
    count +=1