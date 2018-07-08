/* Name : main.c ver 1.0
 * Content : main function
 * Implementation : CWS
 *
 * Last modified 2018/07/04
 */
#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT=1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT};

/* Function : int main()
 * Functions : processing user selection.
 * return : 0 at normal end
 */
int main()
{
    int inputNum = 0;

    //LoadDataFromFile();
    LoadDataFromFileInStruct();

    while(1){
        ShowMenu();
        fputs("Select Menu : ", stdout);
        scanf("%d",&inputNum);
        fflush(stdin);

        switch(inputNum){
        case INPUT:
            InputPhoneData();
            break;
        case SHOWALL:
            ShowAllData();
            break;
        case SEARCH:
            SearchPhoneData();
            break;
        case DELETE:
            DeletePhoneData();
            break;
        case CHANGE:
            ChangePhoneData();
            break;
        }

        if(inputNum == QUIT){
            //StoreDataToFile();
            StoreDataToFileInStruct();
            puts("Thank you for using it.");
            break;
        }

    }

    return 0;
}

/*end of file */
