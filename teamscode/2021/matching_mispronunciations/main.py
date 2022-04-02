t = int(input())
sizes = ['small', 'medium', 'large']

orders = []

for x in range(t):
    orders.append({
        'numofopts': int(input()),
        'opts': [x.lower() for x in input().split(' ')],
        'order': [x.lower() for x in input().split(' ')]
    })

for order in orders:
    endSize = ''
    currentCharWrong = 'Infinity'
    for size in sizes:
        charWrong = 0
        if len(size) != len(order['order'][0]):
            continue
        for sizeCharI in range(len(size)):
            if order['order'][0][sizeCharI] != size[sizeCharI]:
                charWrong += 1
        if currentCharWrong == 'Infinity' or currentCharWrong > charWrong:
            currentCharWrong = charWrong
            endSize = size
    endOrder = ''
    currentCharWrong = 'Infinity'
    for beverage in order['opts']:
        charWrong = 0
        if len(beverage) != len(order['order'][1]):
            continue
        for orderCharI in range(len(beverage)):
            if order['order'][1][orderCharI] != beverage[orderCharI]:
                charWrong += 1
        if currentCharWrong == 'Infinity' or currentCharWrong > charWrong:
            currentCharWrong = charWrong
            endOrder = beverage

    print(endSize, endOrder)
