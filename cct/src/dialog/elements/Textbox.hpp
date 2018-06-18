/**
 * Created by universal on 8.1.17
 * This file is part of reloded which is licensed
 * under the MOZILLA PUBLIC LICENSE 2.0 - mozilla.org/en-US/MPL/2.0/
 * github.com/univrsal/input-overlay
 */


#pragma once

#include "./GuiElement.hpp"
#include "../Dialog.hpp"
#include <string>

#define TEXTBOX_NUMERIC 1 << 0
#define TEXTBOX_HEX 1 << 1

class Dialog;

class GuiElement;

class Textbox : public GuiElement
{
public:
	Textbox(int8_t id, int x, int y, int w, int h, std::string text, Dialog *parent);

	~Textbox();

	void close(void);

	void draw_background(void);

	void draw_foreground(void);

	bool handle_events(SDL_Event * event);

	void set_text(std::string s);

	void append_text(std::string s);

	uint8_t get_cursor(void);

	const std::string * get_text();

	inline bool is_numeric(const std::string& s);

	inline bool is_hex(const std::string& s);

	void set_alert(bool state);

	void set_cutoff(uint8_t c);
private:
	std::string m_text;
	std::string m_composition;
	std::string m_cut_text;
	uint8_t m_cut_off = 38;
	bool m_alert = false;
	bool m_focused;
};