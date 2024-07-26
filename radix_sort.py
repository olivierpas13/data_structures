arr = [123, 24, 89, 177, 290, 991, 1, 100]


# max number -> string to use len -> len to get the number of digits
digits = (len(str(max(arr))))

num = str(123);



print (int(num[2]))

def countingSort(arr, digits):

    length = len(arr)

    container ={
        "0": [],
        "1": [],
        "2": [],
        "3": [],
        "4": [],
        "5": [],
        "6": [],
        "7": [],
        "8": [], 
        "9": [],
    }    
    
    nums = []
    container["0"].append(1)
    for i in range(0, length):
        numAsStr = str(arr[i])
        if len(numAsStr) < digits:
            container["0"].append(arr[i])
        else:
            container[numAsStr[-1]].append(arr[i])

    print(container["0"])
        # index = arr[i] // exp1
        # container[index % 10] += 1


    # for i in range(1, digits+1):
    #     for j in arr:
    #         if len(str(j)) < i:
    #             container["0"].append(j)
    #         else:
    #             container[str(str(j)[-i])].append(j)
    #     arr = []
    #     for k in container:
    #         arr.extend(container[k])
    #         container[k] = []
    # return arr

countingSort(arr, digits)