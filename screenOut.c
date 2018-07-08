/* Name : scrrenOut.c ver 1.0
 * Content : Definition for consol output_iterator_tag
 * Imlementation : CHOI WOOSUK
 *
 * Last modified 2018/07/06
 */

 #include "common.h"
 #include "phoneData.h"

 /* function declaration : void ShowMenu(void)
  * function definition : for choice to output menu
  *
  */

void ShowMenu(){
    system("cls");

    printf("--------------------Menu--------------------\n");
    printf(" 1. Input Phone Number \n");
    printf(" 2. Print whole information \n");
    printf(" 3. Search Phone Number \n");
    printf(" 4. Delete Phone Number \n");
    printf(" 5. Change Phone Number \n");
    printf(" 6. Quit \n");
    printf("--------------------------------------------\n\n");
    printf("Select>>");
}

void ShowPhoneInfo(phoneData phone){

    printf("-----------------------------\n");
    printf("---> Name : %s \n",phone.name);
    printf("---> Phone Number : %s \n",phone.phoneNum);
    printf("-----------------------------\n\n");
}

void ShowPhoneInfoByPtr(phoneData* pPhone){
    printf("-----------------------------\n");
    printf("---> Name : %s \n",pPhone->name);
    printf("---> Phone Number : %s \n",pPhone->phoneNum);
    printf("-----------------------------\n\n");
}
