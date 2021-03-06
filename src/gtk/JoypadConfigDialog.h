// -*- C++ -*-
// VisualBoyAdvance - Nintendo Gameboy/GameboyAdvance (TM) emulator.
// Copyright (C) 1999-2003 Forgotten
// Copyright (C) 2004 Forgotten and the VBA development team

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or(at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef __VBA_JOYPADCONFIG_H__
#define __VBA_JOYPADCONFIG_H__

#include <vector>

#include <gtkmm.h>

#include "InputSDL.h"

namespace VBA
{

class JoypadConfigDialog : public Gtk::Dialog
{
public:
	JoypadConfigDialog(GtkDialog* _pstDialog, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	virtual ~JoypadConfigDialog();

protected:
	bool bOnEntryFocusIn(GdkEventFocus * _pstEvent, guint _uiEntry);
	bool bOnEntryFocusOut(GdkEventFocus * _pstEvent);

	void vOnInputEvent(const SDL_Event &event);
	bool on_key_press_event(GdkEventKey * _pstEvent);

private:
	struct SJoypadKey
	{
		const EKey   m_eKeyFlag;
		const char * m_csEntryName;
	};

	Gtk::Button *             m_poCloseButton;
	std::vector<Gtk::Entry *> m_oEntries;
	gint                      m_iCurrentEntry;
	bool                      m_bUpdating;
	static const SJoypadKey   m_astKeys[];
	sigc::connection          m_oConfigSig;
	SDL_Event                 m_oPreviousEvent;

	bool bOnConfigIdle();
	void vUpdateEntries();
	void vEmptyEventQueue();
};

} // namespace VBA


#endif // __VBA_JOYPADCONFIG_H__
