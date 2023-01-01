# merge sort

def merge_sort(arr, p, r):
    if p < r:
        q = p + (r - p) // 2
        merge_sort(arr, p, q)
        merge_sort(arr, q + 1, r)
        merge(arr, p, q, r)

def merge(arr, p, q, r):
    tmp = []
    i = p
    j = q + 1
    while i <= q and j <= r:
        if arr[i] <= arr[j]:
            tmp.append(arr[i])
            i += 1
        else:
            tmp.append(arr[j])
            j += 1
    while i <= q:
        tmp.append(arr[i])
        i += 1
    while j <= r:
        tmp.append(arr[j])
        j += 1

    for i in range(len(tmp)):
        arr[p + i] = tmp[i]


if __name__ == '__main__':
    arr = [1, 3, 5, 7, 2, 4, 6, 8]
    print(arr)
    merge_sort(arr, 0, len(arr) - 1)
    print(arr)