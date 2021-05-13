#ifndef keypad_H_
#define keypad_H_

class Keypad{
	private:
		uint8_t note = 0;
		uint8_t prev_note = 0;
		bool note_changed = false;
	public:
		Keypad();
		bool update();
		bool NoteChanged();
		uint8_t get_note();
};

#endif
