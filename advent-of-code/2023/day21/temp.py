num = [[196, 33665], [327, 93356], [458, 182843], [589, 302126]]
for numi in num:
    numi[0] = numi[0] - 65
    numi[0] /= 131
    print(str(numi[0]**2) + "a+" + str(numi[0])+"b+c="+str(numi[1]))

