#include <stdio.h>
#include <string.h>

int main()
{
    float amount;
    float Kenyan, Euro, Dollar, Tanzanian, Ugandan, Rwandan, Canadian, UAE;
    int choice;

    printf("Options available for selection: \n");
    printf("\nEnter 1: Euro \n");
    printf("\nEnter 2: Dollar  \n");
    printf("\nEnter 3: Tanzanian   \n");
    printf("\nEnter 4: Rwandan franc   \n");
    printf("\nEnter 5: Uganda shilling   \n");
    printf("\nEnter 6: Canadian dollar   \n");
    printf("\nEnter 7: United Arab Emirates \n\n ");

    printf("\nEnter your desired currency: \t");
    scanf("%d", &choice);

    printf("\nEnter the amount you wish to convert: ");
    scanf("%f", &amount);

    switch (choice)
     {
     case 1://euro conversion
         Kenyan = amount;
        printf("\nEuro value of %f in Kenyan shillings  is %f \n", Kenyan, (Kenyan * 166.29 ));
        break;
     case 2:
         Kenyan = amount;
        printf("\nDollar value of %f in Kenyan shillings is %f \n", Kenyan, (Kenyan * 152.35 ));
        break;
     case 3:
        Kenyan = amount;
        printf("\nTanzanian value of %f in Kenyan shillings is %f \n", Kenyan, (Kenyan * 0.061));
        break;
     case 4:
       Kenyan = amount;
        printf("\nRwandan franc  value of %f in Kenyan shillings is %f \n", Kenyan, (Kenyan * 0.12));
        break;
     case 5:
        printf("\nUganda shilling  value of %f in Kenyan shillings is %f \n", Kenyan, (Kenyan * 0.040));
        break;
     case 6:
         Kenyan = amount;
        printf("\nCanadian dollar value of %f in Kenyan shillings is %f \n", Kenyan, (Kenyan * 111.21 ));
        break;
     case 7:
        Kenyan = amount;
        printf("\nUnited Arab Emirates Dirham of %f in Kenyan is %f \n", Kenyan, (Kenyan * 41.51 ));
        break;
     default:
        printf("\nPlease enter a valid value: \n");
        break;
     }
    return 0;
     }


