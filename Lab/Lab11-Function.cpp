/*
    จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
    
    หมายเหตุ: ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
    153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
    370 = 3^3 + 7^3 + 0^3

    Test Case:
        Enter Number:
            153
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            370
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            372
    Output:
        Not Pass.
*/

#include <stdio.h>
#include <math.h>

int calculatePower(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int isArmstrongNumber(int number) {
    int originalNumber = number;
    int numberOfDigits = 0;
    int sum = 0;

    while (originalNumber != 0) {
        originalNumber /= 10;
        ++numberOfDigits;
    }

    originalNumber = number;

    while (originalNumber != 0) {
        int digit = originalNumber % 10;
        sum += calculatePower(digit, numberOfDigits);
        originalNumber /= 10;
    }

    return sum == number;
}

int main() {
    int number;

    printf("Enter Number: ");
    scanf("%d", &number);

    if (isArmstrongNumber(number)) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }

    return 0;
}