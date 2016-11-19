#include<stdio.h>
#include<math.h>
#include<string.h>

void convert_to_binary(void);
void convert_to_decimal(void);
void hexadecimal(void);
void into_hexadecimal(void);
void from_hexadecimal(void);
void into_hexa_fromdec(int decimal_number);
void into_hexa_frombin(int binary_number);
int hexadecimal_todec(char* hex);
char* hexadecimal_tobin(int final);


int main ( int argc ,char* argv[])
{

  if(argc != 2)
  {

      printf("Go again and press (b)to enter a binary number or press (d)to enter a decimal number or press(h)to do things in hexadecimal");

      return 1;
  }

  else
  {

      char* given = argv[1];

    if( strcmp(given , "b") == 0)
    {
      convert_to_decimal();
    }

    else if ( strcmp(given , "d") == 0)
    {
      convert_to_binary();
    }

    else if( strcmp(given , "h") == 0)
    {
      hexadecimal();
    }

    return 0;
  }

}

 void convert_to_decimal()
 {
   int input;
   int count = 0;
   int to_decimal = 0;
   printf("Enter a binary number:");
   scanf("%d", &input);

   while(input > 0)
   {

     int remainder = input%10;

     if (remainder != 1 && remainder != 0)
     {

         printf("Invalid Input !!!!\n");
         break;
     }


     else if (remainder == 1 || remainder == 0)
     {

       to_decimal = to_decimal + ( remainder * pow(2,count) );
     }

      count++;
      input = input/10;
   }

   printf("Decimal conversion of given binary number is: %d\n", to_decimal);
 }

 void convert_to_binary()
 {
   int input;
   int i;
   int count = 0;
   int initial[100];

  printf("Enter a decimal number:");
  scanf("%d", &input);

  while( input != 0)
  {

    initial[count] = input % 2;
    count++;
    input = input/2;
  }

  printf("Binary conversion of given decimal number is:");

   for ( i = count-1 ; i >= 0 ; i--)
  {
    printf("%d",initial[i]);
  }
  printf("\n");
}

void hexadecimal(void)
{

  char entry;

  printf("Welcome to hexadecimal :)\n");
  printf("To convert into hexadecimal press(i) and to convert from hexadecimal press(f)\n");

  scanf("%c",&entry);
  //entry = 'i';

  if( entry == 'i')
  {
    into_hexadecimal();
  }

  else if (entry == 'f')
  {
    from_hexadecimal();
  }

  else
  {

    printf("Error");
  }

}

void into_hexadecimal(void)
{
  int num;
  char press;

  printf("Press(b) to enter a binary number or press (d) to enter a decimal number:");
  scanf("%c",&press);


  if( press == 'd')
  {
    printf("Enter decimal number:");
    scanf("%d",&num);

    into_hexa_fromdec(num);
  }
  else if(press =='b')
  {
    printf("Enter a binary number:");
    scanf("%d", &num);

   into_hexa_frombin(num);
  }
}

void into_hexa_fromdec(int decimal_number)
{

  int initial[100];
  int count = 0;
  int i;

    while( decimal_number > 0)
    {

        initial[count] = decimal_number % 16;

        decimal_number = decimal_number / 16;
        count++;
    }

    printf("0x");

    for(i = count-1 ; i >= 0 ; i--)
    {
      if(initial[count] < 10)
      {
        printf("%d",initial[count]);
      }

      else if(initial[count] >= 10)
      {

        if(initial[count] == 10)
        {
          printf("A");
        }
        else if(initial[count] == 11)
        {
          printf("B");
        }
        else if(initial[count] == 12)
        {
          printf("C");
        }
        else if(initial[count] == 13)
        {
          printf("D");
        }
        else if(initial[count] == 14)
        {
          printf("E");
        }
        else if(initial[count] == 15)
        {
          printf("F");
        }

      }
    }

  }
  void into_hexa_frombin(int binary_number)
  {

    int count = 0;
    int to_decimal = 0;

    while(binary_number > 0)
    {

      int remainder = binary_number%10;

      if (remainder != 1 && remainder != 0)
      {

          printf("Invalid Input !!!!\n");
          break;
      }

      else if (remainder == 1 || remainder == 0)
      {

        to_decimal = to_decimal + ( remainder * pow(2,count) );
      }

       count++;
       binary_number = binary_number/10;
    }

     into_hexa_fromdec(to_decimal);

  }


void from_hexadecimal(void)
{

  char info;
  char hexa[100];
  int decimal;
  //int binary;
  //int n,val;

  printf("Press (d) to convert in decimal or press (b) to convert in binary\n");
  scanf("%c",&info);


  if ( info == 'd')
  {

    printf("Enter a hexadecimal number:");
    scanf("%s",hexa);

    decimal = hexadecimal_todec(hexa);

    printf("Decimal number is:%d",decimal);
  }

  else if( info == 'b')
  {
    char* hexadecimal_tobin(int);
  }

}

  int hexadecimal_todec(char hex[100])
  {

  int length = strlen(hex);
  int n;
  int dec_num = 0;
  int val;

  for( n = (length-1) ; n >= 0 ; n-- )
  {
    switch(hex[n])
     {
       case 0: val = 0;
       break;

       case 1: val = 1;
       break;

       case 2: val = 2;
       break;

       case 3: val = 3;
       break;

       case 4: val = 4;
       break;

       case 5: val = 5;
       break;

       case 6: val = 6;
       break;

       case 7: val = 7;
       break;

       case 8: val = 8;
       break;

       case 9: val = 9;
       break;

       case 'a':
       case 'A': val = 10;
       break;

       case 'b':
       case 'B': val = 11;
       break;

       case 'c':
       case 'C': val = 12;
       break;

       case 'd':
       case 'D': val = 13;
       break;

       case 'e':
       case 'E': val = 14;
       break;

       case 'f':
       case 'F': val = 15;
       break;

     }

     dec_num += val * pow(16,n);

 }

 return dec_num;

}


char* hexadecimal_tobin(int final)
{

  //int final;
  int i;
  int count = 0;
  int initial[100];
  char new[100];

  printf("enter a hexadecimal number:");
  scanf("%s",new);

 final = hexadecimal_todec(new);

 while(1)
 {

   initial[count] = final % 2;
   count++;
   final = final/2;
 }

 printf("Binary conversion of given decimal number is:");

  for ( i = count-1 ; i >= 0 ; i--)
 {

   printf("%d",initial[i]);
 }


}
