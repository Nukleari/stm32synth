#ifndef SYNTH_H_
#define SYNTH_H_

class Synth{
	private:
	uint32_t notes[129] = {
				818,
				866,
				918,
				972,
				103,
				1091,
				1156,
				1225,
				1298,
				1375,
				1457,
				1543,
				1635,
				1732,
				1835,
				1945,
				2060,
				2183,
				2312,
				2450,
				2596,
				2750,
				2914,
				3087,
				3270,
				3465,
				3671,
				3889,
				4120,
				4365,
				4625,
				4900,
				5191,
				5500,
				5827,
				6174,
				6541,
				6930,
				7342,
				7778,
				8241,
				8731,
				9250,
				9800,
				10383,
				11000,
				11654,
				12347,
				13081,
				13859,
				14683,
				15556,
				16481,
				17461,
				18500,
				19600,
				20765,
				22000,
				23308,
				24694,
				26163,
				27718,
				29366,
				31113,
				32963,
				34923,
				36999,
				39200,
				41530,
				44000,
				46616,
				49388,
				52325,
				55437,
				58733,
				62225,
				65926,
				69846,
				73999,
				78399,
				83061,
				88000,
				93233,
				98777,
				104650,
				110873,
				117466,
				124451,
				131851,
				139691,
				147998,
				156798,
				166122,
				176000,
				186466,
				197553,
				209300,
				221746,
				234932,
				248902,
				263702,
				279383,
				295996,
				313596,
				332244,
				352000,
				372931,
				395107,
				418601,
				443492,
				469864,
				497803,
				527404,
				558765,
				591991,
				627193,
				664488,
				704000,
				745862,
				790213,
				837202,
				886984,
				939727,
				995606,
				1054808,
				1117530,
				1183982,
				1254385,
				1328975
	};
		uint32_t num_of_samples = 100000/440;
		uint32_t wave_table[10000];
		uint8_t wave_type = 0;
		int8_t pitch = 0;
		DAC_HandleTypeDef *hdac;
		uint32_t Channel;
		double v_ref = 3.3;
		double v_peak_to_peak = 2.0;
		void generate_sin();
		void generate_triangle();
		void generate_square();
		void generate_saw();
	public:
		Synth(DAC_HandleTypeDef *hdac, uint32_t Channel, TIM_HandleTypeDef *htim);
		void update(uint8_t note);
		void config(uint8_t note);

};

#endif
