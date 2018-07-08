/* Name : phoneFunc.c ver 1.0
 * Content : Funtion which control phone number
 * Implementation : CHOI WOOSUK
 *
 * Last modified 2018/07/16
 */

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
 //phoneData phoneList[List_NUM];
phoneData* phoneList[LIST_NUM];

 /* function : void InputPhoneData(void)
  * operation : Inputed and save phone number related data
  * return value : void
  *
  */

void InputPhoneData(void){

    int i;
    //phoneData phone;
    phoneData* pPhone;

    pPhone = (phoneData*)malloc(sizeof(phoneData));

    if(numOfData >= LIST_NUM){
         puts("array is fully.");
         return;
    }
    fputs("Input name : ",stdout);
    gets(pPhone->name);
    fputs("Input phone number : ",stdout);
    gets(pPhone->phoneNum);

    for(i=0;i<numOfData;i++){
        if(!strcmp(phoneList[i]->name, pPhone->name)
           && !strcmp(phoneList[i]->phoneNum, pPhone->phoneNum)){
            puts("This data already inputed.");
            free(pPhone); // delete most important.
            getchar();
            return;
        }
    }

    phoneList[numOfData] = pPhone;
    numOfData++;
    StoreDataToFileInStruct();
    puts("Input is comleted.");
    getchar();
}

/* function : void ShowAllData(void)
 * operation : Whole stored data print
 * return value : void
 *
 */
void ShowAllData(){
    int i;

    for(i=0;i<numOfData;i++){
        //ShowPhoneInfo(phoneList[i]);
        ShowPhoneInfoByPtr(phoneList[i]);
    }

    puts("Print is completed.");
    getchar();
}

void SearchPhoneData(){

    int i;
    char name[100];
    int searchSte = 0;

    puts("What is your searching name? ");
    gets(name);

    for(i=0;i<numOfData;i++){
        if(!strcmp(phoneList[i]->name,name)){
            ShowPhoneInfoByPtr(phoneList[i]);
            //break;
            //getchar();
            //return;
            searchSte = 1;
        }
    }
    if(searchSte == 0)
        puts("No searching data in arrray.");
    else
        puts("Searching data is completed.");
    getchar();

}

void DeletePhoneData(){

    int i; int sel;
    char delname[LIST_NUM];

    //temp array
    int tempIndex[LIST_NUM];
    int matchCount = 0;
    sel = 0;
    int delIdx = 0;

    fputs("What is your deleting(searching) name? ",stdout);
    gets(delname);

    for(i=0;i<numOfData;i++){
        if(!strcmp(delname,phoneList[i]->name)){
            tempIndex[matchCount++] = i;
        }
    }
    if(matchCount == 0){
        puts("No data in array.");
        getchar();
        return;
    }
    else if(matchCount == 1){
        delIdx = tempIndex[0];
    }
    else{
        for(i=0;i<matchCount;i++){
            printf("NUM. %d \n",i+1);
            ShowPhoneInfoByPtr(phoneList[tempIndex[i]]);
        }
        fputs("Select : ",stdout);
        scanf("%d",&sel);
        fflush(stdin);
        delIdx = tempIndex[sel-1];
    }

    free(phoneList[delIdx]);


    for(i=delIdx;i<numOfData-1;i++){
        phoneList[i] = phoneList[i+1];
    }
    numOfData--;
    StoreDataToFileInStruct();
    puts("Deleting is completed.");
    getchar();
}

void StoreDataToFile(){

    int i;
    FILE* fp = fopen("phoneData.dat","w");
    fwrite(&numOfData, sizeof(int),1,fp);

    for(i=0;i<numOfData;i++){
        fprintf(fp,"%s\n%s\n", phoneList[i]->name,phoneList[i]->phoneNum);
        free(phoneList[i]);
    }
    fclose(fp);
}

void LoadDataFromFile(){
    int i, sLen;
    FILE* fp = fopen("phoneData.dat","r");

    if(fp == NULL)
        return;
    fread(&numOfData, sizeof(int), 1, fp);

    for(i=0;i<numOfData;i++){
        phoneList[i] = (phoneData*)malloc(sizeof(phoneData));
        fgets(phoneList[i]->name,NAME_LEN,fp);

        sLen = strlen(phoneList[i]->name);
        phoneList[i]->name[sLen-1] = 0;

        fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);

        sLen = strlen(phoneList[i]->phoneNum);
        phoneList[i]->phoneNum[sLen-1] = 0;

    }
    fclose(fp);
}

void ChangePhoneData(){
    int i; int sel;
    char searchName[NAME_LEN];
    char newPhoneNumber[PHONE_LEN];

    //temp array
    int tempIndex[LIST_NUM];
    int matchCount = 0;
    sel = 0;
    int delIdx = 0;

    fputs("What is your changing(searching) name? ",stdout);
    gets(searchName);

    for(i=0;i<numOfData;i++){
        if(!strcmp(searchName,phoneList[i]->name)){
            tempIndex[matchCount++] = i;
        }
    }
    if(matchCount == 0){
        puts("No data in array.");
        getchar();
        return;
    }
    else if(matchCount == 1){
        delIdx = tempIndex[0];
    }
    else{
        for(i=0;i<matchCount;i++){
            printf("NUM. %d \n",i+1);
            ShowPhoneInfoByPtr(phoneList[tempIndex[i]]);
        }
        fputs("Select : ",stdout);
        scanf("%d",&sel);
        fflush(stdin);

        delIdx = tempIndex[sel-1];
    }

    fputs("What is changing number? ",stdout);
    gets(newPhoneNumber);
    strcpy(phoneList[delIdx]->phoneNum,newPhoneNumber);

    StoreDataToFileInStruct();
    puts("Changing is completed.");
    getchar();
}

void StoreDataToFileInStruct(){
    int i;

    FILE* fp = fopen("phoneDataStruct.dat","wb");

    fwrite(&numOfData,sizeof(int),1,fp);

    for(i=0;i<numOfData;i++){
        fwrite(phoneList[i], sizeof(phoneData),1,fp);
    }
    fclose(fp);
}

void LoadDataFromFileInStruct(){
    int i;

    FILE* fp = fopen("phoneDataStruct.dat","rb");

    if(fp==NULL)
        return;

    fread(&numOfData,sizeof(int),1,fp);

    for(i=0;i<numOfData;i++){
        phoneList[i] = (phoneData*)malloc(sizeof(phoneData));

        fread(phoneList[i],sizeof(phoneData),1,fp);
    }

    fclose(fp);
}
