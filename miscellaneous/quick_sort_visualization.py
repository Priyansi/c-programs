def print_array(arr, low, high):
    for i in range(low, high+1):
        print(arr[i], end=" ")
    print("\n")


def partition(arr, low, high):
    i = low
    j = high
    pivot = arr[low]
    print(f"Quicksort on this array : ")
    print_array(arr, low, high)
    print(f"Pivot selected : {pivot}")
    while i < j:
        print(f"Lower index moved from : {i}", end=" ")
        while i <= high and arr[i] <= pivot:
            i = i+1
        print(f"to {i}")
        print(f"Upper index moved from : {j}", end=" ")
        while j >= low and arr[j] > pivot:
            j = j-1
        print(f"to {j}")
        if(i < j):
            print(f"Swap lower element {arr[i]} and upper element {arr[j]}")
            arr[i], arr[j] = arr[j], arr[i]
            print("After swapping : ")
            print_array(arr, low, high)
    print(f"Swap upper element {arr[j]} and pivot {pivot}")
    arr[j], arr[low] = arr[low], arr[j]
    print("After swapping : ")
    print_array(arr, low, high)
    return j


def quickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
        pivot_ind = partition(arr, low, high)
        quickSort(arr, low, pivot_ind-1)
        quickSort(arr, pivot_ind+1, high)


arr = list(map(int, input("Enter array : ").split()))
n = len(arr)
quickSort(arr, 0, n-1)
print("Sorted array is:")
for i in range(n):
    print(arr[i], end=" ")
