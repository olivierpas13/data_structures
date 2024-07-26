
def counting_sort(arr, exp):
    n = len(arr)
    res = [0] * n
    count = [0] * 10

    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        res[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(n):
        arr[i] = res[i]
    print(arr)

def radix_sort(arr):
    max_value = max(arr)
    exp = 1
    iteration_counter = 0
    while max_value // exp > 0:
        print("Iteracion", iteration_counter)
        counting_sort(arr, exp)
        iteration_counter += 1
        exp *= 10

arr = [170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(arr)
print("Array Ordenado:", arr)