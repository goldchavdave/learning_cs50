#include <stdio.h>
#include <cs50.h>

//get the users card number
//determine what type of card it is
//if the numbers are recognized as a card
//check if its valid by performing the Luhn's algorithm
//if the card is valid, print the card type

// int card_type(long type)
// {
//     //this function determins whether the num entered belongs to a VISA, MASTERCARD, AMEX
//     //**however, it can only be a card if the end result is a number that ends with a zero
//     //AMEX and MASTERCARD looking at the two first digits
//     //if the first two digits are 34 or 37, it is a AMEX and has 15 digits
//     //if the first two digits are 51,52,53, or 54, it is a MASTERCARD and had 16 digits
//     //if the first digit is a 4, it is a visa and has 13-16 digits
//     //else: printf("foo"\n);

// }

int get_length(long num)
{
    int length =0;

    do
    {
        length++;
        int last = num % 10;
        num = (num - last)/10 ;
    }
    while(num>0);
    return length;

}

int first_two(long num, int thresh)
{
    printf("length %i\n", get_length(num));
    for(int i=0; i<20; i++)
    {
        if(num<thresh)
        {
            break;
        }
        else
        {
            int lastNum = num %10;
            num = (num-lastNum)/10;
        }
    }
    printf("%li\n", num);
    return num;
}

int all_sum(int num)
{
    int sum = 0;
    do
    {
        int lastNum = num %10;
        num = (num-lastNum)/10;
        sum +=lastNum;
    }
    while(num>0);
    return sum;
}

int every_other_sum(long num, bool choice)
{
    bool on = choice;
    int sum = 0;


    do
    {
        int lastNum = num %10;
        num = (num-lastNum)/10;

        if(on)
        {
            if(num%2==0)
            {
                if(!choice)
                {
                    sum += all_sum(lastNum*2);
                }
                else
                {
                    sum += lastNum;
                }
            }
            else
            {
                 if(choice)
                {
                    sum += all_sum(lastNum*2);
                }
                else
                {
                    sum += lastNum;
                }
            }
            on = false;
        }
        else
        {
            on = true;
        }
    }
    while(num>0);


    return sum;
}

bool valid(long cardNum)
{
    int total = every_other_sum(cardNum,true) + every_other_sum(cardNum,false);
    return total%10==0;
}


int main(void)
{
    long credit = get_long("please enter your credit card number: ");

    int someVar = first_two(credit,100);
    printf("first (1 or 2) digits %i\n", someVar);

    bool val = valid(credit);
    printf(val ? "true" : "false");
}

//even num will be if %2 = 0

// int mult_two(long card)
// {
//     //this function needs to select every other digit in the card (starting with the second to last) and *2 and get the products
//     //a for loop which runs the according to the amount of digits in the card
//     //everytime it runs it selects every other digit, starting from the end. (the first (rly the last) is skipped).
//     //it then * the digit by 2 (we will do smt with the digits of the product)
//     //all the digits of the products must then be added up
//     //store the sum in var = sum_two
// }

// int non_mult(long other)
// {
//     //function which adds up all the digits from the credit which were not multiplied by two
//     //for loop that runs according to the amount od digitsn of the card
//     //selects everyother digit, starting from the last num (select that one first)
//     //-> take that digit and add it to the next digit selected to get the final sum
//     //store sum in var = non_mult
// }

// int total(int product, int sum)
// {
//     //get the sum of sum_two + non_mult
//     //return int sum (if thats the total)
// }

// int valid(int final)
// {
//     //function which uses the modulo -> dividing the total() by 10
//     //if (modulo == 0)
//     //  the card is valid
//     //else: the card in invalid
// }
