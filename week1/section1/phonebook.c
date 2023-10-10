#include <stdio.h>
#include <cs50.h>

int main(void){
    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string phoneNumber = get_string("Phone number: ");

    printf("%s\n%i\n%s\n", name, age, phoneNumber);

}