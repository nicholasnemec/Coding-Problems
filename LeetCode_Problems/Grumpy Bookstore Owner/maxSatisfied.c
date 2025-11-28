int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int baseSatisfaction = 0;
    int extraSatisfaction = 0;
    int maxExtraSatisfaction = 0;
    for(int i = 0; i < customersSize; i++){
        if(grumpy[i] == 0){
            baseSatisfaction += customers[i];
        }
    }
    // first window [x, y, ..., z] with a width of minutes
    for(int i = 0; i < minutes; i++){
        if(grumpy[i] == 1){
            extraSatisfaction += customers[i];
        }
    }

    maxExtraSatisfaction = extraSatisfaction;
    for(int i = minutes; i < customersSize; i++){
        if(grumpy[i] == 1){
            extraSatisfaction += customers[i];
        }
        if(grumpy[i - minutes] == 1){
            extraSatisfaction -= customers[i-minutes];
        }
        if(extraSatisfaction > maxExtraSatisfaction){
            maxExtraSatisfaction = extraSatisfaction;
        }
    }
    return maxExtraSatisfaction + baseSatisfaction;
}