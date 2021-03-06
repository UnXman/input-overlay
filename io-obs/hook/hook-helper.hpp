#ifndef HOOK_HELPER_HPP
#define HOOK_HELPER_HPP

#include <uiohook.h>
#include "../util/util.hpp"

#ifdef LINUX
#include <stdint.h>
#endif

#ifdef WINDOWS
#include <windows.h>
#endif

/**
 * This file is part of input-overlay
 * which is licensed under the MIT license.
 * See LICENSE or mozilla.org/en-US/MPL/2.0/
 * github.com/univrsal/input-overlay
 */

class ElementDataHolder;

namespace Hook {

	extern ElementDataHolder * input_data;

	extern wint_t last_character;
	extern int16_t mouse_x, mouse_y, mouse_x_smooth, mouse_y_smooth, mouse_last_x, mouse_last_y;
	extern bool hook_initialized;


#ifdef WINDOWS
	DWORD WINAPI hook_thread_proc(LPVOID arg);
#else
	void *hook_thread_proc(void *arg);
#endif

	void dispatch_proc(uiohook_event * const event);

	bool logger_proc(unsigned int level, const char *format, ...);

	void start_hook(void);

	void end_hook(void);

	int hook_enable(void);

	void proccess_event(uiohook_event * const event);

};

#endif // HOOK_HELPER_HPP
