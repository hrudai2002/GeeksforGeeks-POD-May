void reArrange(int arr[], int N) {
       int i = 0, j = N - 1;
       while(i < N && i < j) {
           if(arr[i] & 1) {
               i++;
           }
           else {
               swap(arr[i], arr[j]);
               j--;
           }
       }
       i = 0, j = 0;
       while(j < N && (arr[j] & 1))
         j++;
       while(j < N) {
           swap(arr[i], arr[j]);
           i += 2, j++;
       }
    }
