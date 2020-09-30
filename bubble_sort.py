def bubbleSort(arr):
    # TC = O(n^2)
    for i in range(len(arr)):
        for j in range(0,len(arr)-i-1):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    return arr

l=[9,12,1,4,8]
print(len(l))
print(bubbleSort(l))