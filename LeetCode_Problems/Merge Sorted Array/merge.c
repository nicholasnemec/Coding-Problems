void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int ct = n;
    for(int i = 0; i < n; i++){
        *(nums1 + (m + i)) = *(nums2 + i);
    }
    while(ct > 0){
        for(int i = (m + n - 1); i > 0; i--){
            if(*(nums1 + i) < *(nums1 + i - 1)){
                int temp;
                temp = *(nums1 + i - 1);
                *(nums1 + i - 1) = *(nums1 + i);
                *(nums1 + i) = temp;
            }
        }
        ct--;
    }
}