while(1):
    tri = map(int, input().split())

    tri_list = []

    for i in tri:
        tri_list.append(i)

    a = tri_list[0]
    b = tri_list[1]
    c = tri_list[2]

    if(a == 0 and b == 0 and c == 0):
        exit()
    elif((a*a) + (b*b) == (c*c)):
        print('right')
    elif((b*b) + (c*c) == (a*a)):
        print('right')
    elif((c*c) + (a*a) == (b*b)):
        print('right')    
    else:
        print('wrong')

