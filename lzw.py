def compress(uncompressed):
    """Compress a string to a list of output symbols."""

    # Build the dictionary.
    dict_size = 256
    dictionary = dict((chr(i), chr(i)) for i in range(dict_size))
    # in Python 3: dictionary = {chr(i): chr(i) for i in range(dict_size)}

    w = ""
    result = []
    for c in uncompressed:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            result.append(dictionary[w])
            # Add wc to the dictionary.
            dictionary[wc] = dict_size
            dict_size += 1
            w = c

    # Output the code for w.
    if w:
        result.append(dictionary[w])
    return result



def decompress(compressed):
    """Decompress a list of output ks to a string."""

    # Build the dictionary.
    dict_size = 256
    dictionary = dict((chr(i), chr(i)) for i in range(dict_size))
    # in Python 3: dictionary = {chr(i): chr(i) for i in range(dict_size)}

    w = result = compressed.pop(0)
    for k in compressed:
        if k in dictionary:
            entry = dictionary[k]
        elif k == dict_size:
            entry = w + w[0]
        else:
            raise ValueError('Bad compressed k: %s' % k)
        result += entry

        # Add w+entry[0] to the dictionary.
        dictionary[dict_size] = w + entry[0]
        dict_size += 1

        w = entry
    return result


def main():
    readFile = open("lzwInput.txt","r+")
    message = readFile.readline()
    readFile.close()

    writeFile = open("lzwOutput.txt","w")

    writeFile.write('\nCompressed Message: ')
    compressed = compress(message)
    for code in compressed:
        writeFile.write(str(code))
        writeFile.write(', ')

    
    writeFile.write('\nDecompressed Message: ')
    decompressed = decompress(compressed)
    for code in decompressed:
        writeFile.write(str(code))
        writeFile.write(', ')

    writeFile.close()


if __name__ == '__main__':
    main()