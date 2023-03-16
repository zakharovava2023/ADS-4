// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int result = 0, left = 0, right = size - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (value > arr[middle])
            left = middle + 1;
        if (value < arr[middle])
            right = middle - 1;
        if (value == arr[middle]) {
            int mid_left = middle - 1;
            int mid_right = middle + 1;
            result = 1;
            while ((mid_left >= 0) && (value == arr[mid_left])) {
                result++;
                mid_left--;
            }
            while ((mid_right < size) && (value == arr[mid_right])) {
                result++;
                mid_right++;
            }
            return result;
        }
    }
    return 0;
}

int countPairs1(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((*(arr + i) + *(arr + j)) == value) result++;
        }
    }
    return result;
}
int countPairs2(int *arr, int len, int value) {
    int result = 0;
    int right = len - 1;
    while (*(arr + right) > value) right--;
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if ((*(arr + i) + *(arr + j)) == value) {
                result++;
            }
        }
    }
    return result;
}
int countPairs3(int *arr, int len, int value) {
    int result = 0;
    int pair = 0;
    for (int i = 0; i < len; i++) {
        pair = value - (*(arr + i));
        result += cbinsearch(arr, len, pair);
        if (pair == value / 2) result--;
    }
    return result / 2;
}
