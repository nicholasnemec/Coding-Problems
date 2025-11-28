int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(int), compare);
    qsort(heaters, heatersSize, sizeof(int), compare);
    
    int radius = 0;
    int j = 0;
    
    for (int i = 0; i < housesSize; i++) {
        int left = 0, right = heatersSize - 1;
        // binary search
		while (left < right) {
            int mid = left + (right - left) / 2;
            if (heaters[mid] < houses[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int dist = abs(heaters[left] - houses[i]);
        if (left > 0) {
            int dist2 = abs(heaters[left - 1] - houses[i]);
            if (dist2 < dist) {
                dist = dist2;
            }
        }
        
        if (dist > radius) {
            radius = dist;
        }
    }
    
    return radius;
}