#include "math.h"
#include "main.h"
#include "synth.hpp"

Synth::Synth(DAC_HandleTypeDef *hdac, uint32_t Channel, TIM_HandleTypeDef *htim){
	HAL_TIM_Base_Start(htim);
	this->hdac = hdac;
	this->Channel = Channel;
}

void Synth::update(uint8_t note){
	if(note != 0){
		num_of_samples = (10000000/notes[(note+pitch)]);

		if(wave_type == 0) generate_sin();
		if(wave_type == 1) generate_triangle();
		if(wave_type == 2) generate_square();
		if(wave_type == 3) generate_saw();

		for(uint32_t i=0; i<num_of_samples; i++){
			wave_table[i] = wave_table[i] * v_peak_to_peak / v_ref;
		}

		HAL_DAC_Stop_DMA(hdac, Channel);
		HAL_DAC_Start_DMA(hdac, Channel, wave_table, num_of_samples, DAC_ALIGN_12B_R);
	}else HAL_DAC_Stop_DMA(hdac, Channel);
}

void Synth::config(uint8_t note){
	if(note != 0){
		//wawe select
		if(note == 71){
			wave_type = 0;
			update(69);
		}
		if(note == 70){
			wave_type = 1;
			update(69);
		}
		if(note == 69){
			wave_type = 2;
			update(69);
		}
		if(note == 68){
			wave_type = 3;
			update(69);
		}
		//pitch select
		if(note == 66){
			pitch = -24;
			update(69);
		}
		if(note == 65){
			pitch = -12;
			update(69);
		}
		if(note == 64){
			pitch = 0;
			update(69);
		}
		if(note == 63){
			pitch = 12;
			update(69);
		}

	}else update(0);
}

void Synth::generate_sin()
{
	for(uint32_t i=0; i<num_of_samples; i++){
		wave_table[i] = (4095 * (sin(i*2*M_PI/num_of_samples) + 1) / 2);
	}
}

void Synth::generate_triangle()
{
	for(uint32_t i=0; i<num_of_samples; i++){
		if(i <= num_of_samples/2) wave_table[i] = (4095 * 2 * i / num_of_samples);
		else wave_table[i] = (4095-(4095 * 2 * i / num_of_samples));
	}
}

void Synth::generate_square()
{
	for(uint32_t i=0; i<num_of_samples; i++){
		if(i <= num_of_samples/2) wave_table[i] = 0;
		else wave_table[i] = 4095 / 1.6;
	}
}

void Synth::generate_saw()
{
	for(uint32_t i=0; i<num_of_samples; i++){
		wave_table[i] = (4095 * i / num_of_samples);
	}
}
