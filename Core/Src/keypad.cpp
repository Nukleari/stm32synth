#include "main.h"
#include "keypad.hpp"

Keypad::Keypad(){
}
bool Keypad::update(){
note = 0;
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10)) note = 52;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12)) note = 53;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14)) note = 54;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15)) note = 55;
if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) note = 56;
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10)) note = 57;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12)) note = 58;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14)) note = 59;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15)) note = 60;
if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) note = 61;
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10)) note = 62;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12)) note = 63;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14)) note = 64;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15)) note = 65;
if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) note = 66;
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET);
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10)) note = 67;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12)) note = 68;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14)) note = 69;
if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15)) note = 70;
if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) note = 71;
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET);

note_changed = (note != prev_note);

prev_note = note;
return note_changed;
}
bool Keypad::NoteChanged(){
return note_changed;
}
uint8_t Keypad::get_note(){
return note;
}
