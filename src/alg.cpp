// Copyright 2021 NNTU-CS

int cbinsearch_Helper_left(int* arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int mid = (left + right) / 2;
  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] == value && mid == 0) return 0;
    if ((arr[mid] == value && arr[mid - 1] != value)) return mid;
    if (value > arr[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int cbinsearch_Helper_right(int* arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  if (arr[right] == value) return right;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == value && mid == 0) return 0;
    if ((arr[mid] == value && arr[mid + 1] != value)) return mid;
    if (value < arr[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int cbinsearch(int* arr, int size, int value) {
  if (cbinsearch_Helper_left(arr, size, value) == -1) {
    return 0;
  }
  if (arr[cbinsearch_Helper_left(arr, size, value)] == \
      arr[cbinsearch_Helper_right(arr, size, value)]) {
    return (cbinsearch_Helper_right(arr, size, value) - \
            cbinsearch_Helper_left(arr, size, value)) + 1;
  }
  return 0;
}
