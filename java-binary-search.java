class BinarySearch { 

    int binarySearch(int arr[], int left, int right, int x) 
    { 
        if (right >= left) { 
            int mid = left + (right - left) / 2; 
  
            if (arr[mid] == x) 
                return mid; 
  
            if (arr[mid] > x) 
                return binarySearch(arr, left, mid - 1, x); 
  
            return binarySearch(arr, mid + 1, right, x); 
        } 
  
        return -1; 
    } 
  
    public static void main(String args[]) 
    { 
        int arr[] = {1, 2, 3, 4, 10, 40, 80}; 
        int n = arr.length; 
        int x = 40; 
        int result = binarySearch(arr, 0, n - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at index " + result); 
    } 
} 
