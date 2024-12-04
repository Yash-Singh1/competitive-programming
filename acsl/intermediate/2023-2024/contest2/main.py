import re

def encodeMessage(text, message):
    encoded = ""
    lastdigit = False
    sentences = list(map(lambda sentence: list(map(lambda word: list(word), filter(lambda word: len(word) > 0, re.split('[^A-Za-z0-9]', sentence)))), re.split('[?!.]  ', text)))
    print(sentences)
    RE = re.compile('[A-Za-z0-9]')
    occur = 1
    for i, char in enumerate(message):
        if RE.match(char):
            if lastdigit:
                encoded += ' '
            found = (-1, -1, -1)
            occurr = occur
            while found[0] == -1:
                c = 0
                for i in range(len(sentences)):
                    for j in range(len(sentences[i])):
                        for k in range(len(sentences[i][j])):
                            if sentences[i][j][k] == char:
                                c += 1
                            print(c, occurr)
                            if c == occurr:
                                found = (i + 1, j + 1, k + 1)
                                break
                        if found[0] != -1:
                            break
                    if found[0] != -1:
                        break
                if found[0] == -1:
                    occurr = int(occurr / 2)
            encoded += str(found[0]) + '.' + str(found[1]) + '.' + str(found[2])
            occur += 1
            lastdigit = True
        else:
            encoded += '_' if char == ' ' else char
            lastdigit = False
    return encoded

def main():
    with open('input.txt', 'r') as file:
        text = file.readline().strip()
        message = file.readline().strip()
        print(encodeMessage(text, message))

main()
