books = int(input())
bookTitlesAndYear = []

for i in range(books):
    inputGiven = input()
    bookTitlesAndYear.append({'title': inputGiven.split(
        ' ')[0], 'year': int(inputGiven.split(' ')[1])})


def group(arr, func):
    result = {}
    for val in arr:
        functionResult = func(val)
        if functionResult not in result:
            result[functionResult] = []
        result[functionResult].append(val)
    return result


for item in [item for sublist in list(map(lambda entry: sorted(list(entry[1]), key=lambda key: key['year']), sorted(list(group(bookTitlesAndYear, lambda book: book['title'][0]).items()), key=lambda key: key[0])))
             for item in sublist]:
    print(item['title'])
