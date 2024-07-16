int maximumGroups(int* grades, int gradesSize){

    int n = gradesSize;
    int groups = 0;
    int sum = 0;

    while (sum + (groups + 1) <= n) {
        groups++;
        sum += groups;
    }

    return groups;
}
