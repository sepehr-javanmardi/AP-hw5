def test (a, b, c, *args, **kwargs):
    print (f'a =  {a}\nb = {b}\nc = {c}')
    print('the tuple:')
    for arg in args:
        print(f'arg = {arg}')

    print('the dictionary:')
    for key in kwargs:
        print(f'key = {key} and value = {kwargs[key]}')


test (1, 2, 3, '1','2','3', t1=1, t2=2, t3=3)





