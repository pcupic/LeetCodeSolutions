// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand10() {
    int firstNum = rand7();
    int secondNum = rand7();
    while(firstNum >= 6) 
        firstNum = rand7();
    while(secondNum == 7)
        secondNum = rand7();
    return (secondNum < 4) ? firstNum : firstNum + 5;
}
