/* Name :phoneData.h ver 1.0
 * Content : declaration and definition to struct phoneData
 * Implementaion : CHOI WOOSUK
 *
 * Last modified : 20180/07/06
 */

#ifndef PHONEDATA_H_INCLUDED
#define PHONEDATA_H_INCLUDED

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct _phoneData{

    char name[NAME_LEN];
    char phoneNum[PHONE_LEN];

}phoneData;


#endif // PHONEDATA_H_INCLUDED
