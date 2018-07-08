/* Name : phoneFunc.h ver 1.0
 * Content : Control function declaration for Phone Number
 * Implementation : CHOI WOOSUK
 *
 * Last modified : 2018/07/06
 */
#ifndef PHONEFUNC_H_INCLUDED
#define PHONEFUNC_H_INCLUDED

#include "phoneData.h"

void InputPhoneData();
void ShowAllData();
void SearchPhoneData();
void DeletePhoneData();
void StoreDataToFile();
void LoadDataFromFile();
void ChangePhoneData();
void StoreDataToFileInStruct();
void LoadDataFromFileInStruct();
#endif // PHONEFUNC_H_INCLUDED
